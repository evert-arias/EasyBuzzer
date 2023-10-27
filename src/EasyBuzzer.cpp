/*
Name:		EasyBuzzer.cpp
Version:	1.0.3
Created:	9/29/2017 12:03:48 AM
Updated:	2/19/2019 12:19:00 AM
Author:		Evert Arias
Github:		https://github.com/evert-arias/EasyBuzzer
			Copyright (c) 2019 Evert Arias
*/

#include "EasyBuzzer.h"

/* Class constructor */
EasyBuzzerClass::EasyBuzzerClass()
{
}
/* Class destructor */
EasyBuzzerClass::~EasyBuzzerClass() {}
/* Start beeping continuously at a given frequency. */
void EasyBuzzerClass::beep(unsigned int frequency)
{
	beep(frequency, 1, 0, 1, 0, 0, NULL);
}
/* Beep at a given frequency an specific number of beeps. */
void EasyBuzzerClass::beep(unsigned int frequency, unsigned int beeps)
{
	beep(frequency, mOnDuration, mOffDuration, 1, mPauseDuration, beeps, NULL);
}
/* Beep at a given frequency an specific number of beeps, with callback functionality. */
void EasyBuzzerClass::beep(unsigned int frequency, unsigned int beeps, void (*finishedCallbackFunction)())
{
	beep(frequency, mOnDuration, mOffDuration, 1, mPauseDuration, beeps, finishedCallbackFunction);
}
/* Beep sequence at a given frequency. */
void EasyBuzzerClass::beep(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences)
{
	beep(frequency,onDuration,offDuration,beeps,pauseDuration,sequences,NULL);
}
/* Beep sequence at a given frequency, with callback functionality. */
void EasyBuzzerClass::beep(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)())
{
	mMode = Mode::BEEP;
	mFreq = frequency;
	mOnDuration = onDuration ? max(MINIMUM_INTERVAL, onDuration) : 0;
	mOffDuration = offDuration ? max(MINIMUM_INTERVAL, offDuration) : 0;
	mBeeps = beeps;
	mPauseDuration = pauseDuration ? max(MINIMUM_INTERVAL, pauseDuration) : 0;
	mSequences = sequences;
	mFinishedCallbackFunction = finishedCallbackFunction;
	mStartTime = max(millis(), 1);
	mLastRunTime = 0;
	mTurnedOn = false;
	mTurnedOff = false;
	update();
}
/* Start beeping at a given frequency, for an specific duration. */
void EasyBuzzerClass::singleBeep(unsigned int frequency, unsigned int duration)
{
	beep(frequency, duration, 0, 1, DEFAULT_PAUSE_DURATION, 1, NULL);
}
/* Start beeping at a given frequency, for an specific duration, with callback functionality. */
void EasyBuzzerClass::singleBeep(unsigned int frequency, unsigned int duration, void (*finishedCallbackFunction)())
{
	beep(frequency, duration, 0, 1, DEFAULT_PAUSE_DURATION, 1, finishedCallbackFunction);
}

/** Start siren with the specified mode, the given start and end fequency and the provided delay */
void EasyBuzzerClass::siren(bool riseAndFall, unsigned int startFrequency, unsigned int endFrequency, unsigned int delay)
{
	mMode = Mode::SIREN;
	mSirenRiseAndFall = riseAndFall;
	if(endFrequency > startFrequency)
	{
		mStartFreq = startFrequency;
		mEndFreq = endFrequency;
	}
	else
	{	// Reverse way
		mStartFreq = endFrequency;
		mEndFreq = startFrequency;
		mSirenRise = false;
	}
	mFreq = startFrequency;
	mSirenDelay = delay;
	mStartTime = max(millis(), 1);
	mLastRunTime = 0;
	mTurnedOn = false;
	mTurnedOff = false;
	update();
}

/* Stop beeping. */
void EasyBuzzerClass::stop()
{
	mStartTime = 0;
	noTone(mPin);
}
/* Set the pin where the buzzer is connected. */
void EasyBuzzerClass::setPin(unsigned int pin)
{
	mPin = pin;
}
/* Set On duration. */
void EasyBuzzerClass::setOnDuration(unsigned int duration)
{
	mOnDuration = duration;
}
/* Set Off duration. */
void EasyBuzzerClass::setOffDuration(unsigned int duration)
{
	mOffDuration = duration;
}
/* Set Pause duration. */
void EasyBuzzerClass::setPauseDuration(unsigned int duration)
{
	mPauseDuration = duration;
}

/* Update function that keeps the library running. */
void EasyBuzzerClass::update()
{
	unsigned long currentTime = millis();
	if (currentTime - mLastRunTime < MINIMUM_INTERVAL)
	{
		return;
	}
	mLastRunTime = currentTime;
	if (!mStartTime || !mPin)
	{
		return;
	}

	switch(mMode)
	{
		case Mode::SIREN :
			updateSiren(currentTime);
			break;
		case Mode::BEEP :
		default:
			updateBeep(currentTime);
			break;
	}
}

void EasyBuzzerClass::updateBeep(unsigned long currentTime)
{
	unsigned long elapsedTime = currentTime - mStartTime;
	unsigned int blinkDuration = mOnDuration + mOffDuration;
	unsigned int sequenceDuration = blinkDuration * mBeeps + mPauseDuration - mOffDuration;

	if (!sequenceDuration || (mSequences != 0 && elapsedTime / sequenceDuration >= mSequences))
	{
		mStartTime = 0;
		mTurnedOn = false;
		mTurnedOff = false;
		if (mFinishedCallbackFunction)
		{
			mFinishedCallbackFunction();
		}
		return;
	};

	unsigned int blinkingDuration = blinkDuration * mBeeps;
	unsigned int timeInSequence = elapsedTime % sequenceDuration;

	if (timeInSequence < blinkingDuration && timeInSequence % blinkDuration < mOnDuration)
	{
		if(!mTurnedOn)
		{
			tone(mPin, mFreq);
			mTurnedOn = true;
			mTurnedOff = false;
		}
	}
	else
	{
		if(!mTurnedOff)
		{
		noTone(mPin);
			mTurnedOff = true;
			mTurnedOn = false;
		}
	};
}

void EasyBuzzerClass::updateSiren(unsigned long currentTime)
{
	if(!mTurnedOn)
	{
		tone(mPin, mFreq);
		mTurnedOn = true;
		mLastSirenUpdateTime = currentTime;
	}
	else if(currentTime - mLastSirenUpdateTime >= mSirenDelay)
	{
		if(mSirenRise)
		{
			mFreq+=SIREN_INCREMENT;
			if(mFreq>=mEndFreq)
			{
				if(mSirenRiseAndFall)
				{
					mSirenRise = false;
				}
				else
				{
					mFreq = mStartFreq;
				}
			}
		}
		else
		{
			mFreq-=SIREN_INCREMENT;
			if(mFreq<=mStartFreq)
			{
				if(mSirenRiseAndFall)
				{
					mSirenRise = true;
				}
				else
				{
					mFreq = mEndFreq;
				}
			}
		}
		tone(mPin, mFreq);
		mLastSirenUpdateTime = currentTime;
	}
}

EasyBuzzerClass EasyBuzzer;

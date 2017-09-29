/*
Name:		EasyBuzzer.h
Version:	1.0.0
Created:	9/29/2017 12:03:48 AM
Author:		Evert Arias
Github:		https://github.com/evert-arias/Esp32-Buzzer
			Copyright (c) 2017 Evert Arias
*/

#include "EasyBuzzer.h"

EasyBuzzerClass::EasyBuzzerClass(){
	ledcSetup(mChannel, mFreq, mResolution);
}

EasyBuzzerClass::~EasyBuzzerClass() {}

void EasyBuzzerClass::setPin(int pin) {
	mPin = pin;
}

void EasyBuzzerClass::update() {
	unsigned long currentTime = millis();
	if (currentTime - mLastRunTime < MINIMUM_INTERVAL) {
		return;
	}
	mLastRunTime = currentTime;
	if (!mStartTime || !mPin) {
		return;
	}

	unsigned long elapsedTime = currentTime - mStartTime;
	unsigned int blinkDuration = mOnDuration + mOffDuration;
	unsigned int sequenceDuration = blinkDuration * mBeeps + mPauseDuration - mOffDuration;

	if (!sequenceDuration || (mSequences != 0 && elapsedTime / sequenceDuration >= mSequences)) {
		mStartTime = 0;
		if (mFinishedCallbackFunction) {
			mFinishedCallbackFunction();
		}
		return;
	};

	unsigned int blinkingDuration = blinkDuration * mBeeps;
	unsigned int timeInSequence = elapsedTime % sequenceDuration;
	if (timeInSequence < blinkingDuration && timeInSequence % blinkDuration < mOnDuration) {
		ledcAttachPin(mPin, mChannel);
		ledcWriteTone(mChannel, mFreq);
	}
	else {
		ledcDetachPin(mPin);
	};
}

void EasyBuzzerClass::beepSequence(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences, void(*finishedCallbackFunction)()) {
	mFreq = frequency;
	mOnDuration = onDuration ? max(MINIMUM_INTERVAL, onDuration) : 0;
	mOffDuration = offDuration ? max(MINIMUM_INTERVAL, offDuration) : 0;
	mBeeps = beeps;
	mPauseDuration = pauseDuration ? max(MINIMUM_INTERVAL, pauseDuration) : 0;
	mSequences = sequences;
	mFinishedCallbackFunction = finishedCallbackFunction;
	mStartTime = max(millis(), 1);
	mLastRunTime = 0;
	update();
}

void EasyBuzzerClass::beep(int frequency) {
	beepSequence(frequency, 1, 0, 1, 0, 0, NULL);
}

void EasyBuzzerClass::beep(int frequency, int duration, void(*finishedCallbackFunction)()) {
	beepSequence(frequency, duration, 0, 1, 0, 1, finishedCallbackFunction);
}

void EasyBuzzerClass::stopBeep() {
	ledcDetachPin(mPin);
}

EasyBuzzerClass EasyBuzzer;

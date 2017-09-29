/*
Name:		EasyBuzzer.h
Version:	1.0.0
Created:	9/29/2017 12:03:48 AM
Author:		Evert Arias
Github:		https://github.com/evert-arias/EasyBuzzer
Copyright (c) 2017 Evert Arias
*/

#ifndef _EasyBuzzer_h
#define _EasyBuzzer_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

class EasyBuzzerClass
{
public:
	EasyBuzzerClass();
	~EasyBuzzerClass();
	/* Set the pin where the buzzer is connected. */
	void setPin(int pin);
	/* Update function that keeps the library running. */
	void update();
	/* Beep continuously at a given frequency. */
	void beep(unsigned int frequency);
	/* Beep once at a given frequency. */
	void beep(unsigned int frequency, unsigned int duration);
	/* Beep at given frequency, for duration time, with callback functionality. */
	void beep(unsigned int frequency, unsigned int duration, void(*finishedCallbackFunction)());
	/* Beep sequence at a given frequency, with callback functionality. */
	void beepSequence(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences, void(*finishedCallbackFunction)());
	/* Stop beeping. */
	void stopBeep();
private:
	unsigned int mPin = DEFAULT_PIN;
	unsigned int mFreq = DEFAULT_FREQ;
	unsigned int mChannel = DEFAULT_CHANNEL;
	unsigned int mResolution = DEFAULT_RESOLUTION;
	byte mBeeps;
	unsigned int mOnDuration;
	unsigned int mOffDuration;
	unsigned int mPauseDuration;
	unsigned int mSequences;
	unsigned long mStartTime;
	unsigned long mLastRunTime;
	void(*mFinishedCallbackFunction)();
}; extern EasyBuzzerClass EasyBuzzer;

#endif


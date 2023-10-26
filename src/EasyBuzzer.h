/*
Name:		EasyBuzzer.h
Version:	1.0.3
Created:	9/29/2017 12:03:48 AM
Updated:	2/19/2019 12:19:00 AM
Author:		Evert Arias
Github:		https://github.com/evert-arias/EasyBuzzer
			Copyright (c) 2019 Evert Arias
*/

#ifndef _EasyBuzzer_h
#define _EasyBuzzer_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"

#ifdef ESP8266
#define min _min
#define max _max
#endif
#ifdef ESP32
#define min _min
#define max _max
#endif

class EasyBuzzerClass
{
  public:
	enum class Mode { BEEP, SIREN };
	EasyBuzzerClass();
	~EasyBuzzerClass();
	/* Beep continuously. */
	void beep(unsigned int frequency);
	/* Beep at a given frequency an specific number of times. */
	void beep(unsigned int frequency, unsigned int beeps);
	/* Beep at a given frequency an specific number of times, with callback functionality. */
	void beep(unsigned int frequency, unsigned int beeps, void (*finishedCallbackFunction)());
	/* Beep sequence at a given frequency. */
	void beep(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences);
	/* Beep sequence at a given frequency, with callback functionality. */
	void beep(unsigned int frequency, unsigned int const onDuration, unsigned int const offDuration, byte const beeps, unsigned int const pauseDuration, unsigned int const sequences, void (*finishedCallbackFunction)());
	/* Beep at a given frequency, for an specific duration. */
	void singleBeep(unsigned int frequency, unsigned int duration);
	/* Beep at a given frequency, for an specific duration, with callback functionality. */
	void singleBeep(unsigned int frequency, unsigned int duration, void (*finishedCallbackFunction)());
	/** Start siren with the specified mode, the given start and end fequency and the provided delay */
	void siren(bool riseAndFall, unsigned int startFrequency = DEFAULT_START_FREQ, unsigned int endFrequency = DEFAULT_END_FREQ, unsigned int delay = DEFAULT_SIREN_DELAY);
	/* Stop beeping. */
	void stop();
	/* Set the pin where the buzzer is connected. */
	void setPin(unsigned int pin);
	/* Set On duration. */
	void setOnDuration(unsigned int duration);
	/* Set Off duration. */
	void setOffDuration(unsigned int duration);
	/* Set Pause duration. */
	void setPauseDuration(unsigned int duration);
	/* Set buzzer volume. */
  	void setVolume(byte volume);
	/* Update function that keeps the library running. */
	void update();

  private:
	bool isArduino = true;
	unsigned int mPin = DEFAULT_PIN;
	unsigned int mFreq = DEFAULT_FREQ;
	unsigned int mChannel = DEFAULT_CHANNEL;
	byte mBeeps;
	unsigned int mOnDuration = DEFAULT_ON_DURATION;
	unsigned int mOffDuration = DEFAULT_OFF_DURATION;
	unsigned int mPauseDuration = DEFAULT_PAUSE_DURATION;
	unsigned int mSequences;
	unsigned int mVolume = DEFAULT_VOLUME;
	unsigned long mStartTime;
	unsigned long mLastRunTime;
	void (*mFinishedCallbackFunction)();
	bool mTurnedOn = false;
	bool mTurnedOff = false;
	Mode mMode = Mode::BEEP;
	unsigned int mStartFreq = DEFAULT_START_FREQ;
	unsigned int mEndFreq = DEFAULT_END_FREQ;
	unsigned int mSirenDelay = DEFAULT_SIREN_DELAY;
	bool mSirenRiseAndFall = true;
	unsigned long mLastSirenUpdateTime;
	bool mSirenRise = true;

	void updateBeep(unsigned long currentTime);
	void updateSiren(unsigned long currentTime);
};

extern EasyBuzzerClass EasyBuzzer;

#endif

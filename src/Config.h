/*
Name:		Config.h
Version:	1.0.0
Created:	9/29/2017 12:03:48 AM
Author:		Evert Arias
Github:		https://github.com/evert-arias/EasyBuzzer
Copyright (c) 2017 Evert Arias
*/

#pragma once

#ifndef _Config_h
#define _Config_h

#define DEFAULT_PIN			4		// Default pin number where the buzzer is connected.	0
#define DEFAULT_FREQ		1000    // Default frequency.
#define DEFAULT_CHANNEL		0		// Default PWM channel.
#define MINIMUM_INTERVAL    0      // Minimum interval allowed in milliseconds(ms).
#define DEFAULT_START_FREQ	700     // Default start frequency for siren mode.
#define DEFAULT_END_FREQ	800     // Default end frequency for siren mode.
#define DEFAULT_SIREN_DELAY 45      // Default delay between siren frequency increment
#define SIREN_INCREMENT     3

#define DEFAULT_ON_DURATION		100 // Default ON duration of a cycle in milliseconds(ms).
#define DEFAULT_OFF_DURATION	100 // Default OFF duration of a cycle in milliseconds(ms).
#define DEFAULT_PAUSE_DURATION	100 // Default PAUSE duration of a cycle in milliseconds(ms).

#endif

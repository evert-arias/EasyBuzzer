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
#define DEFAULT_VOLUME	    0x1FF   // 10 bit resolution => 50% duty cycle is 0x3FF/2 = 0x1FF
#define MINIMUM_INTERVAL    5       // Minimum interval allowed in milliseconds(ms).

#define DEFAULT_ON_DURATION		100 // Default ON duration of a cycle in milliseconds(ms).
#define DEFAULT_OFF_DURATION	100 // Default OFF duration of a cycle in milliseconds(ms).
#define DEFAULT_PAUSE_DURATION	100 // Default PAUSE duration of a cycle in milliseconds(ms).

#endif

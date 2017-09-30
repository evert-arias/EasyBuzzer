/*
	EasyBuzzer - Beep Sequence
	This example shows you how to create a sequence of beeps at a given frequency.
	Copyright (c) 2017, Evert Arias
	MIT License
*/

#include <EasyBuzzer.h>

void setup() {
	// Start a beeping sequence.
	EasyBuzzer.beepSequence(
		1000,		// Frequency in hertz(HZ).
		50,			// On Duration in milliseconds(ms).
		100,		// Off Duration in milliseconds(ms).
		2,			// The number of beeps per cycle.
		500,		// Pause duration.
		10      	// The number of cycle.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

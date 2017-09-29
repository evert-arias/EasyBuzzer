/*
	EasyBuzzer - Beep Sequence With A Callback
	This example shows you how to create a sequence of beeps at a given 
	frequency and make a call to a given function when the sequence ends.
	Copyright (c) 2017, Evert Arias
	MIT License
*/

#include <EasyBuzzer.h>

// This function will be called when the beeping sequence ends.
void finished() {
	Serial.println("Done!");
};

void setup() {
	Serial.begin(115200);
	// Start a beeping sequence.
	EasyBuzzer.beepSequence(
		1000,		// Beep's frequency.
		50,			// On duration.
		100,		// Off duration.
		2,			// The number of beeps per cycle.
		500,		// Pause duration.
		10,			// The number of cycle.
		finished	// [Optional] A function to call when the sequence ends.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

/*
	EasyBuzzer - Beep Once Example
	This example shows you how to make a single beep at given frequency.
	Copyright (c) 2017, Evert Arias
	MIT License
 */

#include <EasyBuzzer.h>

// This function will be called when the beeping sequence ends.
void finished() {
	// This function stop the beeping.
	EasyBuzzer.stopBeep();
};

void setup() {
	// Beep once
	EasyBuzzer.beep(
		1000,		// Beep's frequency.
		100,		// On duration.
		finished	// A function to call when the beep ends.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

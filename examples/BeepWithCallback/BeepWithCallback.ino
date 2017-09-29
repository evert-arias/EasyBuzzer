/*
	EasyBuzzer - Beep With CallBack
	This example shows you how to make a single beep at given frequency and call a given function at the end.
	Copyright (c) 2017, Evert Arias
	MIT License
*/

#include <EasyBuzzer.h>

// This function will be called when the beeping sequence ends.
void finished() {
	// This function stop the beeping.
	EasyBuzzer.stopBeep();
	Serial.println("Done!");
};

void setup() {
	Serial.begin(115200);
	// Beep.
	EasyBuzzer.beep(
		1000,		// Frequency.
		100,		// Duration.
		finished	// A function to call when the beep ends.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

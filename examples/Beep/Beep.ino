/*
	EasyBuzzer - Beep
	This example shows the differents beeps methods.
	Copyright (c) 2017, Evert Arias
	MIT License
*/

#include "EasyBuzzer.h"

unsigned int frequency = 1000;
unsigned int duration = 200;
unsigned int beeps = 10;

void done() {
	Serial.println("Done!");
}

void setup() {
	
	Serial.begin(115200);

	/* Start beeping continuously at a given frequency. */
	// EasyBuzzer.start(frequency);

	/* Stop beeping. */
	// EasyBuzzer.stopBeep();

	/* Start beeping at a given frequency, for an specific duration. */
	// EasyBuzzer.start(frequency, duration);

	/* Start beeping at a given frequency, for an specific duration, with callback functionality. */
	// EasyBuzzer.start(frequency, duration, done);

	/* Beep at a given frequency an specific number of beeps. */
	// EasyBuzzer.beep(frequency, beeps);
	
	/* Beep at a given frequency an specific number of beeps, with callback functionality. */
	// EasyBuzzer.beep(frequency, beeps, done);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

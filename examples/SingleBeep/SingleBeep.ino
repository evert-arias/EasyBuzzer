/*
	EasyBuzzer - Single Beep Example
	This example shows single beeps methods.
	Copyright (c) 2017, Evert Arias
	MIT License
*/

#include "EasyBuzzer.h"

unsigned int frequency = 1000;
unsigned int duration = 1000;

void done() {
	Serial.println("Done!");
}

void setup() {
	Serial.begin(115200);
	/* Single beep at a given frequency, for an specific duration, with callback functionality */
	EasyBuzzer.singleBeep(
		frequency, 	// Frequency in hertz(HZ).  
		duration, 	// Duration of the beep in milliseconds(ms). 
		done		// [Optional] Function to call when done.
	);
}

void loop() {
	/* Always call this function in the loop for EasyBuzzer to work. */
	EasyBuzzer.update();
}

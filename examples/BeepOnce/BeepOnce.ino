/*
	EasyBuzzer - Beep Once
	This example shows you how to make a single beep at given frequency.
	Copyright (c) 2017, Evert Arias
	MIT License
 */

#include <EasyBuzzer.h>

void setup() {
	// Beep once.
	EasyBuzzer.beep(
		1000,	// Frequency.
		100	    // Duration.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}
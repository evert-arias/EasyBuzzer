/*
<<<<<<< HEAD
	EasyBuzzer - Beep Once
=======
	EasyBuzzer - Beep Once Example
>>>>>>> 0b3cf33fdb1dc1cd2eb64c807087ea3db9797260
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

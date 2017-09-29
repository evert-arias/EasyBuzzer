/* EasyBuzzer - Sequence Example */

#include <EasyBuzzer.h>

void setup() {
	// Start a beeping sequence.
	EasyBuzzer.beepSequence(
		1000,	// Beep's frequency
		50,		// On duration
		100,	// Off duration
		2,		// Cycles
		500,	// Pause duration
		1,      // Sequences
		NULL	// Optional. A function to call when the sequence ends.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

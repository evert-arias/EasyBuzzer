/* EasyBuzzer - BeepOnce Example */

#include <EasyBuzzer.h>

// This function will be called when the beeping sequence ends.
void finished() {
	// This function stop the bepping.
	EasyBuzzer.stopBeep();
};

void setup() {
	EasyBuzzer.beep(
		1000,			// Beep's frequency
		100,			// On duration
		finished		// Optional. A function to call when the sequence ends.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

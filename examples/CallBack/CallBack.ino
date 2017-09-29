/* EasyBuzzer - Callback Example */

#include <EasyBuzzer.h>

// This function will be called when the beeping sequence ends.
void finished() {
	Serial.println("Sequence finished!");
};

void setup() {
	Serial.begin(115200);
	Serial.println("EasyBuzzer - Callback Example");
	Serial.println("Started!");
	// Start a beeping sequency.
	EasyBuzzer.beepSequence(
		1000,		// Beep's frequency
		50,			// On duration
		100,		// Off duration
		2,			// Cycles
		500,		// Pause duration
		10,			// Sequences
		finished	// Optional. A function to call when the sequence ends. Set it to NULL if no callback needed.
	);
}

void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}

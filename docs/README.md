# EasyBuzzer
[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

A library to easily make sounds with a Buzzer.

*This library is currently under development. Fixes and new features as well as support for more platforms will be included in further releases. If you find any issue please report it in the issues section.* 



## Supported Platforms

Currently **only supports** the `Esp32` platform. 

Support for this others platforms will be added. 

 `Arduino`  `Particle Photon`  `Particle Electron`

## Getting Started

##### Include the library in the sketch

`#include <EasyBuzzer.h>`

##### Run the library

``` c++
void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}
```



## Uses

#### Beep Once

Use this function `EasyBuzzer.beep()` to make a single beep at given frequency. Note that you have to use a callback function to stop the beeping sound of the buzzer.

```c++
// This function will be called when the beeping sequence ends
void finished() {
	// This function stop the beeping
	EasyBuzzer.stopBeep();
};
// Beep once
EasyBuzzer.beep(
	1000,		// Beep's frequency
	100,		// On duration
	finished	// A function to call when the beep ends
);
```


#### Beep Sequence

This function creates a sequence of beeps at a given frequency. 

```c++
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
```


#### Beep Sequence With A Callback

This function creates a sequence of beeps at a given frequency and make a call to a given function when the sequence ends.

```c++
// This function will be called when the beeping sequence ends
void finished() {
	Serial.println("Done!");
};
// Start a beeping sequence
EasyBuzzer.beepSequence(
	1000,		// Beep's frequency
	50,			// On duration
	100,		// Off duration
	2,			// The number of beeps per cycle
	500,		// Pause duration
	10,			// The number of cycles
	finished	// Optional. A function to call when the sequence ends.
);
```



## Copyright

[MIT](../LICENSE.md) © [Evert Arias](https://evert.ariascode.com/about)
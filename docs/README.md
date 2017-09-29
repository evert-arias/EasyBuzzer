# EasyBuzzer
[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

A library to easily make sounds with a Buzzer.

*This library is currently under development. Fixes and new features as well as support for more platforms will be included in further releases. If you find any issue please report it in the issues section.*



## Supported Platforms

Currently only supports the `Esp32` platform. 

Support for this others platforms will be added `Arduino`  `Particle Photon`  `Particle Electron`

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

#### Beep Continuously

`EasyBuzzer.beep(frequency)`

Use this function to beep continuously at a given `frequency`. Note that you must call `EasyBuzzer.stopBeep()` to stop beeping.

```c++
// Beep continuously.
EasyBuzzer.beep(frequency);	// Frequency in hertz(HZ).
```


#### Beep Once

`EasyBuzzer.beep(frequency, duration)`

Use this function to beep once at a given frequency `frequency` for a `duration`.

```c++
// Beep once.
EasyBuzzer.beep(
  1000,		// Frequency in hertz(HZ).
  100	    // Duration in milliseconds(ms).
);
```


#### Beep With Callback  

`EasyBuzzer.beep(frequency, duration, callback)`

Use this function to beep at a given `frequency` for a `duration  ` and make a `callback` at the end.

```c++
// This function will be called when the beeping sequence ends.
void finished() {
	// This function stop the beeping.
	EasyBuzzer.stopBeep();
	Serial.println("Done!");
};
// Setup
void setup() {
	Serial.begin(115200);
	// Beep.
	EasyBuzzer.beep(
		1000,		// Frequency in hertz(HZ).
		100,		// Duration in milliseconds(ms).
		finished	// Callback. A function to call when the beep ends.
	);
}
// Loop
void loop() {
	// Always call this function in the loop for EasyBuzzer to work.
	EasyBuzzer.update();
}
```



#### Beep Sequence 

```c++
EasyBuzzer.beepSequence(frequecy, onDuration, offDuration, cycles, pauseDuration, sequences, callback)
```

Use this function to start a sequence of beeps at a given frequency. 

```c++
// Start a beeping sequence
EasyBuzzer.beepSequence(
  1000,		// Frequency in hertz(HZ).
  50,		// On Duration in milliseconds(ms).
  100,		// Off Duration in milliseconds(ms).
  2,		// The number of beeps per cycle.
  500,		// Pause duration.
  1,      	// The number of cycle.
  NULL		// [Optional] Callback. A function to call when the sequence ends.
);
```



#### Beep Sequence With A Callback

```c++
EasyBuzzer.beepSequence(frequency, onDuration, offDuration, cycles, pauseDuration, sequences, callback)
```

Use this function to create a sequence of beeps at a given `frequency` and make a `callback` when the sequence ends.

```c++
// This function will be called when the beeping sequence ends.
void finished() {
  Serial.println("Done!");
};
// Start a beeping sequence.
EasyBuzzer.beepSequence(
  1000,		// Frequency in hertz(HZ).
  50,		// On Duration in milliseconds(ms).
  100,		// Off Duration in milliseconds(ms).
  2,		// The number of beeps per cycle.
  500,		// Pause duration.
  10,		// The number of cycle.
  finished	// [Optional] A function to call when the sequence ends.
);
```



## Copyright

[MIT](../LICENSE.md) © [Evert Arias](https://evert.ariascode.com/about)
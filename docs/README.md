# EasyBuzzer
[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

A library to easily make beeps with a Buzzer.

*This library is currently under development. Fixes and new features as well as support for more platforms will be included in further releases. If you find any issue please report it in the issues section.*



## Supported Platforms

Currently supports the `Esp32` platform only.

Support for this others platforms will be added `Arduino`  `Particle Photon`  `Particle Electron`

## Getting Started

##### Include the library in the sketch

`#include <EasyBuzzer.h>`

##### Set the Pin where the Buzzer is connected

By default, the library use the pin number 4. You may change the default pin number in the `Config.h` file. To set the pin number, call the function `EasyBuzzer.setPin(pin)` on the setup.

```c++
int pin = 2;
void setup() {
  EasyBuzzer.setPin(pin);
}
```

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


#### Stop beeping

`EasyBuzzer.stopBeep()` 

Use this function to stop the beeping. You may call this function at all time, everywhere in the code. This function is rarely used. Only when you run a beep continuously and you need to stop it manually.

```
EasyBuzzer.stopBeep();
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

Use this function to beep at a given `frequency` for a `duration  ` and make a call to a given `function` when the sequence ends.

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

Use this function to create a sequence of beeps at a given `frequency` and make a call to a given `function` when the sequence ends.

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
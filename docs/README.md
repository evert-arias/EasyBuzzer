# EasyBuzzer
[![License](http://img.shields.io/:license-mit-blue.svg)](http://doge.mit-license.org)

The Beep Library For Arduino

**​ This library has been tested on the following devices:**

- Arduino UNO  :ok:
- Arduino MEGA 2560 :ok:
- ESP32 :ok:

## What to expect in next updates

- [ ] Support for multiple instances of `EasyBuzzer` Class, making possible to have more than one Buzzer.
- [ ] Shortcut functions to predefined sounds like; success, error and warning.

## Getting Started

#### Include the library in the sketch

`#include <EasyBuzzer.h>`

#### Set the pin where the buzzer is connected

By default, the library is configured to use the pin number 4. You may change the default pin number, modifying the value of `DEFAULT_PIN`  in *Config.h* file. To set the pin number on the sketch, call the function `EasyBuzzer.setPin(pin)` on the setup.

```c++
int pin = 2;
void setup() {
  EasyBuzzer.setPin(pin);
};  
```

#### Run the library

``` c++
void loop() {
  /* Always call this function in the loop for EasyBuzzer to work. */
  EasyBuzzer.update();
};
```



## Uses

### Regular Beep

Beep continuously at a given frequency.

```c++
/* Beep continuously at a given frequency. */
EasyBuzzer.beep(
  frequency	// Frequency in Hertz(HZ).
);
```

Beep at a given frequency an specific number of times. 

```c++
/* 
	Beep at a given frequency an specific number of times. 
	The default onDuration and offDuration is set in Config.h file. 
*/
EasyBuzzer.beep(
  frequency,	// Frequency in Hertz(HZ).
  beeps		// The number of beeps.
);
```

Beep at a given frequency an specific number of times, with callback functionality.

```c++
/* 
	Beep at a given frequency an specific number of times, with callback functionality. 
	The default onDuration and offDuration is set in Config.h file.
*/
EasyBuzzer.beep(
  frequency,	// Frequency in Hertz(HZ).
  beeps,	// The number of beeps.
  callback	// [Optional] Function to call when done.
);
```



### Beep Sequence

Create a sequence of beeps at a given frequency. 

```c++
/* Create a sequence of beeps at a given frequency. */
EasyBuzzer.beep(
  frequency,		// Frequency in hertz(HZ).
  onDuration, 		// On Duration in milliseconds(ms).
  offDuration, 		// Off Duration in milliseconds(ms).
  beeps, 		// The number of beeps per cycle.
  pauseDuration, 	// Pause duration.
  cycles, 		// The number of cycle.
  callback		// [Optional] Function to call when done.
);	
```



### Single Beep For A Duration 

Single beep at a given frequency, for an specific duration.

```c++
/* Single beep. */
EasyBuzzer.singleBeep(
  frequency,	// Frequency in hertz(HZ).
  duration	// Duration of the beep in milliseconds(ms).
);
```

Single beep at a given frequency, for an specific duration, with callback functionality.

```c++
/* Single beep at a given frequency, for an specific duration, with callback functionality. */
EasyBuzzer.singleBeep(
  frequency, 	// Frequency in hertz(HZ).
  duration, 	// Duration of the beep in milliseconds(ms).
  callback	// [Optional] Function to call when done.
);
```



### Stop Beeping

Use this function to stop the beeping. You may call this function at all time, everywhere in the code.

```c++
EasyBuzzer.stopBeep();
```



### Modifying the default duration values

The default duration values are defined in the *Config.h* file. You may change those values on the *Config.h* file or use the provided function to change them.

```c++
EasyBuzzer.setOnDuration(duration);	// Set On duration.
EasyBuzzer.setOffDuration(duration);	// Set Off duration.
EasyBuzzer.setPauseDuration(duration);	// Set Pause duration.
```



## Copyright

[MIT](../LICENSE.md) © [Evert Arias](https://evert.ariascode.com/about)

# ArduinoDebugger
Arduino Debugger Project

The debugger is made for debugging Arduino easier. Please follow the instruction below for usage.

## Requirements

- Arduino ide
- Atmel Studio
- Visual Studio

## Usage

1. Compile Arduino sketch with Atmel Studio
2. Compile the Sketch file located under [SourceCode/Atmelstudio/ArduinoSimulater/ArduinoSketch2/Blink/A32u4](ArduinoDebugger/SourceCode/Atmelstudio/ArduinoSimulater/ArduinoSketch2/Blink/A32u4)
3. Make new directory name "Sketch"
4. Change the file extension of Sketch from .cpp to .ino
5. Due to the different line Formatting, the first line of Sketch.ino could create an error when compilling and might need to be rewritten manually.
6. Compile and upload to Arduino.
7. Open the [ArduinoTraceDebug](SourceCode/VisualStudio/ArduinoDebugLibrary) solution (which can be located in the SourceCode folder) with Visual Studio
8. Start a template for the next project.

## How it works

A communication between Arduino and the PC must be established. The idea is that, for each set of instructions, a package of signal is sent to the arduino, which translates the package to corresponding action. It doesn't matter what form of communication it is. It could be HID, serial, wifi, bluetooth, or mqtt. 

Take for example:
>digitalWrite(13, HIGH)

Which is made to look identical, but is only a function that sends signal.

The command is translated in some form of signal representing the corresponding command, and is forward to the Arduino. The pre-programmed Arduino now translate the action:

>Received a signal, it said run a function A with parameters B, C.

Then the program in arduino calls the function digitalWrite with the parameters 13, HIGH.

More functions is to be updated, please check the details for the available commands.

## Details

### Available Commands
- All supported command from [Arduino's Official Documents](https://www.arduino.cc/reference/en/)
### Supported Versions of Arduino
- Arduino Leonardo (Possibly all Arduinos with an Atmega32u4)

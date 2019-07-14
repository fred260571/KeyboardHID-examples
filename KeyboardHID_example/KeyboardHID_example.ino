/*
  KeyboardHID example

  For the Arduino Leonardo and Micro.

  Sends USB HID values to the computer when a button is pressed.

  The circuit:
  - pushbutton attached from pin 4 to +5V
  - 10 kilohm resistor attached from pin 4 to ground

  created 24 Oct 2011
  modified 27 Mar 2012
  by Tom Igoe
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 14 July 2019
  by Frederic Pouchal

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardMessage

  KeyboardHID can be downloaded at
  https://github.com/fred260571/KeyboardHID
*/

#include <KeyboardHID.h>

const int buttonPin = 4;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton
int counter = 4;                  // button push counter

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  KeyboardHID.begin();
  Serial.begin(9600);
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {

    // shows USB HID output
    KeyboardHID.write(counter);
    KeyboardHID.write(40); // new line
    // shows HID number on the serial monitor
    Serial.println(counter);
    // increment the button counter
    counter++;
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;
}

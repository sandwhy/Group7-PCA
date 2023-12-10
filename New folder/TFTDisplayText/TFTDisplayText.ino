/*
  Arduino TFT text example

  This example demonstrates how to draw text on the
  TFT with an Arduino. The Arduino reads the value
  of an analog sensor attached to pin A0, and writes
  the value to the LCD screen, updating every
  quarter second.

  This example code is in the public domain

  Created 15 April 2013 by Scott Fitzgerald

  http://www.arduino.cc/en/Tutorial/TFTDisplayText

 */

#include <TFT.h>  // Arduino LCD library
#include <SPI.h>

// pin definition for the Uno
#define cs   10
#define dc   9
#define rst  8
TFT myScreen = TFT(cs, dc, rst);

void setup() {
  myScreen.begin();
  myScreen.background(0,0,0); // clear the screen

  // write the static text to the screen
  // set the font color to white
  myScreen.stroke(255, 255, 255);


  myScreen.stroke(255,255,255);

  // static text
  myScreen.setTextSize(1);
  myScreen.text("one \n", 0,0);
  myScreen.setTextSize(2);
  myScreen.text("two \n", 1,1);
  myScreen.setTextSize(3);
  myScreen.text("three \n", 2,2);

  // increase font size for text in loop()

  myScreen.setTextSize(3);
}

void loop() {

  // // Read the value of the sensor on A0
  // String sensorVal = String(analogRead(A0));

  // // convert the reading to a char array
  // sensorVal.toCharArray(sensorPrintout, 4);

  // // set the font color
  // TFTscreen.stroke(255, 255, 255);
  // // print the sensor value
  // TFTscreen.text(sensorPrintout, 0, 20);
  // // wait for a moment
  // delay(250);
  // // erase the text you just wrote
  // TFTscreen.stroke(0, 0, 0);
  // TFTscreen.text(sensorPrintout, 0, 20);
}


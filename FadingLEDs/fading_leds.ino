/*
  This example shows how to fade LEDs on pin 9 and pin 6 using the analogWrite()
  function.
*/

int led = 9;           // the PWM pin the LED is attached to
int led2 = 6;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int brightness2 = 255; 
int fadeAmount = 5;    // how many points to fade the LED by


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 and 6 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9 and 6:
  analogWrite(led, brightness);
  analogWrite(led2, brightness2);

  //pin 9 starts off and pin 6 starts on

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness2 = brightness2 - fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  if (brightness2 <= 0 || brightness2 >= 255) {
    fadeAmount = +fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

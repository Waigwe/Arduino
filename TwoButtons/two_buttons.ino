/*
  Using 2 buttons to turn 1 LED on and off
*/

const int button = 4;            // pin 4 for the first button
const int button2 = 2;            // pin 2 for the second button
const int led = 8;                // pin 8 for the LED
int ledflag=0;                   // LED status flag

void setup() {
  pinMode(button,INPUT);         // define first button as an input
  pinMode(button2,INPUT);         // define second button as an input  
  pinMode(led,OUTPUT);           // define LED as an output
  digitalWrite(led,LOW);         // turn output off just in case
}

void loop() {
  if (digitalRead(button)==HIGH || digitalRead(button2)==HIGH){ // if button is pressed
    if (ledflag==0) {             // and the status flag is LOW
      ledflag=1;                  // make status flag HIGH
      digitalWrite(led,HIGH);     // and turn on the LED
      }                           // 
    else {                        // otherwise...
      ledflag=0;                  // make status flag LOW
      digitalWrite(led,LOW);      // and turn off the LED
    }
  delay(1000);                    // wait a sec for the 
  }                               // hardware to stabilize
}                                 // begin again 

/*
  Light LEDs to the tune produced by a buzzer
*/


#include "pitches.h" //include this library

const int BUZZER_PIN = 2; // Arduino pin connected to Buzzer's pin

// notes in the melody:
int melody[] = {
NOTE_C4, NOTE_G3,NOTE_G3, NOTE_GS3, NOTE_G3,0, NOTE_B3, NOTE_C4};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
   4, 8, 8, 4,4,4,4,4 
};

//LED pins
int leds[] = {
   3,5 , 6,7, 8, 9,12,13,
};

void setup() {
  // set all pins to output mode
  pinMode(BUZZER_PIN, OUTPUT);       
  pinMode(3, OUTPUT);       
  pinMode(5, OUTPUT);       
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);       
  pinMode(8, OUTPUT);       
  pinMode(9, OUTPUT);      
  pinMode(12, OUTPUT);     
  pinMode(13, OUTPUT);     
}

void loop() {
     // iterate over the notes of the melody:
   for (int thisNote = 0; thisNote < 8; thisNote++) {
    //iterate over the leds
    for(int thisLed = 0; thisLed < 8; thisLed++){
        // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000/noteDurations[thisNote];
      //turn the current led on
      digitalWrite(leds[thisLed], HIGH);
      tone(BUZZER_PIN, melody[thisNote],noteDuration);
      //pause for the note's duration plus 30 ms:
      delay(noteDuration +30);
      //turn the current led off
      digitalWrite(leds[thisLed], LOW);
      }
   }
}

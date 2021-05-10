/*
  Display digital brightness value on adjusting the potentiometer resistance 
*/

int sensorPin = A3;    // select the input pin for the potentiometer
int ledPin = 3;      // select the pin for the LED
int sensorValue;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  int sensorValue = analogRead(sensorPin)/4; //we divide by 4 to display value between 0-255
  analogWrite(ledPin, sensorValue);
  Serial.println(sensorValue);
  delay(50);
}

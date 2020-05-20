
// Header section for importing libraries
// #include <DateTime.h>
//  #include <DateTimeStrings.h>

#define TIME_MSG_LEN 11
#define TIME_HEADER 255

// Global variable declarations
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int scaledFreq = 0;
int counter = 0;
int currentTime = 0;
int prevSensorVal = 0;
int valDiff = 0;

// Main setup function 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Serial communication started");
  Serial.print('\n');

  pinMode(2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

}

// Main loop
void loop() {
  
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  valDiff = abs(sensorValue-prevSensorVal);
  
  if(sensorValue != prevSensorVal && valDiff > 3){
    Serial.print(sensorValue);
    Serial.print('\n');
  }
  else
  
  scaledFreq = sensorValue * 1000;

  if (scaledFreq > 5000) {
    scaledFreq = 5000;
  }
  else if (scaledFreq < 500) {
    scaledFreq = 500;
  }

  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  delayMicroseconds(scaledFreq * .1); //Approx 10% duty cycle @ 1kHz

  digitalWrite(2, LOW);
  delayMicroseconds(scaledFreq - scaledFreq * .1);

  prevSensorVal = sensorValue;
}

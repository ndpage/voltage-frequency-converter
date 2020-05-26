
// Header section for importing libraries
// #include <DateTime.h>
//  #include <DateTimeStrings.h>

#define MAX_FREQ 200
#define MIN_FREQ 2
#define MAX_VOLTAGE 5
#define MIN_VOLTAGE 0

// Global variable declarations
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int freqOutputPin = 2;
double sensorValue = 0.0;
double setPoint = 0;  // variable to store the value coming from the sensor
double freqSetPoint = 0;
double timeSetPoint = 0;



// Main setup function 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial communication started");

  pinMode(freqOutputPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

}

// Main loop
void loop() {
    // put your main code here, to run repeatedly:

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
    
    // Convert from volts to hertz
  freqSetPoint = ((MAX_FREQ-MIN_FREQ)/(MAX_VOLTAGE-MIN_VOLTAGE))*sensorValue;
  
  if (freqSetPoint > MAX_FREQ) {
    freqSetPoint = MAX_FREQ;
  }
  else if (freqSetPoint < MIN_FREQ) {
    freqSetPoint = MIN_FREQ;
  }

timeSetPoint = 1/freqSetPoint;
timeSetPoint = timeSetPoint*1000; //convert time set point to miliseconds to use with delay()
  
  digitalWrite(2, HIGH);
  delay(timeSetPoint/2);

  digitalWrite(2, LOW);
  delay(timeSetPoint/2);
}


// Global variable declarations
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int freqOutputPin = 2;
int sensorValue = 0; // variable to store the value coming from the sensor
float freqSetPoint = 0; 
float timeSetPoint = 0;



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
  sensorValue = analogRead(sensorPin); // Returns an int value between 0-1023

    // Convert from volts to hertz
  freqSetPoint = (512.0/1023)*sensorValue; 
  
  if (freqSetPoint > 512) {
    freqSetPoint = 512.0;
  }
  else if (freqSetPoint < 5) {
    freqSetPoint = 5.0;
  }
Serial.println(freqSetPoint);

timeSetPoint = 1/freqSetPoint;
timeSetPoint = timeSetPoint*1000; //convert time set point to miliseconds to use with delay()
  
  digitalWrite(2, HIGH);
  delay(timeSetPoint/2);

  digitalWrite(2, LOW);
  delay(timeSetPoint/2);
}

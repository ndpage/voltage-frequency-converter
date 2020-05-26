

// Global variable declarations
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
double setPoint = 0;  // variable to store the value coming from the sensor
double freqSetPoint = 0;
double timeSetPoint = 0;


// Main setup function 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial communication started");

  pinMode(2, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

// Main loop
void loop() {
// put your main code here, to run repeatedly:

freqSetPoint = 100; //Hz

  if (freqSetPoint > 200) {
    freqSetPoint = 200; //Hz
    Serial.print("Max frequency is 5000 Hz!");
    Serial.print('\n');
  }
  else if (freqSetPoint < 5) {
    freqSetPoint = 5; //Hz 
    Serial.print("Min frequency is 20 Hz!");
    Serial.print('\n');
  }
  else
  
timeSetPoint = 1/freqSetPoint;
timeSetPoint = timeSetPoint*1000; //convert time set point to miliseconds to use with delay()
  
  digitalWrite(2, HIGH);
  delay(timeSetPoint/2);

  digitalWrite(2, LOW);
  delay(timeSetPoint/2);

}

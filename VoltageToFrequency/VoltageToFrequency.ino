
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
  freqSetPoint = 100.0;
  
freqSetPoint = checkLimits(freqSetPoint);

printFloat(freqSetPoint);

timeSetPoint = 1/freqSetPoint;
timeSetPoint = timeSetPoint*1000; //convert time set point to miliseconds to use with delay()
 /* 
  digitalWrite(2, HIGH);
  delay(timeSetPoint/2);

  digitalWrite(2, LOW);
  delay(timeSetPoint/2);
  */
}

float checkLimits(float value){
  if (value > 512) {
    return 512.0;
  }
  else if (value < 5) {
    return 5.0;
  }
  else return value;
}

void updateSerial(int input){
  Serial.println(input);
  return ;
}

void printFloat(float valueToPrint) {
  const long timeInterval = 1000;
  static unsigned long lastTime = 0;
  
  unsigned long now = millis();

  if ( now - lastTime > timeInterval) {
    lastTime = now;
    Serial.println(valueToPrint);
  }
}

void printString(char* valueToPrint) {
  const long timeInterval = 1000;
  static unsigned long lastTime = 0;
  
  unsigned long now = millis();

  if ( now - lastTime > timeInterval) {
    lastTime = now;
    Serial.println(valueToPrint);
  }
}



// Global variable declarations
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int freqOutputPin = 2;
int sensorValue = 0; // variable to store the value coming from the sensor
float freqSetPoint = 0; 

float maxFreq = 500.0;
float minFreq = 5.0;

/*  
 *   Main set up functions 
*/ 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial communication started");

  pinMode(freqOutputPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

}

/*  
 *   Main loop 
*/ 
void loop() {
    // put your main code here, to run repeatedly:

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); // Returns an int value between 0-1023

    // Convert from volts to hertz
  freqSetPoint = (maxFreq/1023)*sensorValue; 
  
freqSetPoint = checkLimits(freqSetPoint);

printFloat(freqSetPoint);

 /* 
  digitalWrite(2, HIGH);
  delay(timeSetPoint/2);

  digitalWrite(2, LOW);
  delay(timeSetPoint/2);
  */
}
//======= END OF MAIN LOOP  =======


/*-----------------------------------------------------------------------------------------------
 Name: checkLimits
 Usage: Checks the calculated value and coerrces to the maximum or minimum limits
        specified by the global variables maxFreq and minFreq, respectively
 Author: Nathan Page 
 -----------------------------------------------------------------------------------------------
 */
float checkLimits(float value){
  if (value > maxFreq) {
    return maxFreq;
  }
  else if (value < minFreq) {
    return minFreq;
  }
  else return value;
}//-----------------------------------------------------------------------------------------------

/*-----------------------------------------------------------------------------------------------
 Function: setOutputFreq
 Usage: Sets the output frequency of the specified digital output pin. Pulse width is set by the 
        variable pulseWidth
 Author: Nathan Page

                      #####  INCOMPLETE #####
 ------------------------------------------------------------------------------------------------
 */
void setOutputFreq(float frequencySetPoint) {
  //const long timeInterval = 1000; // in milliseconds
  static unsigned long lastTime = 0;
  static unsigned int currentState=0;
  static unsigned int prevState=0;
  
  float timeSetPoint = 0;
  
  unsigned long currentTime = millis(); // Get the current time

// NEED TO DETERMINE MECHANISM FOR SETTING THE OUTPUT FREQUENCY 
//  WHEN CALLING THIS FUNCTION FROM THE MAIN LOOP

  timeSetPoint = 1/frequencySetPoint;
  timeSetPoint = timeSetPoint*1000; //convert time set point to miliseconds 

  if ( currentTime - lastTime > timeSetPoint) {
    lastTime = currentTime;
    // Set the digital pin HIGH or LOW depending on the frequency set point and previous state
    switch(prevState){
      case 0: digitalWrite(2, HIGH);
              currentState = 1;
              break;
      case 1: digitalWrite(2, LOW);
              currentState = 0;
              break;
      default: digitalWrite(2, LOW);
               currentState = 0; 
              break;
    }
    prevState = currentState;
  }
  
}//-----------------------------------------------------

/*-----------------------------------------------------------------------------------------------
 Function: printFloat
 Usage: Prints the float value passed to the function to the serial stream 
        at a specified time interval (in ms)
 Author: Nathan Page
 -----------------------------------------------------------------------------------------------
 */
void printFloat(float valueToPrint) {
  const long timeInterval = 1000; // in milliseconds
  static unsigned long lastTime = 0;
  
  unsigned long now = millis(); // Get the current time

  if ( now - lastTime > timeInterval) {
    lastTime = now;
    Serial.println(valueToPrint);
  }
}//-----------------------------------------------------------------------------------------------

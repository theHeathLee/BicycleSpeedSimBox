/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(5, 6);
//   avoid using pins with LEDs attached
unsigned long PulseDelay; 
void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
  unsigned long PulseDelay = millis();
  //Pulselegth = millis();
  pinMode(LED_BUILTIN, OUTPUT);
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    oldPosition = newPosition;
    Serial.println(newPosition);
  }

  if (millis() >= PulseDelay + (10000/newPosition)) {

    //all funtions to be run every second
    statusLED();
    
    PulseDelay = millis(); //reset timer
  }
}

void statusLED(){
  
    digitalWrite(LED_BUILTIN, 1);
    delay(20);
    digitalWrite(LED_BUILTIN, 0);
    
}  

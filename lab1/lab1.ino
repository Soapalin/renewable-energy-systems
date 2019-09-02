#include <PWM.h>

int pin_PWM = 10;  
int32_t frequency = 100000; //frequency (in Hz)

void setup() {
//initialize all timers except for 0, to save time keeping functions
InitTimersSafe(); 
//sets the frequency for the specified pin
bool success = SetPinFrequencySafe(pin_PWM, frequency);
 if(success) {
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);    
    pinMode(pin_PWM,OUTPUT);
 }
}

void loop() {

analogWrite(pin_PWM,40); //duty cycle 50%

}

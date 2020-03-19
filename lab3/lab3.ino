#include <PWM.h>
int pin_PWM = 10;
const int pin_ADC = A0; 
int duty = 40; // duty cyle 50%
int Vref = 17.84; // Vref found in prelab 
int32_t frequency = 100000; // Hz
float MPPT; // read value 

void setup() {
  InitTimersSafe();

  bool success = SetPinFrequencySafe(pin_PWM, frequency);
  if(success)
  {
    pinMode(pin_PWM, OUTPUT);
    Serial.begin(9600);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  MPPT = analogRead(pin_ADC); // Read analog value on pin A0
  MPPT = MPPT*5/1023; // convert analog to digital 
  MPPT = MPPT*10/1.5; // voltage divider ratio, approx (1.7+8.2)/1.7
  delay(100); // delay 

  Serial.println(MPPT); // print to keep track of the value 
  
  if(MPPT >= Vref) // If the output voltage is higher than our theorical value, decrease duty cycle
  {  
    duty--;
    delay(500); 
  }
  else if (MPPT < Vref) // If the output voltage is lower than our theoriccal value, increase duty cycle
  {   
    duty++;
    delay(500);    
  } 
  if(duty > 72) // upper limit duty cycle 90%
  {
    duty = 72;
  }
  if(duty < 8) // limit duty cycle over 10%
  {
    duty = 8;
  }
  analogWrite(pin_PWM, duty); // Write duty cycle to PWM pin
  delay(500); // delay to see how the circuit and results behaves 

}

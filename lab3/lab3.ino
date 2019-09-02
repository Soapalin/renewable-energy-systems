#include <PWM.h>
int pin_PWM = 10;
const int pin_ADC = A0;
int duty = 40;
int Vref = 17.84;
int32_t frequency = 100000;
float MPPT;
int count;
// 0.0272

void setup() {
  // put your setup code here, to run once:
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
  MPPT = analogRead(pin_ADC)*0.0049;
  delay(100);


  Serial.println(MPPT);
  
  if(MPPT > Vref)
  {
    
    duty++;
    delay(500);
  }
  else if (MPPT < Vref)
  {
    
    duty--;
    delay(500);
    
  }

  
  
  if(duty > 72)
  {
    duty = 72;
  }
  if(duty < 8)
  {
    duty = 8;
  }
  analogWrite(pin_PWM, duty);
  delay(500);

}

#include <PWM.h>
int pin_PWM = 10;
const int pin_ADC1 = A0;
const int pin_ADC2 = A1;
float InputVoltage = 0;
float OutputVoltage =0;
float PVstart = 0; // PV power old value 
float PVPnew = 0; // PV power new value 
int duty = 40;
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
  InputVoltage = analogRead(pin_ADC1)*0.0049;
  OutputVoltage = analogRead(pin_ADC2)*0.0049;
  delay(200);
  PVPnew = InputVoltage * OutputVoltage;
  

  Serial.println(PVPnew);
  
  if(PVPnew > PVstart)
  {
    duty++;
  }
  else if (PVPnew < PVstart)
  {   
    duty--;
  }
  delay(500);

  
  
  if(duty > 72)
  {
    duty = 72;
  }
  if(duty < 8)
  {
    duty = 8;
  }
  analogWrite(pin_PWM, duty);
  PVstart = PVPnew;
  delay(500);

}

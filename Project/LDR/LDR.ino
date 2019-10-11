//Variables
int inPin = A0; //Pin the sensor is connected to
int sensorVal = 0; //Variable to store sensor data
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Serial Communication started...\n");
}
void loop() {
// put your main code here, to run repeatedly:
sensorVal = analogRead(inPin); //analogRead will read the voltage on the pin specified and return it as a value between 0 and 1024.
Serial.println(sensorVal); //Print the sensor reading to the serial window so we can view the data.
delay(1000);
}

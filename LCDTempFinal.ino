#include <SoftwareSerial.h>
SoftwareSerial LCD= SoftwareSerial(255,3);
int val = 0;                 
float temp=0;

void setup() {  
   Serial.begin(9600);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   digitalWrite(3,HIGH);

   LCD.begin(9600);
   delay(100);

   LCD.write(17);
   LCD.write(22);
   delay(10);
   LCD.print("Current Temperature");
   LCD.write(13);
   LCD.write(153);
   LCD.print("F");
}

void loop() {
    val = analogRead(5);
    temp = ((0.1820*val)-12.372);
    LCD.write(148);
    LCD.print(temp);   
    
    if (temp < 75.0){
      digitalWrite(4, HIGH);
      LCD.write(220);
      LCD.write(188);
      LCD.print("Heater is on!");
    }
    if (temp >= 80.0){
    digitalWrite(4, LOW);
    LCD.write(188);
    LCD.print("Heater is off");
    } 
    delay(1000);
}

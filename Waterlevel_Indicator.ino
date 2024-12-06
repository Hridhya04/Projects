#include <LiquidCrystal.h>
const int trigPin = 2;
const int echoPin = 3;
const int buzzer = 13;

LiquidCrystal lcd(12,11,5,4,6,7);
                         
long duration;
int distance;
int safetyDistance;
 
            
void setup() {
 
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer, OUTPUT);
lcd.begin(16,2);
Serial.begin(9600); 
}
 
 
void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
 

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

 

duration = pulseIn(echoPin, HIGH);
 
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)  
{
  digitalWrite(buzzer, HIGH);
  
  
}
else{
  digitalWrite(buzzer, LOW);
  
  
}
lcd.setCursor(0,0);
lcd.print("Distance: ");
lcd.print(distance);
lcd.print("cm");
delay(1000); 
Serial.print("Distance: ");
Serial.println(distance);
delay(2000);
}

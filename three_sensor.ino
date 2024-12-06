
const int trigPin1 = 9;
const int echoPin1 = 10;
const int trigPin2 = 2;
const int echoPin2 = 3;
const int trigPin3 = 4;
const int echoPin3 = 5;

const int buzzer = 11;

                         
long duration;
int distance;
int safetyDistance;
 
            
void setup() {
pinMode(trigPin1, OUTPUT); 
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT); 
pinMode(buzzer, OUTPUT);

Serial.begin(9600);
 
}
 
 
void loop() {

digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
digitalWrite(trigPin3, LOW);

delayMicroseconds(2);
 

digitalWrite(trigPin1, HIGH);
digitalWrite(trigPin2, HIGH);
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
digitalWrite(trigPin3, LOW);
 

duration = pulseIn(echoPin1, HIGH);
duration = pulseIn(echoPin2, HIGH);
duration = pulseIn(echoPin3, HIGH);
 
distance= duration*0.034/2;
 
safetyDistance = distance;
if (safetyDistance <= 20)  
{
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  
}
 
Serial.print("Distance: ");
Serial.println(distance);
}

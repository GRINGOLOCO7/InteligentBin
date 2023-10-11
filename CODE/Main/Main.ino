
#include <Servo.h>

Servo myservo;
float distance;
const int trigg_pin = 3; // We use pin 3 to trigger the Ultrasound Device
const int echo_pin = 4;


void setup()
{
  Serial.begin(9600);
  pinMode(trigg_pin, OUTPUT);
  pinMode(echo_pin, INPUT);  
  myservo.attach(9);
  myservo.write(140);
}
int counter;
void loop()
{
  digitalWrite(trigg_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigg_pin, LOW);
  distance = 0.034*pulseIn(echo_pin,HIGH)/2;
  Serial.println(distance);

  if (distance < 25){
    counter = 0;
    myservo.write(0); 
    delay(600); 
    //distance = 20;
    while (distance > 15 && counter < 80){ // or 15 sec have passed
      digitalWrite(trigg_pin,HIGH);
      delayMicroseconds(10);
      digitalWrite(trigg_pin, LOW);
      distance = 0.034*pulseIn(echo_pin,HIGH)/2;
      Serial.println(distance);
      counter++;
      delay(100);
    }   
    myservo.write(140);   
    }
  delay(800);
}
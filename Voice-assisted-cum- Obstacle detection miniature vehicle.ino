//Arduino 1.8.15
//roject: VOICE-ASSISTED + OBSTACLE DETECTION MINIATURE VEHICLE
//Author:Dheepak_G

#include <SoftwareSerial.h>

SoftwareSerial BT(0, 1); //(TX, RX )
String readvoice;

#define trigPin 9//set pin 9 as the trigPin //transmitter of Ultrasonic_sensor_SR04
#define echoPin 8//set pin 8 as the echoPin //Receiver of Ultrasonic_sensor_SR04
#define motor1pin1 3//CONNECT PIN 1 AS MOTOR DRIVER PIN 1
#define motor1pin2 4//CONNECT PIN 2 AS MOTOR DRIVER PIN 2
#define motor2pin1 5//CONNECT PIN 3 AS MOTOR DRIVER PIN 3
#define motor2pin2 6//CONNECT PIN 4 AS MOTOR DRIVER PIN 4
#define led1 1 //red LED//set pin 2 to led1
#define led2 2 //green LED//set pin 3 to led2

void setup() {
  BT.begin(9600);
  Serial.begin (9600);//begin with standard baud rate 
  pinMode(trigPin, OUTPUT);//mode select trigPin as OUTPUT
  pinMode(echoPin, INPUT);//mode select echo pin as INPUT
  pinMode(led1, OUTPUT);//mode select led1 as OUTPUT
  pinMode(led2, OUTPUT);//mode select led2 as OUTPUT
}

void loop() {
	while (BT.available()){  //Check  byte to read
  delay(10); //Stability Delay
  char c = BT.read(); //Serial read
  readvoice += c; // "forward", "reverse", "left" and "right"
  } 
  if (readvoice.length() > 0) {
    Serial.println(readvoice);

  
    long duration, distance;
  digitalWrite(trigPin, LOW); //Iteration
  delay(2); //Before transmission pause for 2 Microseconds.
  digitalWrite(trigPin, HIGH);//Iteration
  delay(10); //transmitting .....10 Microseconds
  digitalWrite(trigPin, LOW); //Iteration
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1;//Formula to calculate the distance using the duration
  
  if (distance < 10) {  //distance is less than 10cm so red LED turns on & Car is stopped
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
   
	if (readvoice == "*left#")
  {
    digitalWrite (3,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    digitalWrite (6,LOW);
   delay (800);
      digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
  
  }

 else if ( readvoice == "*right#")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   delay (800);
      digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
 }
        }
  else {	//distance is more than 10cms so green LED turns on & car is set to move as per the user's wish
  digitalWrite(led1,LOW); 
  digitalWrite(led2,HIGH);
  
    if(readvoice == "*forward#")
  {
    digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
  }

  else if(readvoice == "*back#")
  {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6,HIGH);
    delay(100);
  }

  else if (readvoice == "*left#")
  {
    digitalWrite (3,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    digitalWrite (6,LOW);
   delay (800);
      digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
  
  }

 else if ( readvoice == "*right#")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   delay (800);
      digitalWrite(3, HIGH);
    digitalWrite (4, HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    delay(100);
 }

 else if (readvoice == "*stop#")
 {
   digitalWrite (3, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   delay (100);
 }

      }
  if (distance >= 400 || distance <= 0){ //range is 150 cm for SR04 sensor
    Serial.println("Out of range");
      }
  else {
    Serial.print("Distance :  ");
    Serial.print(distance);
    Serial.println(" cm"); //in centimeters
  }
  delay(1000);
  
  readvoice="";
}

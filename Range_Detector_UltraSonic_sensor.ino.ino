//Arduino 1.8.15
//project name: Range Detector using SR04
//Author:Dheepak_g


#define trigPin 9//set pin 9 as the trigPin //transmitter of Ultrasonic_sensor_SR04
#define echoPin 8//set pin 8 as the echoPin //Receiver of Ultrasonic_sensor_SR04
#define led1 2 //red LED//set pin 2 to led1
#define led2 3 //green LED//set pin 3 to led2

void setup() {
  Serial.begin (9600);//begin with standard baud rate 
  pinMode(trigPin, OUTPUT);//mode select trigPin as OUTPUT
  pinMode(echoPin, INPUT);//mode select echo pin as INPUT
  pinMode(led1, OUTPUT);//mode select led1 as OUTPUT
  pinMode(led2, OUTPUT);//mode select led2 as OUTPUT
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); //Iteration
  delay(2); //Before transmission pause for 2 Microseconds.
  digitalWrite(trigPin, HIGH);//Iteration
  delay(10); //transmitting .....10 Microseconds
  digitalWrite(trigPin, LOW); //Iteration
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;//Formula to calculate the distance using the duration
  if (distance < 10) {  //distance is less than 10cm so red LED turns on
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
}
  else {
  digitalWrite(led1,LOW); //distance is more than 10cms so green LED turns on
  digitalWrite(led2,HIGH);

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
}

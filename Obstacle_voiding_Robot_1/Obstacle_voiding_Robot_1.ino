#include <AFMotor.h>

// AF_DCMotor motor1(1); // Create a motor object for motor 1
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);

const int trigPin = 9;
const int echoPin = 10;
long duration ;
int distanceCm;






void setup() {
  // Set the motor speed (optional)
  motor1.setSpeed(200); // Set speed to 150 (out of 255)
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200); 

  pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
Serial.begin(9600);

}

void loop() {
FOR();


}

void FOR(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void BACK(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void LEFT(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void RIGHT(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

void STOP(){
  motor1.run(RELEASE);
  motor2.run(RELEASE); 
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void DISTANCE(){
   digitalWrite(trigPin,LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(2);
 digitalWrite(trigPin,LOW);

 duration = pulseIn(echoPin,HIGH);
 distanceCm = duration*0.034/2;
 Serial.println(distanceCm);

}
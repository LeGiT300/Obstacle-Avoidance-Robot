#include <Servo.h>
#include <AFMotor.h>

AF_DCMotor m1(1);
AF_DCMotor m2(1);
AF_DCMotor m3(1);
AF_DCMotor m4(1);

Servo motor;

float set = 0.125;
int trig = A0, echo = A1;

float distance_L, distance_F, distance_R;
long distance, duration;

void setup() {
  Serial.begin(9600);
  Serial.println("Start...");
  
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200);
}

void loop() {
  distance_F = data();
  Serial.print("S=");
  Serial.println(distance_F);

  if(distance_F > set){
    Serial.println("Forward...");
    m1.run(FORWARD);
    m2.run(FORWARD);
    m3.run(FORWARD);
    m4.run(FORWARD);
  }
  else{
    Stopping();
  }

}


/*
Collecting from the ultrasonic
*/
long data(){
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);

  distance = ((duration/1000000.)*343)/2;
  return distance;
}

/*
 * Testing conditions
 */
 
void compare(){
  if(distance_L > distance_R){
    m1.run(BACKWARD);   // turn it on going left
    m2.run(BACKWARD);
    m3.run(FORWARD); 
    m4.run(FORWARD); 
    delay(350);
  }

  else if (distance_R > distance_L){
  m1.run(FORWARD);  // the other right
  m2.run(FORWARD); 
  m3.run(BACKWARD); 
  m4.run(BACKWARD);
    delay(350);
  }
  else{
  m1.run(BACKWARD);  // the other way
  m2.run(BACKWARD);
  m3.run(BACKWARD); 
  m4.run(BACKWARD); 
   delay(300);
  m1.run(BACKWARD);   // turn it on going left
  m2.run(BACKWARD);
  m3.run(FORWARD); 
  m4.run(FORWARD); 
    delay(500);
  }
}
 /*
  * STOPING THE MOTOR AND VERIFYING CONDITIONS
  */
void Stopping(){
  Serial.println("Release...");

  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);

  motor.write(0);
  delay(300);
  distance_R = data();
  delay(100);
  motor.write(175);
  delay(500);
  distance_L = data();
  delay(100);
  motor.write(90);
  delay(300);
  compare();
}

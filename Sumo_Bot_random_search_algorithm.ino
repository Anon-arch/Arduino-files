#include <ATX2.h>
#include <NewPing.h>

#define TRIGGER_PIN  12
#define ECHO_PIN  13
#define MAX_DISTANCE 200
//define ultrasonic sensor config
NewPing sonarSensor(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
//declare motors
int Motor_1 = 3;
int Motor_2 = 4;
int Motor_3 = 5;
int Motor_4 = 6;
//declares IR pins
int irPin1 = 1;
int irPin2 = 2;
int irValue1, irValue2;

void setup() {
  //declare Motor Pins and ir sensors
  Serial.begin(9600);
}

void loop() 
{
  int distance = sonarSensor.ping_cm();
  irValue1 = analogRead(irPin1); 

//reads ultrasonic sensor distance in cm
  if (distance <= 20) {
    //make motors go at max speed and ignore line limits
  } 
  
  else
  {
    
  }
  //robot runs to white border
  //subject to change depending on IR placement
  if (irValue1 > 600 || irValue2 > 600) {
    //make robot stop
    delay(1000);
    //make motors go backward
    int randomNum = random(1, 4);
    if (randomNum == 1) {
      //make robot turn at random direction I.E 45 degrees
    } else if (randomNum == 2) {
      //make robot turn ar random direction I.R 30 degrees
    } else {
      //make robot do 180 degss
    }
  }
  delay(100);
}

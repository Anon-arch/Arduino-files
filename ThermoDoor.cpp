#include <LiquidCrystal.h> //library to use LCD
#include <Servo.h> //library to use Servo motor
Servo myServo;  //setting myServo as a servo variable
const int servo = 5;
const int trigPin = 3;    //trigger Pin
const int echoPin = 2;  // Echo Pin
const int buzzer = 6;

long duration; // variable for the duration of sound wave travel
int distance; // initializing variable for determining distance of object
int sensePin = A0;  //temp sensor
int sensorInput;    //store the sensor input
double temp;  
//                RS  E  D4 D5  D6 D7  (PIN CONNECTIONS FOR THE LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);  //declares lcd ports
void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speedpinMode(servo,OUTPUT);
  lcd.begin(16, 2); //turns on LCD panel
  myServo.attach(servo); //attaches servo to myServo
  myServo.write(0); //servo starts with 0 degrees angle
}
void loop()
{
  // This initalizes Ultrasonic Sensor 
  
 
  digitalWrite(trigPin, LOW); // Clears the trigPin condition
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  
  
  // This Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  
  
  if(distance <= 100)  //if sw is pressed temp sensor will be read
    
  {
    
    // This initializes and reads value of temperature sensor
  	sensorInput = analogRead(A0);        //read the analog sensor and store it
  	temp = (double)sensorInput / 1024;   //find percentage of input reading
  	temp = temp * 5;                     //multiply by 5V to get voltage
  	temp = temp - 0.5;                   //Subtract the offset 
  	temp = temp * 100;                   //Convert to degrees 
  
    
    // prints temperature on LCD panel
  	lcd.setCursor(0, 0);
  	lcd.print("Temp         C  ");
 
  	lcd.setCursor(6, 0);
  
  	lcd.print(temp);
  
  	delay(500);
  //if temp is less than 37 degrees door will open for 10 seconds then close again
  	if(temp <= 37.50)
  	{
    myServo.write(90);
    digitalWrite(buzzer,LOW);
  	}
  	else if(temp >= 37.55) // if temp is more than 37.5 degrees door will stay closed 
      						//and buzzer will make sound
  	{
    myServo.write(0);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
  	}
    
  }
  else if(distance > 100)
    {
      myServo.write(0);
      digitalWrite(buzzer,LOW);
    }
}
/**intructions for prototype
	1. start sim and set ult sensor to 100cm
    2. adjust temperature on TMP pin
   note: 
   temperature will only be read after ult sensor detects you within 1m
   **/



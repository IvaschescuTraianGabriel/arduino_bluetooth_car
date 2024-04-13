#include <Adafruit_MotorShield.h>

#include <AFMotor.h>

#include <SoftwareSerial.h>

#define buzzerPin 13
#define led1 16
#define led2 17
#define led3 18
#define led4 19

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command; 

boolean horn = false;

void setup() 
{       
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(buzzerPin,OUTPUT);
  
  Serial.begin(9600);  //Set the baud rate to the  Bluetooth module.
 
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    
if (horn) {digitalWrite(buzzerPin, HIGH);}
if (!horn) {digitalWrite(buzzerPin, LOW);}

    switch(command){
    case 'F':  
      forward();
      break;
    case 'G':
      forward_left();
      break;
    case 'I':
      forward_right();
      break;
    case 'B':  
       back();
      break;
    case 'H':
      back_left();
      break;
    case 'J':
      back_right();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
      break;
    case 'V':horn = true;
      firstSection();
      break;
    case 'v':horn = false;
      noMusic();
      break;
    case 'W':
      front_lights_on();
      break;
    case 'w':
      front_lights_off();
      break;
    case 'U':
      back_lights_on();
      break;
    case 'u':
      back_lights_off();
      break;
    }
  } 
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}

void forward_left()
{
  motor1.setSpeed(123);
  motor1.run(FORWARD);
  motor2.setSpeed(123);
  motor2.run(FORWARD);
  motor3.setSpeed(255);
  motor3.run(FORWARD);
  motor4.setSpeed(255);
  motor4.run(FORWARD);
}

void forward_right()
{
  motor1.setSpeed(255);
  motor1.run(FORWARD);
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(123);
  motor3.run(FORWARD);
  motor4.setSpeed(123);
  motor4.run(FORWARD);
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void back_left()
{
  motor1.setSpeed(123); //Define velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(123); //Define velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void back_right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(123); //Define set velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(123); //Define set velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}

void firstSection()
{

 beep(a, 500);
 beep(a, 500); 
 beep(a, 500);
 beep(f, 350);
 beep(cH, 150); 
 beep(a, 500);
 beep(f, 350);
 beep(cH, 150);
 beep(a, 650);
 
 delay(500);
 
 beep(eH, 500);
 beep(eH, 500);
 beep(eH, 500); 
 beep(fH, 350);
 beep(cH, 150);
 beep(gS, 500);
 beep(f, 350);
 beep(cH, 150);
 beep(a, 650);
 
 delay(500);

 beep(aH, 500);
 beep(a, 300);
 beep(a, 150);
 beep(aH, 500);
 beep(gSH, 325);
 beep(gH, 175);
 beep(fSH, 125);
 beep(fH, 125); 
 beep(fSH, 250);
 
 delay(325);
 
 beep(aS, 250);
 beep(dSH, 500);
 beep(dH, 325); 
 beep(cSH, 175); 
 beep(cH, 125); 
 beep(b, 125); 
 beep(cH, 250); 
 
 delay(350);
}

void beep(int note, int duration)
{
 //Play tone on buzzerPin
 tone(buzzerPin, note, duration);
 
}

void noMusic()
{
  noTone(buzzerPin);
}

void front_lights_on()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}

void front_lights_off()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
}

void back_lights_on()
{
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
}

void back_lights_off()
{
digitalWrite(led3,LOW);
digitalWrite(led4,LOW); 
}
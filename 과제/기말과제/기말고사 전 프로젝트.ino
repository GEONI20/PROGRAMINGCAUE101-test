#include <Servo.h>
//서보모터 동작을 위한 라이브러리

#define MINANALOG 0
#define MAXANALOG 1023
#define MINANG 0
#define MAXANG 180
#define nServopin 2
#define nSlideSwpin 3
#define nRedpin 4
#define nGreenpin 5
#define Servopin 0
#define SlideSwpin 1
#define Redpin 2
#define Greenpin 3

//핀들과 동작하는 구성요소를 이어놓은 배열
int nPinAry[4] = {nServopin,nSlideSwpin,nRedpin,nGreenpin};
int nPoterPin = A0;
int *pLED = nPinAry;
int Delay = 1000;
int Servo_Degree = 0;

Servo myServo;

//LED 핀을 동작시키기 위한 함수
void LEDPin_Function(int nNumpin, int nCmd, int nDelay)
{
  digitalWrite(nNumpin, nCmd);
  delay(nDelay);
}

//무게 센서를 작동시키기 위한 함수이지만 무게감지 센서를 찾지 못한 관계로 가변저항으로 대체
void Weightsensor_function()
{ 
  //가변저항의 아날로그 값을 읽어냄
  int readPotValue = analogRead(nPoterPin);
  //가변저항에서 가져온 값을 서보모터에서 쓸수 있는 각도의 범위로 치환
  int ServoAng = map(readPotValue, MINANALOG, MAXANALOG, MINANG, MAXANG);
 
  //가변저항값(무겟값)에 따라 서보모터의 각도 조정
  myServo.write(Servo_Degree);
  delay(Delay);
}

//기본 셋업
void setup()
{
  myServo.attach(nServopin);
  pinMode(nPinAry[Servopin], OUTPUT);
  pinMode(nPinAry[SlideSwpin], INPUT);
  pinMode(nPoterPin, INPUT);
  pinMode(nPinAry[Redpin], OUTPUT);
  pinMode(nPinAry[Greenpin], OUTPUT);
  
  Serial.begin(9600);
}


void loop()
{
  //슬라이드 스위치로 화장실 불을 키고끄는 것을 재현
  int readValue = digitalRead(nSlideSwpin);
  Serial.print("Switch : ");
  Serial.println(readValue);
  
  //가변저항의 아날로그 값을 읽어냄
  int readPotValue = analogRead(nPoterPin);
  //가변저항에서 가져온 값을 서보모터에서 쓸수 있는 각도의 범위로 치환
  int ServoAng = map(readPotValue, MINANALOG, MAXANALOG, MINANG, MAXANG);
  //가변저항값(무겟값)에 따라 서보모터의 각도 조정
  myServo.write(ServoAng);
  delay(Delay);  
 
  
  if(readValue == HIGH)//화장실 불이 켜졌을 때 작동하는 구간
  {
    //남아 있는 휴지가 20퍼센트 이상일 경우 초록불이 들어온다
    if(ServoAng <= 144)
    {
      LEDPin_Function(*(pLED+Greenpin),HIGH,1000);
      LEDPin_Function(*(pLED+Greenpin),LOW,10);
      LEDPin_Function(*(pLED+Redpin),LOW,10);
    }
    //남아 있는 휴지가 20퍼센트 이하 일 경우 빨간불이 들어온다
    else if(ServoAng < 175)
    {
      LEDPin_Function(*(pLED+Redpin),HIGH,1000);
      LEDPin_Function(*(pLED+Redpin),LOW,10);
      LEDPin_Function(*(pLED+Greenpin),LOW,10);
    }
    //휴지가 아예 없거나 거의 없는 경우 자동으로 휴지를 교체하고 무게 센서를 초기화 한다
    else if(ServoAng >= 175)
    {
      Servo_Degree = 0; 
    }
  }
  else//화장실 불이 꺼졌을때는 해당 프로그램도 작동을 멈춤
  {
    LEDPin_Function(nRedpin,LOW,Delay);
    LEDPin_Function(nGreenpin,LOW,Delay);
  }
}

































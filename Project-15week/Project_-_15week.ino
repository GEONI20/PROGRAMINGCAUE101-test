#include <Servo.h>

//매크로 지정
#define MINANALOG 0
#define MAXANALOG 1023
#define MINANG 0
#define MAXANG 180
#define nRedPin 2
#define nYellowPin 3
#define nGreenPin 4
#define nBluePin 5
#define RedPin 0
#define YellowPin 1
#define GreenPin 2
#define BluePin 3

//변수 설정(LED핀(배열), 가변저항, 서보모터)
int nPotenPin = A0;
int nServoPin = 6;
int nDelay = 100;

int nLEDPin[4] = {nRedPin, nYellowPin, nGreenPin, nBluePin};

Servo myServo;

//LED가 깜빡이게 하는 함수
void GenLEDDigitalOutput(int nNumpin, int nCmd, int nDelay) 
{
  digitalWrite(nNumpin, nCmd);
  delay(nDelay);
}
  
//INPUT, OUTPUT 설정
void setup()
{
  myServo.attach(nServoPin);//6번핀을 서보모터 제어에 사용
  pinMode(nLEDPin[RedPin],OUTPUT);
  pinMode(nLEDPin[YellowPin],OUTPUT);
  pinMode(nLEDPin[GreenPin],OUTPUT);
  pinMode(nLEDPin[BluePin],OUTPUT);
  Serial.begin(9600);
}

//가변저항으로 서보모터의 각도를 조절하고 그에 따라 LED가 깜빡이는 순서를 바꾸는 Loop
void loop()
{
  int nKnobservo = analogRead(nPotenPin);
  int nServoAng = map(nKnobservo, MINANALOG, MAXANALOG, MINANG, MAXANG);
  
 
  //빨강,노랑,초록,파랑 순서대로 깜박임
  if (((nServoAng) > 0) && ((nServoAng) <= 90))
  {
    
    if(nServoAng <= 90)//위에서 아래로 서보모터가 움직임
    {
    for(int i = 0; i <= 180; i++)
     {
         myServo.write(i);
     }
    }
    
    GenLEDDigitalOutput(nLEDPin[RedPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[RedPin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[YellowPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[YellowPin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[GreenPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[GreenPin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[BluePin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[BluePin], LOW, nDelay);
  }
    
    //파랑,초록,노랑,빨강 순서대로 깜박임
  else if (((nServoAng) > 90) && ((nServoAng) <= 180))
  {
    
     if((nServoAng > 90) && (nServoAng <= 180))//아래에서 위로 서보모터가 움직임
    {
    for(int i = 179; i > 0; i--)
    {
         myServo.write(i);
        }
    }
  
    GenLEDDigitalOutput(nLEDPin[BluePin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[BluePin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[GreenPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[GreenPin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[YellowPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[YellowPin], LOW, nDelay);
    
    GenLEDDigitalOutput(nLEDPin[RedPin], HIGH, nDelay);
    GenLEDDigitalOutput(nLEDPin[RedPin], LOW, nDelay);
  }
  
  else //예외처리구문(가변저항값이 0일경우)
  {
    GenLEDDigitalOutput(nRedPin, LOW, 0);
    GenLEDDigitalOutput(nYellowPin, LOW, 0);
    GenLEDDigitalOutput(nGreenPin, LOW, 0);
    GenLEDDigitalOutput(nBluePin, LOW, 0);
    
    myServo.write(0);
  }
  
 
  
  Serial.print("ServoAnalog : ");
  Serial.println(nKnobservo);
  Serial.print("ServoAng : ");
  Serial.println(nServoAng);
  
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

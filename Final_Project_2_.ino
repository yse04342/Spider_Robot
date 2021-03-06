#include <Servo.h> // 서모모터 헤더파일
#include <SoftwareSerial.h> //블루투스 모듈 사용 헤더파일

SoftwareSerial BTSerial(10,9); // 모듈 TX → 우노 RX (10번 핀), 모듈 RX → 우노 TX (9번 핀)
Servo servo1,servo2,servo3,servo4,servo5,servo6,servo7,servo8,servo9,servo10,servo11,servo12; // 서보모터 12개 설정
    int pos1 = 120; ////////1번모터
    int pos2 = 50;////////2번모터
    int pos3 = 70;////////3번모터
    int pos4 = 100;    ////////4번모터
    int pos5 = 40; //////////////////////// 7번 모터
    int pos6 = 130;//////////////////////// 5번 모터
    int pos7 = 100;///////////////////////// 8번 모터
    int pos8 = 30;//////////////////////////6번 모터
    int pos9 = 60;
    int pos10 = 120;
    void Write();
void setup() 
{
  Serial.begin(9600);// 시리얼통신 보레이트 설정
  BTSerial.begin(9600);// 블루투스 모듈 보레이트 설정
  BTSerial.println("Let's start");
  //////////////////핀 설정 /////////////./////////////////////////////////////
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13); // 8번 모터
  servo6.attach(8);
  servo7.attach(7);
  servo8.attach(6); 
  servo9.attach(5); 
  servo10.attach(4); 
  servo11.attach(3);
  servo12.attach(2); // 1번 모터
  ////////////////////////////////////////////
  servo3.write(pos9);
  servo4.write(pos10);
///////////////////////////////////////////
  servo9.write(pos3);
  servo10.write(pos4);
  servo11.write(pos1);
  servo12.write(pos2);
  /////////////////////////////////////////////////////////////
  servo5.write(pos7);
  servo6.write(pos8);
  servo7.write(pos6);
  servo8.write(pos5);
}
void  Write() // 모터값 읽는 함수
{
  servo3.write(pos9);
  servo4.write(pos10);
  servo5.write(pos7);
  servo6.write(pos8);
  servo7.write(pos6);
  servo8.write(pos5);
  servo9.write(pos3);
  servo10.write(pos4);
  servo11.write(pos1);
  servo12.write(pos2);
}

void loop() 
{
    if(BTSerial.available()) // 블루투스 모듈의 시리얼 창을 열어야 된다.(일반 시리얼 창을 열려면 앞에 BT를 빼면 된다.
    {
      while(1)
      {
      char key = BTSerial.read(); // 블루투스 모듈의 시리얼 값을 읽어 드린다.
      Serial.println(key);
      if(key=='w') //일어섰을때
      {
        pos5 = 130,
        pos6 = 40,
        pos7 = 10,
        pos8 = 130,
        pos9 = 150,
        pos10= 30;
        Write();
      }
      else if(key=='s') // 초기상태(앉기)
      {
      pos1 = 120,pos2 = 50,pos3 = 70,pos4 = 100,pos5 = 40,pos6 = 130,pos7 = 100,pos8 = 30,pos9=60,pos10=120;
      }
      ////////////////////////////////////////////////////////////////////////
      else if(key=='J') // 입력값은 대문자 J로 앞으로 전진을 하는 모션
      {
        ////////////////////////////////////////////大자 모양/////////////////////////////////////////////////
        pos1 = 120,pos2 = 50,pos3 = 70,pos4 = 100,pos9=160,pos10=30;
        Write();
        delay(250);
        ///////////////////////////////////////////1번동작///////////////////////////////////////////////
        pos5 = 40,pos9=150,pos10=30;
        Write();
        delay(250);       
        pos1 = 120,pos2 = 50,pos3 = 70,pos4 = 70,pos9=150,pos10=30;
        Write();
        delay(250);
        pos5 = 130,pos9=150,pos10=30;
        Write();
        delay(250);
        ///////////////////////////////////////////2번동작///////////////////////////////////////////////
        pos7 = 100,pos9=150,pos10=30;
        Write();
        delay(250);
        pos1 = 120,pos2 = 50,pos3 = 100,pos4 = 100,pos9=150,pos10=30;
        Write();
        delay(250);
        pos7 = 10,pos9=150,pos10=30;
        Write();
        delay(250);
        ///////////////////////////////////////////3번동작///////////////////////////////////////////////
        pos6 = 130,pos9=150,pos10=30;
        Write();
        delay(250);
        pos1 = 120,pos2 = 70,pos3 = 70,pos4 = 100,pos9=150,pos10=30;
        Write();
        delay(250);
        pos6 = 40,pos9=150,pos10=30;
        Write();
        delay(250);
        ///////////////////////////////////////////4번동작////////////////////////////////////////////////
        pos8 = 30,pos9=150,pos10=30;
        Write();
        delay(250);
        pos1 = 100,pos2 = 50,pos3 = 70,pos4 = 100,pos9=150,pos10=30;
        Write();
        delay(250);
        pos8 = 130,pos9=150,pos10=30;
        Write();
        delay(250);
        ///////////////////////////////////////////초기 일어섬 동작///////////////////////////////////////
        pos1 = 120,pos2 = 50,pos3 = 70,pos4 = 100,pos5 = 130,pos6 = 40,pos7 = 10,pos8 = 130;
        Write();
        delay(250);
      }
      ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      else if(key=='H') // 입력값은 대문자 H이며 로봇이 인사(?)하는 모션
      {
        for(int i=0; i<5; i++)
        {
          pos1 = 120,pos2 = 50,pos3 = 70,pos4 = 100;
          pos5 = 30,pos6 = 150,pos7 = 110,pos8 = 10;
          Write();
          delay(250);
          pos1 = 150,pos2 = 30,pos3 = 40,pos4 = 120,
          pos5 = 40,pos6 = 130,pos7 = 90,pos8 = 30;
          Write();
          delay(250);
        }
      }
      Write();      
      }
    }
}

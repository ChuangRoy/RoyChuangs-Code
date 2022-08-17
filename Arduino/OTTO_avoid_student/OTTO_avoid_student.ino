//----------------------------------------------------------------
//-- Otto basic firmware v2 adapted from Zowi (ottobot.org)
//-- CC BY SA
//-- 04 December 2016
//-----------------------------------------------------------------
//-- Otto will avoid obstacles with this code!
//-----------------------------------------------------------------
//引進函式庫 
#include <Servo.h> //馬達需要的
#include <Oscillator>
#include <US.h> //電路板連接
#include <Otto.h> //otto機器人
Otto Otto;  //宣告 資料型態 變數(otto)
//---------------------------------------------------------
//-- First step: Make sure the pins for servos are in the right position
/*
         --------------- 
        |     O   O     |
        |---------------|
YR 3==> |               | <== YL 2
         --------------- 
            ||     ||
RR 5==>   -----   ------  <== RL 4
         |-----   ------|
*/
//定義 servo為pin值

  #define PIN_YL 2 //servo[0]
  #define PIN_YR 3 //servo[1]
  #define PIN_RL 4 //servo[2]
  #define PIN_RR 5 //servo[3]

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
//-- Movement parameters
int T=1000;              
int moveId=0;            //Number of movement
int moveSize=15;         //Asociated with the height of some movements
//---------------------------------------------------------
bool obstacleDetected = false;//障礙物偵測預設關閉(bool)
///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup(){
  Serial.begin(9600);
  //Set the servo pins
  Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);//初始化四個servo為true 
  Otto.sing(S_connection); 
  //Otto休息模式
  ?
  delay(500);//delay0.05秒
  Otto.sing(S_happy);
  obstacleDetector()
}
///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
//如果障礙物偵測不等於0，就唱歌跳舞

void loop() {
  if(obstacleDetected){ 
               Otto.sing(S_surprise); 
               Otto.playGesture(OttoFretful); 
               Otto.sing(S_fart3); 
               Otto.walk(?); //往後走五步，持續1.3秒
               Otto.turn(?);//往右走兩步，持續1秒(左1右-1)                
               delay(時間);//0.05秒 
             //繼續偵測障礙物
             ?
             }        
         else{ 
            Otto.walk(?); //往前走兩步，持續1秒
            //繼續偵測障礙物
            ?
        }           
  }  

///////////////////////////////////////////////////////////////////
//-- Function to read distance sensor & to actualize obstacleDetected variable
//無須回傳
void obstacleDetector(){
   int distance = Otto.getDistance();
          //序列埠印出距離
         Serial.begin(9600)
         Serial.print("Distance is :")
         Serial.println(distance)
        //if-else 若距離小於5，偵測障礙物開啟，否則關閉。
        if (distance < 5)
            obstacleDetected = true;
        else
            obstacleDetected = false;
}

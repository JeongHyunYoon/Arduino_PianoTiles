#include <Servo.h>

Servo servo1; //빨간색
Servo servo2; //노란색


void setup() {
 servo1.attach(4); //servo1.write(10);
 servo2.attach(5); //servo2.write(10);
 Serial.begin(9600);
}

void loop() {
   int delay0_1 = 200;
   int delay1_1 = 85; //hit
   int delay2_1 = 40;  //init
   
   int delay0_2 = 175;
   int delay1_2 = 85; //hit
   int delay2_2 = 40;  //init
   
   int angle_init_1 = 125;       //올라갔을 때 모터 각도
   int angle_hit_1 = 100;        //터치할 때 모터 각도
   
   int angle_init_2 = 120;       
   int angle_hit_2 = 100;        //터치
   
   servo1.write(angle_init_1);
   servo2.write(angle_init_2);
   int a= analogRead(A4);
   Serial.println(a);
   delay(20);
   if(analogRead(A4)<=15)
   {
    delay(delay0_1);
//    servo1.write(angle_init_1);
//    delay(delay2_1);
    servo1.write(angle_hit_1);
    delay(delay1_1);
    servo1.write(angle_init_1);
    delay(delay2_1);
   }
   if(analogRead(A5)<=15)
   {    
    delay(delay0_2);
//    servo2.write(angle_init_2);
//    delay(delay2_2);
    servo2.write(angle_hit_2);
    delay(delay1_2);
    servo2.write(angle_init_2);
    delay(delay2_2);
   }
   char stop = Serial.read();
   if(stop == '0')            //Serial에 0 입력하면 모터 초기 각도로 되돌리고, 모두 멈춤
   {
    servo1.write(angle_init_1);
    servo2.write(angle_init_2);
    delay(1000);
    servo1.detach();
    servo2.detach();
   }
}

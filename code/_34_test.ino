#include <Servo.h>

Servo servo3; //초록색
Servo servo4; //파란색


void setup() {
 servo3.attach(4); //servo3.write(10);
 servo4.attach(5); //servo4.write(10);
 Serial.begin(9600);
}

void loop() {
   int delay0_3 = 175;
   int delay1_3 = 85; //hit
   int delay2_3 = 40;  //init
   
   int delay0_4 = 120;
   int delay1_4 = 85; //hit
   int delay2_4 = 40;  //init
   
   int angle_init_3 = 125;       //올라갔을 때 모터 각도
   int angle_hit_3 = 95;        //터치할 때 모터 각도
   
   int angle_init_4 = 110;       
   int angle_hit_4 = 95;        //터치
   
   servo3.write(angle_init_3);
   servo4.write(angle_init_4);
//   int a= analogRead(A5);
//   Serial.println(a);
   delay(20);
   if(analogRead(A4)<=15)
   {
    delay(delay0_3);
    servo3.write(angle_hit_3);
    delay(delay1_3);
    servo3.write(angle_init_3);
    delay(delay2_3);
   }
   if(analogRead(A5)<=9)
   {    
    delay(delay0_4);
    servo4.write(angle_hit_4); Serial.println("hit");
    delay(delay1_4);
    servo4.write(angle_init_4);
    delay(delay2_4);
   }
   char stop = Serial.read();
   if(stop == '0')            //Serial에 0 입력하면 모터 초기 각도로 되돌리고, 모두 멈춤
   {
    servo3.write(angle_init_3);
    servo4.write(angle_init_4);
    delay(1000);
    servo3.detach();
    servo4.detach();
   }
}

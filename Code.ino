#include <Servo.h>// 声明调用Servo.h库
Servo myservo[5];// 创建一个舵机对象
Servo myservo2;// 创建一个舵机对象
Servo myservo3;// 创建一个舵机对象
Servo myservo4;// 创建一个舵机对象
Servo myservo5;// 创建一个舵机对象
int pos = 0;// 变量pos用来存储舵机位置

int potpins[] = {A0, A1, A2, A3, A4};// 连接到模拟口0
int potpin2 = A1;// 连接到模拟口1
int potpin3 = A2;// 连接到模拟口2
int potpin4 = A3;// 连接到模拟口3
int potpin5 = A4;// 连接到模拟口4

int servopins[] = {9, 10, 11, 12, 13};// 连接到模拟口0

int vals[5];//变量val用来存储从模拟口0读到的值
int val2;//变量val用来存储从模拟口1读到的值
int val3;//变量val用来存储从模拟口2读到的值
int val4;//变量val用来存储从模拟口3读到的值
int val5;//变量val用来存储从模拟口4读到的值

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 5; i++) {
    myservo[i].attach(servopins[i]);// 将引脚9上的舵机与声明的舵机对象连接起来
  }
/*myservo2.attach(10);// 将引脚10上的舵机与声明的舵机对象连接起来
myservo3.attach(11);// 将引脚11上的舵机与声明的舵机对象连接起来
myservo4.attach(12);// 将引脚12上的舵机与声明的舵机对象连接起来
myservo5.attach(13);// 将引脚13上的舵机与声明的舵机对象连接起来
*/
}

void loop() {

  for(int i = 0; i < 5; i++) {
    vals[i] = analogRead(potpins[i]);//从模拟口0读值，并通过val记录

    switch(i) {
      case 0: {
        vals[i] = map(vals[i], 400, 1023, 0, 179);//通过map函数进行数值转换
        break;
      }
      case 1: {
        vals[i] = map(vals[i], 0, 600, 0, 179);//通过map函数进行数值转换
        break;
      }
      case 2: {
        vals[i] = map(vals[i], 0, 600, 0, 179);//通过map函数进行数值转换
        break;
      }
      case 3: {
        vals[i] = map(vals[i], 200, 800, 0, 179);//通过map函数进行数值转换
        break;
      }
      case 4: {
        vals[i] = map(vals[i], 0, 800, 0, 179);//通过map函数进行数值转换
        break;
      }
    }
    
    Serial.println(vals[i]);
    myservo[i].write(vals[i]);// 给舵机写入角度 
    pos = vals[i];
  }

  delay(15);// 延时15ms让舵机转到指定位置

/*
myservo.write(90);// 给舵机写入角度 
delay(1000);// 延时15ms让舵机转到指定位置
myservo.write(pos);// 给舵机写入角度 
delay(1000);// 延时15ms让舵机转到指定位置
*/
}

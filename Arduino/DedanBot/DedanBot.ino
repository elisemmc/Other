#include <Servo.h>

Servo servoLeft;
Servo servoRight;
Servo servoGun;
  
void setup() {
  // put your setup code here, to run once:

  servoLeft.attach(11);
  servoRight.attach(12);
  servoGun.attach(10);

  stop();
  delay(5000);

  forward();
  delay(3500);

  leftTurn();
  delay(1265);

  forward();
  delay(6700);

  rightTurn();
  delay(1360);

  forward();
  delay(5900);

  rightTurn();
  delay(1500);

  forward();
  delay(6060);

  leftTurn();
  delay(1400);

  forward();
  delay(3900);

  leftTurn();
  delay(1500);

  forward();
  delay(7500);
  
  servoLeft.detach();
  servoRight.detach();
  servoGun.detach();
}

void forward()
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1675);
}

void rightTurn()
{
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
}

void leftTurn()
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
}

void backward()
{
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
}

void stop()
{
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void gunUp()
{
  servoGun.writeMicroseconds(2300);
  //servoGun.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:

}

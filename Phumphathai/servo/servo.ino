#include <Servo.h>
Servo servoPan;
Servo servoTilt;
void setup()
{
  Serial.begin(115200);
  servoPan.attach(7);
  servoTilt.attach(8);
  
  servoTilt.write(70);
  servoPan.write(70);
}
void loop()
{
  if (Serial.available()) {
    char in = Serial.read();
    if (in == 'a') {
      servoTilt.write(71);
      servoPan.write(47);
    } else if (in == 'b') {
      servoTilt.write(66);
      servoPan.write(91);
    } else if (in == 'c') {
      servoTilt.write(70);
      servoPan.write(145);
    } else if (in == 't') {
      int num = Serial.parseInt();
      servoTilt.write(num);
    } else if (in == 'p') {
      int num = Serial.parseInt();
      servoPan.write(num);
    }
  }
}

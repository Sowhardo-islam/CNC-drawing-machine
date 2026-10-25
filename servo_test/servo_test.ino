#include <AFMotor.h>
#include <Servo.h>

AF_Stepper motory(48, 1);
AF_Stepper motorx(48, 2);

#define penup 90
#define pendown 110


Servo servo;
void setup() {
  servo.attach(9);
  motorx.setSpeed(400);
  motory.setSpeed(400);
  servo.write(penup);
  delay(1000);
}
void loop() {
    servo.write(pendown);
    delay(1000);
    motorx.step(164, FORWARD, MICROSTEP);
    motory.step(250, FORWARD, MICROSTEP);
    motorx.step(164, BACKWARD, MICROSTEP);
    motory.step(250, BACKWARD, MICROSTEP);
    servo.write(penup);
    delay(1000);
}

void ser() {
  servo.write(160);
  delay(1000);
  servo.write(130);
  delay(1000);
}

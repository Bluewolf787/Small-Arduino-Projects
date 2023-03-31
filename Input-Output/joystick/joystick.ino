#include "Joystick.h"
#include "AxisJoystick.h"

#define SW_PIN 2
#define VRX_PIN A0
#define VRY_PIN A1

Joystick* joystick;

void setup() {
  Serial.begin(9600);
  
  joystick = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
}

void loop() {
  Serial.print("Joystick single reading: ");
  Serial.println(moveDirection(joystick->singleRead()));
  delay(500);
}

String moveDirection(const Joystick::Move move) {
  switch (move) {
    case Joystick::Move::NOT:
      return "NOT";
    case Joystick::Move::PRESS:
      return "PRESS";
    case Joystick::Move::UP:
      return "UP";
    case Joystick::Move::DOWN:
      return "DOWN";
    case Joystick::Move::RIGHT:
      return "RIGHT";
    case Joystick::Move::LEFT:
      return "LEFT";
    default:
      return "???";
  }
}

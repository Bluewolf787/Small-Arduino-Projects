#include "Joystick.h"
#include "AxisJoystick.h"
#include "LedControl.h"

#define SW_PIN 2
#define VRX_PIN A0
#define VRY_PIN A1

Joystick* joystick;

#define DIN_PIN 12
#define CLK_PIN 11
#define CS_PIN 10

LedControl lc = LedControl(12, 11, 10, 1);

int rowPlayer;
int colPlayer;
int rowTarget;
int colTarget;

bool finished = false;

void setup() {
  joystick = new AxisJoystick(SW_PIN, VRX_PIN, VRY_PIN);
  lc.shutdown(0, false);
  lc.setIntensity(0, 0.5);
}

void loop() {
  finished = false;
  lc.clearDisplay(0);

  rowPlayer = (int)random(8);
  colPlayer = (int)random(8);
  rowTarget = (int)random(8);
  rowTarget = (int)random(8);

  lc.setLed(0, rowPlayer, colPlayer, true);
  lc.setLed(0, rowTarget, colTarget, true);

  while (!finished) {
    movePlayer(joystick->singleRead());
    lc.setLed(0, rowPlayer, colPlayer, true);
    if (rowPlayer == rowTarget && colPlayer == colTarget) {
      finished = true;
    }
  }
}

void movePlayer(const Joystick::Move move) {
  lc.setLed(0, rowPlayer, colPlayer, false);
  switch (move) {
    case Joystick::Move::NOT:
      break;
    case Joystick::Move::PRESS:
      break;
    case Joystick::Move::UP:
      rowPlayer++;
      if (colPlayer > 7) {
        colPlayer = 0;
      }
      break;
    case Joystick::Move::DOWN:
      rowPlayer--;
      if (colPlayer < 0) {
        colPlayer = 7;
      }
      break;
    case Joystick::Move::RIGHT:
      colPlayer--;
      if (rowPlayer < 0) {
        rowPlayer = 7;
      }
      break;
    case Joystick::Move::LEFT:
      colPlayer++;
      if (rowPlayer > 7) {
        rowPlayer = 0;
      }
      break;
    default:
      break;
  }
}

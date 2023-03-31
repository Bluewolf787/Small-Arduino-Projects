#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

int row;
int col;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 0.5);
}

void loop() {
  lc.clearDisplay(0);

  delay(500);

  row = (int)random(8);
  col = (int)random(8);

  lc.setLed(0, row, col, true);

  delay(1000);
}

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
int intTemp;

int pin13 = 13;
int pin12 = 12;
int pin11 = 11;
int pin10 = 10;
int pin9 = 9;

void errorLed() {
  for (int i = 1; i <= 10; i++) {
    if (i == 1 || i == 10) {
      digitalWrite(pin13, HIGH);
    } else {
      digitalWrite(pin13, LOW);
    }

    if (i == 2 || i == 9) {
      digitalWrite(pin12, HIGH);
    } else {
      digitalWrite(pin12, LOW);
    }

    if (i == 3 || i == 8) {
      digitalWrite(pin11, HIGH);
    } else {
      digitalWrite(pin11, LOW);
    }

    if (i == 4 || i == 7) {
      digitalWrite(pin10, HIGH);
    } else {
      digitalWrite(pin10, LOW);
    }

    if (i == 5 || i == 6) {
      digitalWrite(pin9, HIGH);
    } else {
      digitalWrite(pin9, LOW);
    }
    delay(100);
  }
}

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(pin13, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);
}

void loop() {
  delay(2000);

  temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read Sensor data!");
    errorLed();
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C\n");

  intTemp = (int)temp;

  if (intTemp % 2 > 0) {
    digitalWrite(pin13, HIGH);
  } else {
    digitalWrite(pin13, LOW);
  }

  if (intTemp % 4 > 1) {
    digitalWrite(pin12, HIGH);
  } else {
    digitalWrite(pin12, LOW);
  }

  if (intTemp % 8 > 3) {
    digitalWrite(pin11, HIGH);
  } else {
    digitalWrite(pin11, LOW);
  }

  if (intTemp % 16 > 7) {
    digitalWrite(pin10, HIGH);
  } else {
    digitalWrite(pin10, LOW);
  }

  if (intTemp % 32 > 15) {
    digitalWrite(pin9, HIGH);
  } else {
    digitalWrite(pin9, LOW);
  }
}

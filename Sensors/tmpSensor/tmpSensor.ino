#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

float humidity = 0.0;
float temp = 0.0;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);

  humidity = dht.readHumidity();
  temp = dht.readTemperature();

  if (isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read Sensor data!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("% Temperature: ");
  Serial.print(temp);
  Serial.print("°C");
  Serial.println("");
}

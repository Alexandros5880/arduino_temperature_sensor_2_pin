#include"temperature.h"

Thermometer * temp;
uint16_t rezistor = 10000;
uint16_t num_samples = 333;
byte sensor_pin = A0;

void setup() {
  temp = new Thermometer(sensor_pin, num_samples, rezistor);
}

void loop() {
  float celcius = temp->getCelcius();
  float fahrenheit = temp->getFahrenheit(celcius);

  Serial.print("Temperature:    ");
  Serial.print(celcius);
  Serial.print(" *C,    ");
  Serial.print(fahrenheit);
  Serial.println(" *F");
}


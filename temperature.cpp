#include "temperature.h"

Thermometer::Thermometer() {
  Serial.begin(this->serial_frequency);
  analogReference(DEFAULT);
}

Thermometer::Thermometer(byte & pin) {
  this->sensor_pin = pin;
  Serial.begin(this->serial_frequency);
  analogReference(DEFAULT);
}

Thermometer::Thermometer(byte & pin, uint16_t & num_samples) {
  this->sensor_pin = pin;
  this->num_samples = num_samples;
  Serial.begin(this->serial_frequency);
  analogReference(DEFAULT);
}

Thermometer::Thermometer(byte & pin, uint16_t & num_samples, uint16_t &  rezistor) {
  this->sensor_rezistor = rezistor;
  this->num_samples = num_samples;
  this->sensor_pin = pin;
  Serial.begin(this->serial_frequency);
  analogReference(DEFAULT);
}

void Thermometer::getAvgOfSumples(float * average) {
  *average = 0;
  uint64_t i;
  for (i=0; i< this->num_samples; i++) {
    *average += analogRead(this->sensor_pin);
  }
  *average /= num_samples;
}

void Thermometer::convertToRezistanceValue(float * average) {
  *average = 1023 / *average - 1;
  *average = this->sensor_rezistor / *average;
}

float Thermometer::getCelcius() {
  float average;
  this->getAvgOfSumples(&average);
  this->convertToRezistanceValue(&average);
  float celsius;
  celsius = average / this->thermistor_nomimal; // (R/Ro)
  celsius = log(celsius); // ln(R/Ro)
  celsius /= this->bcoefficient; // 1/B * ln(R/Ro)
  celsius += 1.0 / (this->temperature_nomimal + 273.15); // + (1/To)
  celsius = 1.0 / celsius; // Invert
  celsius -= 273.15; // convert to C
  celsius -= 0.4;
  return roud(celsius*10)/10;
}

float Thermometer::getFahrenheit(float & celsius) {
  float fahrenheit;
  fahrenheit = (celsius*9/5)+32;
  return fahrenheit;
}

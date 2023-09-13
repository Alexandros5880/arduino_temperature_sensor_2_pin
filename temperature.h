#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <cmath>

#include "Arduino.h"

/// @brief Has 4 Constructors
/// @param Empty
/// @param uint16_t & pin
/// @param uint16_t & pin, uint16_t & num_samples
/// @param uint16_t & pin, uint16_t & num_samples, byte & rezistor
class Thermometer {
  private:
    uint16_t sensor_rezistor=10000, num_samples=1000;
    // resistance at 25 degrees C  ,  temp. for nominal resistance (almost always 25 C)
    uint16_t thermistor_nomimal=10000, temperature_nomimal=25;
    // The beta coefficient of the thermistor (usually 3000-4000)
    uint16_t bcoefficient=3950;
    uint16_t serial_frequency=9600;
    byte sensor_pin=A0;
    void getAvgOfSumples(float *);
    void convertToRezistanceValue(float *);
  public:
    /// @brief  Method Required for both celsius and fahrenheit
    /// @return float celsius
    float getCelcius();
    /// @brief Before this method is required to run getCelcius() and pass as parameter the return celsius value.
    /// @return float fahrenheit
    float getFahrenheit(float & celsius);
    Thermometer();
    Thermometer(byte &);
    Thermometer(byte &, uint16_t &);
    Thermometer(byte &, uint16_t &, uint16_t &);
};

#endif

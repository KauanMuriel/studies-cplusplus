#include <iostream>
#include "../include/TemperatureConverter.hpp"

void DisplayValues(double kelvin, double fahrenheit, double celsius);

void TemperatureConverter::ShowInDifferentUnities(MeasurementUnit from, double temperature) {
    double kelvin, fahrenheit, celsius;
    switch (from) {
        case MeasurementUnit::Kelvin:
            kelvin = temperature;
            fahrenheit = (temperature - 273.15) * 1.8 + 32;
            celsius = temperature - 273.15;
            break;
        case MeasurementUnit::Fahrenheit:
            kelvin = (temperature - 32) * 5/9 + 273.15;
            fahrenheit = temperature;
            celsius = (temperature - 32) / 1.8;
            break;
        case MeasurementUnit::Celsius:
            kelvin = temperature + 273.15;
            fahrenheit = temperature * 1.8 + 32;
            celsius = temperature;
            break;
        default:
            std::cout << "The unit of measurement is invalid for conversion.";
            exit(EXIT_FAILURE);
    }
    DisplayValues(kelvin, fahrenheit, celsius);
}

void DisplayValues(double kelvin, double fahrenheit, double celsius) {
    std::cout << "Kelvin: " << kelvin << "K\n";
    std::cout << "Fahrenheit " << fahrenheit << "°F\n";
    std::cout << "Celsius: " << celsius << "°C\n";
}
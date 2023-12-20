#include <cstdlib>
#include <iostream>
#include "../include/MeasurementUnit.hpp"
#include "../include/TemperatureConverter.hpp"

int main() {
    TemperatureConverter converter;
    converter.ShowInDifferentUnities(MeasurementUnit::Fahrenheit, 32);
    return 0;
}
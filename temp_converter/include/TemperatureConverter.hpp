#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H
#include "MeasurementUnit.hpp"

class TemperatureConverter {
    public:
        void ShowInDifferentUnities(MeasurementUnit from, double temperature);
};

#endif
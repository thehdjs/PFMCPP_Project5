#include "LeakedObjectDetector.h"
#pragma once

struct Light
{
    int temperature = 2500;
    int luminosity {1000};
    int electricalConsumption {500};
    float size, price;

    Light();
    
    ~Light();
    
    bool turnOn();
   
    void setTheMood();

    float addedQuality();

    float fade(float intensity);
    
    void costOfLight();

    JUCE_LEAK_DETECTOR(Light)
};

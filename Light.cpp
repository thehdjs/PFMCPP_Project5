#include "Light.h"
#include <iostream>

Light::Light()
{
    size = 25.3f;
    price = 1000;
}

Light::~Light()
{
    std::cout << "a Light is being destroyed\n";
}
bool Light::turnOn()
{
    return true;
}

void Light::setTheMood()
{
    luminosity /= 3;
    temperature = 1000;
    electricalConsumption /= 2;
}

float Light::fade(float intensity)
{
    while (luminosity < intensity)
    {
        luminosity ++;
        std::cout << "incrementing luminosity\ncurrent level: " << luminosity << " target: " << intensity << "\n";
        if (luminosity >= intensity) 
        {
            std::cout << "fade finished\n";
            return 100;
        }   
    }
    return luminosity;
}

void Light::costOfLight()
{
    std::cout << "this Light costs " << this->price << " schmeckels\n";
}

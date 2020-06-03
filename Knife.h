#include "LeakedObjectDetector.h"

#pragma once

struct Knife
{
    float pointiness, sharpness, thickness, price;
    unsigned int length;
    struct Incision
    {
        float depth, length;
        
        Incision();

        float getHurtLevel();
    };

    Knife();

    ~Knife();
    
    void cut(Incision prettyNastyCut);
  
    void stab();
    
    void unscrew();

    void costOfKnife();

    JUCE_LEAK_DETECTOR(Knife)
};

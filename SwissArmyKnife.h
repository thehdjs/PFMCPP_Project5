#pragma once
#include "LeakedObjectDetector.h"
#include "Knife.h"
struct SwissArmyKnife
{
   
    float weight, size, price;
    int numberOfCuttingTools, numberOfGrabbingTools;

    SwissArmyKnife();

    ~SwissArmyKnife();

    void cut(Knife::Incision aNewCut);

    void open();
   
    void unscrew();

    JUCE_LEAK_DETECTOR(SwissArmyKnife)
};

#include "LeakedObjectDetector.h"
#include "Knife.h"
#include "SwissArmyKnife.h"

#pragma once

struct KnifeShop
{
    Knife regularKnife;
    SwissArmyKnife leatherman;

    KnifeShop() {}
    
    ~KnifeShop();

    void sell();

    bool isOpen ();

    JUCE_LEAK_DETECTOR(KnifeShop)
};

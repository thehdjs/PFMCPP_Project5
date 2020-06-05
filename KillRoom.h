#include "Light.h"
#include "Knife.h"
#include "LeakedObjectDetector.h"

#pragma once

struct KillRoom
{
    Knife butchersKnife;
    Light neon;

    KillRoom(){}

    ~KillRoom();

    void getCleaned();

    JUCE_LEAK_DETECTOR(KillRoom)
};

#include "SwissArmyKnife.h"
#include <iostream>

SwissArmyKnife::SwissArmyKnife() : 
weight (351.3f),
size (100),
price (59.99f),
numberOfCuttingTools (3),
numberOfGrabbingTools (2)
{}

SwissArmyKnife::~SwissArmyKnife()
{
    std::cout << "a SwissArmyKnife is being destroyed\n";
}
void SwissArmyKnife::cut(Knife::Incision aNewCut)
{
    aNewCut.getHurtLevel();
    std::cout << "cut pain level: " << aNewCut.getHurtLevel() << "\n";
}

void SwissArmyKnife::open()
{
    std::cout << "#/cutting tools: " << numberOfCuttingTools << "\n";
    std::cout << "size: " << size << "\n";
}

void SwissArmyKnife::unscrew()
{
    std::cout << "#/grabbing tools: " << numberOfGrabbingTools << "\n";
    std::cout << "size: " << size << "\n";
}

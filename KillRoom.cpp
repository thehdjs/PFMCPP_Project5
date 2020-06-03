#include "KillRoom.h"
#include<iostream>

KillRoom::~KillRoom()
{
   getCleaned();
    std::cout << "exiting Killroom\n";
}
void KillRoom::getCleaned()
{
    std::cout << "KillRoom is getting cleaned\n";
    neon.fade(1005);
}

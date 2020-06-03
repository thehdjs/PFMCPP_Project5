#include "Wrappers.h"

KnifeWrapper(Knife* knifePtr) : ptrToaKnife (knifePtr) {}
~KnifeWrapper()
{
    delete ptrToaKnife;
}

LightWrapper(Light* lightPtr) : ptrToaLight(lightPtr) {}
~LightWrapper() 
{
    delete ptrToaLight;
}

SwissArmyKnifeWrapper(SwissArmyKnife* swissArmyKnifePtr) : ptrToaSwissArmyKnife(swissArmyKnifePtr) {}
~SwissArmyKnifeWrapper()
{
    delete ptrToaSwissArmyKnife;
}

KnifeShopWrapper(KnifeShop* knifeShopPtr) : ptrToaKnifeShop(knifeShopPtr) {}
~KnifeShopWrapper() 
{
    delete ptrToaKnifeShop;
}

KillRoomWrapper(KillRoom* killRoomPtr) : ptrToaKillRoom (killRoomPtr) {}
~KillRoomWrapper()
{
    delete ptrToaKillRoom;
}

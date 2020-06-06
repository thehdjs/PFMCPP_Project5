#include "Knife.h"
#include "Light.h"
#include "SwissArmyKnife.h"
#include "KnifeShop.h"
#include "KillRoom.h"
#include "Wrappers.h"

KnifeWrapper::KnifeWrapper(Knife* knifePtr) : ptrToaKnife(knifePtr)  {}
KnifeWrapper::~KnifeWrapper()
{
    delete ptrToaKnife;
}

LightWrapper::LightWrapper(Light* lightPtr) : ptrToaLight(lightPtr) {}
LightWrapper::~LightWrapper() 
{
    delete ptrToaLight;
}

SwissArmyKnifeWrapper::SwissArmyKnifeWrapper(SwissArmyKnife* swissArmyKnifePtr) : ptrToaSwissArmyKnife(swissArmyKnifePtr) {}
SwissArmyKnifeWrapper::~SwissArmyKnifeWrapper()
{
    delete ptrToaSwissArmyKnife;
}

KnifeShopWrapper::KnifeShopWrapper(KnifeShop* knifeShopPtr) : ptrToaKnifeShop(knifeShopPtr) {}
KnifeShopWrapper::~KnifeShopWrapper() 
{
    delete ptrToaKnifeShop;
}

KillRoomWrapper::KillRoomWrapper(KillRoom* killRoomPtr) : ptrToaKillRoom (killRoomPtr) {}
KillRoomWrapper::~KillRoomWrapper()
{
    delete ptrToaKillRoom;
}

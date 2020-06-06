struct Knife;
struct Light;
struct SwissArmyKnife;
struct KnifeShop;
struct KillRoom;

struct KnifeWrapper
{
  KnifeWrapper(Knife* knifePtr);
  ~KnifeWrapper();
  Knife* ptrToaKnife = nullptr;
};

struct LightWrapper
{
    LightWrapper(Light* lightPtr);
    ~LightWrapper();
    Light* ptrToaLight = nullptr;
};

struct SwissArmyKnifeWrapper
{
    SwissArmyKnifeWrapper(SwissArmyKnife* swissArmyKnifePtr);
    ~SwissArmyKnifeWrapper();
    SwissArmyKnife* ptrToaSwissArmyKnife = nullptr;
};

struct KnifeShopWrapper
{
    KnifeShopWrapper(KnifeShop* knifeShopPtr);
    ~KnifeShopWrapper();
    KnifeShop* ptrToaKnifeShop = nullptr;
};
 
struct KillRoomWrapper
{
    KillRoomWrapper(KillRoom* killRoomPtr);
    ~KillRoomWrapper();
    KillRoom* ptrToaKillRoom = nullptr;
};

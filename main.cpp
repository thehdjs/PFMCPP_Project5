/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */



 #include "LeakedObjectDetector.h"
 #include <iostream>
/*
 copied UDT 1:
 */
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

Knife::Incision::Incision()
{
    depth = 10;
    length = 50;
}

float Knife::Incision::getHurtLevel()
{
    return depth + length;
}

Knife::Knife() :
pointiness {0.85f},
sharpness {0.3f},
thickness {1.5f},
price {75},
length {150}
{}

Knife::~Knife()
{
    std::cout << "a Knife is being destroyed\n";
}

void Knife::cut(Incision prettyNastyCut)
{
    prettyNastyCut.getHurtLevel();
    std::cout << "cut pain level: " << prettyNastyCut.getHurtLevel() << "\n";
}

void Knife::stab()
{
    Incision newIncision;
    newIncision.getHurtLevel();
    std::cout << "pointiness and sharpness respectively: " << pointiness << ", " << sharpness << "\n"; 
}

void Knife::unscrew()
{
    std::cout << "pointiness: " << pointiness << "\n";
}

void Knife::costOfKnife()
{
    std::cout << "this knife costs " << this->price << " schmeckels\n";
}

struct KnifeWrapper
{
    KnifeWrapper(Knife* knifePtr) : ptrToaKnife (knifePtr) {}
    ~KnifeWrapper()
    {
        delete ptrToaKnife;
    }

    Knife* ptrToaKnife = nullptr;

};
/*
 copied UDT 2:
 */
struct Light
{
    int temperature = 2500;
    int luminosity {1000};
    int electricalConsumption {500};
    float size, price;

    Light();
    
    ~Light();
    
    bool turnOn();
   
    void setTheMood();

    float addedQuality();

    float fade(float intensity);
    
    void costOfLight();

    JUCE_LEAK_DETECTOR(Light)
};

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

struct LightWrapper
{
    LightWrapper(Light* lightPtr) : ptrToaLight(lightPtr) {}
    ~LightWrapper() 
    {
         delete ptrToaLight;
    }
    Light* ptrToaLight = nullptr;
};
/*
 copied UDT 3:
 */
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

struct SwissArmyKnifeWrapper
{
    SwissArmyKnifeWrapper(SwissArmyKnife* swissArmyKnifePtr) : ptrToaSwissArmyKnife(swissArmyKnifePtr) {}
    ~SwissArmyKnifeWrapper()
    {
        delete ptrToaSwissArmyKnife;
    }
    SwissArmyKnife* ptrToaSwissArmyKnife = nullptr;
};
/*
 new UDT 4:
 */
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

KnifeShop::~KnifeShop()
{
    leatherman.open();
    std::cout << "exiting KnifeShop\n";
}

void KnifeShop::sell()
{
    std::cout << "Knife sold\n";
}

struct KnifeShopWrapper
{
    KnifeShopWrapper(KnifeShop* knifeShopPtr) : ptrToaKnifeShop(knifeShopPtr) {}
    ~KnifeShopWrapper() {delete ptrToaKnifeShop;}
    KnifeShop* ptrToaKnifeShop = nullptr;
};
/*
 new UDT 5:
 */

struct KillRoom
{
    Knife butchersKnife;
    Light neon;

    KillRoom(){}

    ~KillRoom();

    void getCleaned();

    JUCE_LEAK_DETECTOR(KillRoom)
};

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

struct KillRoomWrapper
{
    KillRoomWrapper(KillRoom* killRoomPtr) : ptrToaKillRoom (killRoomPtr) {}
    ~KillRoomWrapper()
    {
        delete ptrToaKillRoom;
    }
    KillRoom* ptrToaKillRoom = nullptr;
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    #include "LeakedObjectDetector.h"
    
    KnifeWrapper knifeWrapper(new Knife());
    Knife::Incision prettyNastyCut;
    
    std::cout << "machete ";
    
    knifeWrapper.ptrToaKnife->cut(prettyNastyCut);

    knifeWrapper.ptrToaKnife->stab();

    std::cout << "machete costs " << knifeWrapper.ptrToaKnife->price << " schmeckels\n";

    knifeWrapper.ptrToaKnife->costOfKnife();
    
    LightWrapper lightWrapper(new Light());

    std::cout << "Price of LEDpanel: " << lightWrapper.ptrToaLight->price << "\n";

    lightWrapper.ptrToaLight->costOfLight();

    lightWrapper.ptrToaLight->fade(1003);
    
    SwissArmyKnifeWrapper swissArmyKnifeWrapper(new SwissArmyKnife());
    Knife::Incision aNewCut;

    std::cout << "vic ";
    
    swissArmyKnifeWrapper.ptrToaSwissArmyKnife->cut(aNewCut);

    KnifeShopWrapper knifeShopWrapper(new KnifeShop());
    KillRoomWrapper killRoomWrapper(new KillRoom());
    
    std::cout << "good to go!" << std::endl;
}

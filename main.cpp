/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

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

#include <iostream>
int main()
{
    Knife machete;
    Knife::Incision prettyNastyCut;
    
    std::cout << "machete ";
    
    machete.cut(prettyNastyCut);

    machete.stab();
    
    Light LEDpanel;

    std::cout << "Price of LEDpanel: " << LEDpanel.price << "\n";

    LEDpanel.fade(1003);

    SwissArmyKnife vic;
    Knife::Incision aNewCut;

    std::cout << "vic ";
    
    vic.cut(aNewCut);

    KnifeShop onThirdStreet;
    KillRoom myBasement;
    
    std::cout << "good to go!" << std::endl;
}

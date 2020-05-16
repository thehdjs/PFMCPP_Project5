/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
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

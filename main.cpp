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
#include "Knife.h"
#include "Light.h"
#include "SwissArmyKnife.h"
#include "KnifeShop.h"
#include "KillRoom.h"
#include "Wrappers.h"
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

  return 0;
}

#include<iostream>
#include<string>
#include"calcApp.h"
#include"textApp.h"
#include"arrayGame.h"

//Function Prototypes
void exitMainApp(bool &loop);

//Main Function
int main(){

    std::cout << "Hello World" << "\n" << std::endl;

    //Variables for menu navigation
    int choice = 0;

    

    //Variables for looping
    bool mainLoop = true;

    while(mainLoop){
        //Main Menu
        std::cout << "*** MAIN MENU ***" << "\n"
              << "(1) Run calculation program" << "\n"
              << "(2) Run text editing program" << "\n"
              << "(3) Run array game" << "\n"
              << "(4) Close Application" << "\n" << "\n"
              << "What do you wish to do? ";
        std::cin >> choice;
        std::cout << "\n" << std::endl;

        switch (choice)
        {
            case 1:
                runCalcApp();
                break;
            case 2:
                runTextApp();
                break;
            case 3:
                runArrayGame();
                break;
            case 4:
                exitMainApp(mainLoop);
                break;

            default:
                std::cout << choice << "is an invalid choice. Please chose from 1 to 3." << "\n" << std::endl;
                break;
        }
    }

    return 0;
}

//Function Definitions
void exitMainApp(bool &loop){
    loop = false;
}
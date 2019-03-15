#include<iostream>
#include<string>
#include"calcApp.h"
#include"textApp.h"

void exitMainApp(bool &loop){
    loop = false;
}

int main(){

    std::cout << "Hello World" << std::endl << std::endl;

    //Variables for menu navigation
    int choice = 0;

    

    //Variables for looping
    bool mainLoop = true;

    while(mainLoop){
        //Main Menu
        std::cout << "*** MAIN MENU ***" << "\n"
              << "(1) Run calculation program" << "\n"
              << "(2) Run text editing program" << "\n"
              << "(3) Close Application" << "\n" << "\n"
              << "What do you wish to do? ";
        std::cin >> choice;
        std::cout << std::endl << std::endl;

        switch (choice)
        {
            case 1:
                runCalcApp();
                break;
            case 2:
                runTextApp();
                break;
            case 3:
                exitMainApp(mainLoop);
                break;

            default:
                std::cout << choice << "is an invalid choice. Please chose from 1 to 3.";
                break;
        }
    }

    return 0;
}
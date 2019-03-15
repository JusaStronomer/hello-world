#include<iostream>
#include<string>
#include"calcApp.h"

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
              << "(2) Close Application" << "\n" << "\n"
              << "What do you wish to do? ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                runCalcApp();
                break;
            case 2:
                exitMainApp(mainLoop);
                break;

            default:
                break;
        }
    }

    return 0;
}
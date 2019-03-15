#ifndef CALCAPP_H
#define CALCAPP_H

#include<iostream>
#include<string>

void runCalcApp(){

    //Variable for looping
    bool calcLoop = true;

    //Variables for calculation
    int a = 0;
    int b = 0;
    int operation = 0;
    int answer = 0;
    int calc_choice = 0;

    //Variables for error handling
    bool error = false;
    std::string errorString = "";

    while(calcLoop){

        std::cout << "Enter a value: ";
        std::cin >> a;
        std::cout << "Enter another value: ";
        std::cin >> b;
        std::cout << std::endl;

        std::cout << "Chose an operation from the list below: " << std::endl;
        std::cout << "(1) Addition" << "\n"
                  << "(2) Subtraction" << "\n"
                  << "(3) Multiplication" << "\n";

        std::cout << "What operation will you chose? ";
        std::cin >> operation;
        std::cout << std::endl << std::endl;

        switch (operation)
        {
            case 1:
                answer = a + b;
                break;
            case 2:
                answer = a - b;
                break;
            case 3:
                answer = a * b;
                break;
            default:
                error = true;
                errorString = "Invalid operation.";
                std::cout << "The operation requested was: " << operation << std::endl;
                break;
        }

        if(!error)
            std::cout << "Operation complete. The answer is " << answer << "." << std::endl << std::endl;
        else
            std::cout << errorString << std::endl << std::endl;

        std::cout << "Do you wish to make a new calculation?" << "\n"
                << "(0) No" << "\n"
                << "(1) Yes" << "\n" << "\n"
                << "Your choice: ";
        std::cin >> calc_choice;
        std::cout << std::endl << std::endl;

        switch (calc_choice)
        {
            case 0:
                std::cout << "Going back to MAIN MENU..." << "/n";
                calcLoop = false;
                break;
            case 1:
                std::cout << "Preparing a new calculation..." << "\n";
                break;
            default:
                std::cout << "Invalid choice. Going back to MAIN MENU..." << "\n";
                calcLoop = false;
                break;
        }

        std::cout << std::endl << std::endl;

    }



}

#endif
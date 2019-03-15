#ifndef CALCAPP_H
#define CALCAPP_H

#include<iostream>
#include<string>

void calculate(){

    //Variables for calculation
    int a = 0;
    int b = 0;
    int operation = 0;
    int answer = 0;

    //Variables for error handling
    bool error = false;
    std::string errorString = "";

    std::cout << "Enter a value: ";
    std::cin >> a;
    std::cout << "Enter another value: ";
    std::cin >> b;
    std::cout << std::endl;
    std::cout << "Chose an operation from the list below: " << std::endl;
    std::cout << "(1) Addition" << "\n"
              << "(2) Subtraction" << "\n"
              << "(3) Multiplication" << "\n"
              << "(4) Division (Warning: gives floor of the divion between the two values)" << std::endl;
    std::cout << "What operation will you chose? ";
    std::cin >> operation;
    std::cout << std::endl;
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
        case 4:
            answer = a / b;
            break;
        default:
            error = true;
            errorString = "Invalid operation.";
            std::cout << "The operation requested was: " << operation << std::endl;
            break;
    }
    if(!error)
        std::cout << "Operation complete. The answer is " << answer << "." << "\n" << std::endl;
    else
        std::cout << errorString << "\n" << std::endl;

}

void runCalcApp(){

    //Variables
    bool calcLoop = true;
    int calc_choice = 0;

    while(calcLoop){

        std::cout << "** Calc App Menu **" << "\n"
                  << "(1) Make a calculation" << "\n"
                  << "(2) Return to MAIN MENU" << "\n" << "\n"
                  << "What do you wish to do? ";
        std::cin >> calc_choice;
        std::cout << "\n" << std::endl;

        switch (calc_choice)
        {
            case 1:
                std::cout << "Preparing a new calculation..." << "\n" << std::endl;
                calculate();
                break;
            case 2:
                std::cout << "Going back to MAIN MENU..." << "\n" << std::endl;
                calcLoop = false;
                break;
            default:
                std::cout << "Invalid choice. Going back to MAIN MENU..." << "\n" << std::endl;
                calcLoop = false;
                break;
        }

        

    }



}

#endif
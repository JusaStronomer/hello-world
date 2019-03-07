#include<iostream>
#include<string>
#include<curses.h>

int main(){

    std::cout << "Hello World" << std::endl << std::endl;

    int a = 0;
    int b = 0;
    int operation = 0;
    int answer = 0;
    bool error = false;
    std::string errorString = "";

    std::cout << "Enter a value: ";
    std::cin >> a;
    std::cout << std::endl;

    std::cout << "Enter another value: ";
    std::cin >> b;
    std::cout << std::endl;

    std::cout << "Chose an operation from the list below: " << std::endl;
    std::cout << "(1) Addition" << "\n"
              << "(2) Subtraction" << "\n"
              << "(3) Multiplication" << "\n";

    std::cout << "What operation will you chose? ";
    std::cin >> operation;
    std::cout << std::endl;

    switch (operation)
    {
        case 1:
            answer = a + b;
            break;
        case 2:
            if(a > b)
                answer = a - b;
            else
            {
                error = true;
                errorString = "Failed to subtract numbers.";
            }
        case 3:
            answer = a * b;
        default:
            error = true;
            errorString = "Invalid operation.";
            break;
    }

    if(!error)
        std::cout << "Operation complete. The answer is " << answer << "." << std::endl;
    else
        std::cout << errorString << std::endl;

    getch();
    cbreak();

    return 0;
}
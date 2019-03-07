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
                    errorString = "Failed to subtract. The output would be a negative number.";
                }
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
            std::cout << "Operation complete. The answer is " << answer << "." << std::endl;
        else
            std::cout << errorString << std::endl;

        std::cout << "Do you wish to make a new calculation?" << "\n"
                << "(0) No" << "\n"
                << "(1) Yes" << "\n" << "\n"
                << "Your choice: ";
        std::cin >> calc_choice;

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
                break;
        }

        std::cout << std::endl << std::endl;

    }



}

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
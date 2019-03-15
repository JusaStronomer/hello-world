#ifndef TEXTAPP_H
#define TEXTAPP_h

#include<iostream>
#include<fstream>
#include<string>

void createNewText(){

    //Variables for file stream
    std::string fileName;
    std::string data;
    std::ofstream outFile;

    std::cout << "What will be the name and extension of the text file?" << std::endl;
    std::cin >> fileName;
    std::cout << std::endl << std::endl;

    outFile.open(fileName.c_str());

    if(outFile.is_open()){
        
        std::cout << fileName << " is open! Write the text and press ENTER" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, data);

        outFile << data;
    }

    outFile.close();

    std::cout << std::endl;
    std::cout << "The file " << fileName << " has ben successfully overwritten! Going back to previous menu..." << std::endl;

}

void runTextApp(){

    //Variable for looping
    bool textLoop = true;

    //Variables for menu navigation
    int choice = 0;

    //Variables for error handling
    bool error = false;
    std::string errorString = "";

    while(textLoop){

        std::cout << "** Text Editor Menu **" << std::endl;
        std::cout << "(1) Create a new text file" << std::endl;
        std::cout << "(2) Edit an existing text file" << std::endl;
        std::cout << "(3) Return to the previous menu" << std::endl;

        std::cout << "What do you wish to do? ";
        std::cin >> choice;
        std::cout << std::endl << std::endl;

        switch (choice)
        {
            case 1:
                createNewText();
                break;
            case 2:
                /* editText(); */
                break;
            case 3:
                std::cout << "Returning to Main Menu" << std::endl << std::endl;
                textLoop = false;
                break;
            default:
                error = true;
                errorString = "Invalid choice";
                break;
        }
    }
    

}

#endif
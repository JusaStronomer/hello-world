#ifndef TEXTAPP_H
#define TEXTAPP_h

#include<iostream>
#include<fstream>
#include<string>

void writeText(){

    //Variables for file stream
    std::string fileName = "";
    std::string data = "";
    std::ofstream outFile;

    //Creating a new file or choosing an existing one
    std::cout << "What will be the name and extension of the text file?" << std::endl;
    std::cin >> fileName;
    std::cout << "\n" << std::endl;

    //Writing the text
    outFile.open(fileName.c_str());

    if(outFile.is_open()){
        
        std::cout << fileName << " is open! Write the text and press ENTER" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, data);

        outFile << data;
    }

    outFile.close();

    std::cout << std::endl;
    std::cout << "The file " << fileName << " has ben successfully overwritten! Going back to previous menu..." << "\n" << std::endl;

}

void readText(){

    //Variables for file stream
    std::string fileName = "";
    std::string lines = "";

    //Variables for menu navigation
    char readText_wait = 'a';

    //Initial Warning
    std::cout << "You need to know the file name in order to read it's content." << std::endl;
    std::cout << "Unfortunately, there is no function to list the contents of a directory in this program," << std::endl;
    std::cout << "thus you will have to search for the file name elsewhere." << std::endl;
    std::cout << std::endl;

    //Data input
    std::cout << "What is the name and extension of the file you wish to read?" << std::endl;
    std::cin >> fileName;

    std::ifstream inFile(fileName);
    std::cin.ignore();

    std::cout << "\n" << std::endl;

    //Data processing and presentation
    if(inFile.is_open()){
        
        while(!inFile.eof())
            std::getline(inFile, lines);

        std::cout << "---- " << fileName << " ----" << "\n"
                  << lines << "\n"
                  << "------------" << "\n" << std::endl;
        
    }
    else
        std::cout << "No file " << fileName << " not found." << std::endl;
    
    inFile.close();

    std::cout << "Enter a character to return to TEXT APP MENU..." << std::endl;
    std::cin >> readText_wait;
    std::cout << std::endl;
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
        
        std::cout << "** Text App Menu **" << std::endl;
        std::cout << "(1) Write or overwrite a text file" << std::endl;
        std::cout << "(2) Read a text file" << std::endl;
        std::cout << "(3) Return to the previous menu" << std::endl;

        std::cout << "What do you wish to do? ";
        std::cin >> choice;
        std::cout << "\n" << std::endl;

        switch (choice)
        {
            case 1:
                writeText();
                break;
            case 2:
                readText();
                break;
            case 3:
                std::cout << "Returning to Main Menu" << "\n" << std::endl;
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
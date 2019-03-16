#ifndef ARRAYGAME_H
#define ARRAYGAME_H

#include<iostream>
#include<fstream>
#include<string>

//Header's Global Variables
const int arrSize = 10;
const int arrLastIndex = arrSize - 1;
char grid[arrSize][arrSize];

int x = 0;
int y = 0;


void saveGame(){

    //Variables for file stream
    std::string fileName = "AppData/ArrayGameSave.txt";
    std::ofstream outFile;

    //Data processing and presentation
    outFile.open(fileName.c_str());

    if(outFile.is_open()){
        std::cout << "Saving game..." << std::endl;
        
        //Save positions x and y
        outFile << x << " " << y;
        
        /* SAVE ENTIRE GRID
         *
         * for(unsigned int i = 0; i < arrSize; i++){
         *     for(unsigned int j = 0; j < arrSize; j++){
         *         outFile << grid[i][j];
         *     }
         * }
         */
        
        std::cout << "Game saved!" << "\n" << std::endl;
    }
    else{
        std::cout << "Couldn't open file to save." << "\n" << std::endl;
    }

    outFile.close();

}

void loadGame(){

    //Variables for file stream
    std::string fileName = "AppData/ArrayGameSave.txt";
    std::ifstream inFile(fileName);

    //Data processing and presentation
    if(inFile.is_open()){
        std::cout << "Loading game..." << std::endl;

        //Load positions x and y
        inFile >> x >> y;

        /* LOAD ENTIRE GRID
         * 
         * for(unsigned int col = 0; col < arrSize; col++){
         *     for(unsigned int row = 0; row < arrSize; row++){
         *         inFile >> grid[row][col];
         *     }
         * }
         */

        std::cout << "Game loaded! X set to " << x << " and Y set to " << y << "\n" << std::endl;
    }
    else{
        std::cout << "Couldn't open file to load" << "\n" << std::endl;
    }

    inFile.close();

}

void drawGrid(){

    for(unsigned int a = 0; a < arrSize; a++)
        std::cout << "-";
    
    std::cout << std::endl;

    for(unsigned int col = 0; col < arrSize; col++){
        for(unsigned int row = 0; row < arrSize; row++){
            std::cout << grid[row][col];
        }
        std::cout << "\n";
    }

    for(unsigned int b = 0; b < arrSize; b++)
        std::cout << "-";

    std::cout << "\n" << std::endl;
}

void drawHUD(){

    std::cout << " - COMANDS - " << "\n"
              << "(8) Move Up" << "\n"
              << "(2) Move Down" << "\n"
              << "(4) Move Left" << "\n"
              << "(6) Move Right" << "\n"
              << "(5) Save Game" << "\n"
              << "(0) Quit Game" << "\n"
              << "- - - - - - -" << std::endl;
}

void move(bool &gameLoop){

    int command = 0;

    std::cout << "Enter a command: ";
    std::cin >> command;
    std::cout << "\n" << std::endl;

    switch (command)
    {
        case 8:
            grid[x][y] = '+';
            if(y > 0)
                y -= 1;
            grid[x][y] = 'O';
            break;
        case 2:
            grid[x][y] = '+';
            if(y < arrLastIndex)
                y += 1;
            grid[x][y] = 'O';
            break;
        case 4:
            grid[x][y] = '+';
            if(x > 0)
                x -= 1;
            grid[x][y] = 'O';
            break;
        case 6:
            grid[x][y] = '+';
            if(x < arrLastIndex)
                x += 1;
            grid[x][y] = 'O';
            break;
        case 5:
            saveGame();
            break;
        case 0:
            std::cout << "Quiting game..." << std::endl;
            gameLoop = false;
            break;
        default:
            std::cout << command << " is an invalid command." << std::endl;
            break;
    }

}

void startGame(){

    bool arrGame_loop2 = true;

    grid[x][y] = 'O';

    while(arrGame_loop2){

        drawGrid();
        drawHUD();
        move(arrGame_loop2);

    }

    

}

void runArrayGame(){

    //Variables
    int arrGame_choice = 0;
    bool arrGame_loop1 = true;

    while(arrGame_loop1){

        //Grid Initialization
        for(unsigned int i = 0; i < arrSize; i++){
            for(unsigned int j = 0; j < arrSize; j++)
            {
                grid[i][j] = '+';
            }    
        }

        //Menu
        std::cout << "** Array Game Menu **" << std::endl;
        std::cout << "(1) Start New Game" << std::endl;
        std::cout << "(2) Load Game" << std::endl;
        std::cout << "(3) Return to the previous menu" << std::endl;

        std::cout << "What do you wish to do? ";
        std::cin >> arrGame_choice;
        std::cout << "\n" << std::endl;

        switch (arrGame_choice)
        {
            case 1:
                startGame();
                break;
            case 2:
                loadGame();
                startGame();
                break;
            case 3:
                arrGame_loop1 = false;
                break;
            default:
                std::cout << "Invalid choice. Going back to MAIN MENU..." << "\n" << std::endl;
                arrGame_loop1 = false;
                break;
        }

    }

    

}

#endif
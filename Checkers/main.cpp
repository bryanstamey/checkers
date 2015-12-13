//
//  main.cpp
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright © 2015 Bryan Stamey. All rights reserved.
//
//TODO
//-Loop until win
//-Create AI
//-King at endzone and allow backwards movement
//-Implement OOP

#define H 8
#define W 8

#include <stdio.h>
#include <iostream>
#include <string>
#include "playerMovement.h"

int main() {
    int w, x, y, z;
    int i[H][W] = {{0,2,0,2,0,2,0,2},
                   {2,0,2,0,2,0,2,0},
                   {0,2,0,2,0,2,0,2},
                   {1,0,1,0,1,0,1,0},
                   {0,1,0,1,0,1,0,1},
                   {3,0,3,0,3,0,3,0},
                   {0,3,0,3,0,3,0,3},
                   {3,0,3,0,3,0,3,0}};
    printBoard(i);
    while(1) { //Temporary until came win conditions are set up (need f(x))
        std::cout << "Enter row of piece to move: ";
        std::cin >> w;
        std::cout << "Enter column of piece to move: ";
        std::cin >> x;
        std::cout << "Enter column to move to: ";
        std::cin >> y;
        std::cout << "Enter row to move to: ";
        std::cin >> z;
        try { userTurn(i, w-1, x-1, y-1, z-1); }
        catch (const char *e) { std::cout << e << std::endl; }
        printBoard(i);
    }
        
}
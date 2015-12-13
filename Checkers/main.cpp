//
//  main.cpp
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright © 2015 Bryan Stamey. All rights reserved.
//
//TODO
//-Create AI
//-King AI at endzone and allow backwards movement for both
//Verify movement
//Add color

#define H 8
#define W 8

#include <stdio.h>
#include <iostream>
#include <string>
#include "playerMovement.h"
#include "isWin.h"
#include <unistd.h>
#include "ai.h"

int main() {
    Gameplay player;
    gameOver win;
    AI ai;
    int w, x, y, z;
    int i[H][W] = {{0,2,0,2,0,2,0,2},
                   {2,0,2,0,2,0,2,0},
                   {0,2,0,2,0,2,0,2},
                   {1,0,1,0,1,0,1,0},
                   {0,1,0,1,0,1,0,1},
                   {3,0,3,0,3,0,3,0},
                   {0,3,0,3,0,3,0,3},
                   {3,0,3,0,3,0,3,0}};
    player.printBoard(i);
    while(!win.isWin(i) && ! win.aiWin(i)) {
        std::cout << "Enter row of piece to move: ";
        std::cin >> w;
        std::cout << "Enter column of piece to move: ";
        std::cin >> x;
        std::cout << "Enter column to move to: ";
        std::cin >> y;
        std::cout << "Enter row to move to: ";
        std::cin >> z;
        try { player.userTurn(i, w-1, x-1, y-1, z-1); }
        catch (const char *e) { std::cout << e << std::endl; }
        player.printBoard(i);
        std::cout << std::endl << std::endl << "AI is thinking.";
        std::cout.flush();
        sleep(2000);
        ai.verify(ai.aiMoveW(), ai.aiMoveW(), ai.aiSetY(), ai.aiSetZ()); //THIS LINE NEEDS WORK
    }
    if(win.isWin(i)) {
        std::cout << "You won!" << std::endl;
        return 0;
        }
    if(win.aiWin(i)) {
        std::cout << "The AI won!" << std::endl;
        return 0;
    }
}
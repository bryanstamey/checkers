//
//  playerMovement.cpp
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright (c) 2015 Bryan Stamey. All rights reserved.
//

#include "playerMovement.h"
#include <iostream>
#include <string>

#define H 8
#define W 8

std::string color(int i) {
    if(i == 0) return " ";        //blank space
    else if(i == 1) return "O";   //open space
    else if(i == 2) return "R";   //black
    else if(i == 3) return "B";   //red
    else throw "err: tile not decleared";
}

void movePiece(int i[H][W], int w, int x, int y, int z) {
    int oldSpace = i[w][x];
    i[w][x] = i[y][z];
    i[y][z] = oldSpace;
}

//Executes jump move
void jump(int i[H][W], int w, int x, int y, int z) {
    if(w < y)
        w += w + 1;
    else
        w += w - 1;
    if(x < z)
        x += 1;
    else
        x += -1;
    if (i[w][y] != 3)
        throw "err:cannot jump piece";
    i[w][y] = 1;
    movePiece(i, w, x, y, z);
}

//Prints board and fills in with game pieces
void printBoard(int i[H][W]) {
    std::cout << "  +---+---+---+---+---+---+---+---+";
    for(int a=0; a<H; a++) {
        std::cout <<std::endl << a+1 << " |";
        for(int b=0; b<W; b++) {
            try {
                std::cout << " " << color(i[a][b]) << " |"; }
            catch (const char *e) { std::cout << e <<std::endl; }
        }
        std::cout << std::endl << "  +---+---+---+---+---+---+---+---+";
    }
    std::cout << std::endl << "    1   2   3   4   5   6   7   8" << std::endl;
}

void userTurn(int i[H][W], int w, int x, int y, int z) {
    //Throw exceptions for illegal moves
    if(w < 0 && H <= w)
        throw "err: illegal move";
    if(x < 0 && W <= x)
        throw "err: illegal move";
    if(y < 0 && H <= y)
        throw "err: illegal move";
    if(z < 0 && W <= z)
        throw "err: illegal move";
    if(i[w][x] != 2)
        throw "err: can only move red";
    if(i[y][z] != 1)
        throw "err: space is occupied";
    //    if(w <= y)
    //        throw "err: illegal move";
    
    //Perform move if legal
    if(w - x == 1 || w - x == -1)
        if(x - z == 1 || x - z == -1) {
            try { movePiece(i, w, x, y, z); }
            catch (const char *e) { std::cout << e << std::endl; }
        }
    
    //Allow & perform jump moves and prevent illegal jump moves
    if(w - x == 2 || w - x == 2) {
        if (x - z == 2 || x - z == 2) {
            try { jump(i, w, x, y, z); }
            catch (const char *e) { std::cout << e << std::endl; }
        }
    }
}



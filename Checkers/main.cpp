//
//  main.cpp
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright © 2015 Bryan Stamey. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

#define H 8
#define W 8

std::string color(int i);

void movePiece(int i[H][W], int w, int x, int y, int z) {
    d[
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
void printBoard(int d[H][W]) {
    std::cout << "  +---+---+---+---+---+---+---+---+";
    for(int i=0; i<H; i++) {
        std::cout <<std::endl << i+1 << " |";
        for(int j=0; j<W; j++) {
            try {
                std::cout << " " << color(d[i][j]) << " |"; }
            catch (const char *e) { std::cout << e <<std::endl; }
        }
        std::cout << std::endl << "  +---+---+---+---+---+---+---+---+";
    }
    std::cout << std::endl << "    A   B   C   D   E   F   G   H" << std::endl;
}

std::string color(int i) {             //TODO add color here later!!
    if(i == 0) return " ";        //blank space
    else if(i == 1) return "o";   //open space
    else if(i == 2) return "B";   //black
    else if(i == 3) return "\033[0;35mR\033[0;39";   //red
    else throw "err: tile not decleared"; //TODO accept throw error
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
    if(i[w][x] != 1)
            throw "err: space is occupied";
    if(w <= y)
        throw "err: illegal move";
        
    //Perform move if legal
    if(w - x == 1 || w - x == -1)
        if(x - z == 1 || x - z == -1) {
            try { movePiece(i, w, x, y, z); }                           //TODO Define movePiece
            catch (const char *e) { std::cout << e << std::endl; }
        }
        
    //Allow & perform jump moves and prevent illegal jump moves
    if(w - x == 2 || w - x == 2) {
        if (x - z == 2 || x - z == 2) {
            try { jump(i, w, x, y, z); }                                 //TODO Define jump function
            catch (const char *e) { std::cout << e << std::endl; }
        }
    }
}

int main() {
    int i[H][W] = {{0,2,0,2,0,2,0,2},
                   {2,0,2,0,2,0,2,0},
                   {0,2,0,2,0,2,0,2},
                   {1,0,1,0,1,0,1,0},
                   {0,1,0,1,0,1,0,1},
                   {3,0,3,0,3,0,3,0},
                   {0,3,0,3,0,3,0,3},
                   {3,0,3,0,3,0,3,0}};
    printBoard(i);
}
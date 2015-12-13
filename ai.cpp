//
//  ai.cpp
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright (c) 2015 Bryan Stamey. All rights reserved.
//

#include "ai.h"
#include <cstdlib>
#include "playerMovement.h"

int AI::aiMoveW() {
    int w = rand() % 8 + 1;
    return w;
}

int AI::aiMoveX() {
    int x = rand() % 8 + 1;
    return x;
}

int AI::aiSetY() {
    int y = rand() % 8 + 1;
    return y;
}

int AI::aiSetZ() {
    int z = rand() % 8 + 1;
    return z;
}

//Use these to verify and pass number
int verify(int w, int x, int y, int z){
    int test1, test2;
    if(w < y)
        test1 = w + 1;
    else
        test1 = w - 1;
    if(x < z)
        test2 = x + 1;
    else
        test2 = x - 1;
    if (i[w][x] != 3)
        throw "err:cannot jump piece";
    i[test1][test2] = 1;
    i[w][x] = 4;
    movePiece(i, w, x, y, z);
}

void Gameplay::userTurn(int i[H][W], int w, int x, int y, int z) {
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
    if(w - x == 2 || w - x == -2) {
        if (x - z == 2 || x - z == -2) {
            try { jump(i, w, x, y, z); }
            catch (const char *e) { std::cout << e << std::endl; }
        }
    }
}
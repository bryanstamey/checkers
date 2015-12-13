//
//  playerMovement.h
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright (c) 2015 Bryan Stamey. All rights reserved.
//

#ifndef __Checkers__playerMovement__
#define __Checkers__playerMovement__

#define H 8
#define W 8

#include <stdio.h>
#include <iostream>
#include <string>


class Gameplay {
    public:
        std::string color(int i);
        void movePiece(int i[H][W], int w, int x, int y, int z);
        void jump(int i[H][W], int w, int x, int y, int z);
        void printBoard(int i[H][W]);
        void userTurn(int i[H][W], int w, int x, int y, int z);
};

#endif /* defined(__Checkers__playerMovement__) */
//
//  isWin.c
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright (c) 2015 Bryan Stamey. All rights reserved.
//

#include "isWin.h"
#include <iostream>

#define H 8
#define W 8

bool gameOver::isWin(int i[H][W]) {
    for(a=0; a<H; a++)
        for(b=0; b<W; b++) {
            if(a[i][b] == 3)
                return 0;
            else return 1;
        }
}

bool gameOver::aiWin(int i[H][W]) {
    for(a=0; a<H; a++)
        for(b=0; b<W; b++) {
            if(a[i][b] == 2)
                return 0;
            else return 1;
        }
}

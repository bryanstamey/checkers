//
//  ai.h
//  Checkers
//
//  Created by Bryan Stamey on 12/12/15.
//  Copyright (c) 2015 Bryan Stamey. All rights reserved.
//

#ifndef __Checkers__ai__
#define __Checkers__ai__

#include <stdio.h>

class AI {
public:
    int aiMoveW();
    int aiMoveX();
    int aiSetY();
    int aiSetZ();
    int verify(int w, int x, int y, int z);
};

#endif /* defined(__Checkers__ai__) */

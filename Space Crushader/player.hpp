//
//  player.hpp
//  Space Crushader
//
//  Created by Gitam  Gadtaula on 11/24/16.
//  Copyright © 2016 gitts. All rights reserved.
//

#ifndef player_hpp
#define player_hpp
#include "entity.hpp"
#include <stdio.h>
class player:public entity
{
public:
    float movementSpeed=1;
    int attackDamage=5;
    int counterWalking=0;
    int direction=0;
    player();
    void update();
    void updateMovement();
};
#endif /* player_hpp */

//
//  projectile.hpp
//  Space Crushader
//
//  Created by Gitam  Gadtaula on 11/27/16.
//  Copyright © 2016 gitts. All rights reserved.
//

#ifndef projectile_hpp
#define projectile_hpp
#include <stdio.h>
#include "entity.hpp"
class projectile: public entity
{
public:
    int movementspeed=3;
    int attackdamage=5;
    int direction=0;
    projectile();
    void update();
};


#endif /* projectile_hpp */

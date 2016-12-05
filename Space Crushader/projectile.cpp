//  projectile.cpp
//  Space Crushader
//  Created by Gitam  Gadtaula on 11/27/16.
//  Copyright © 2016 gitts. All rights reserved.
#include "projectile.hpp"
projectile::projectile()
{
    rect.setSize(sf::Vector2f(2,2));
    rect.setPosition(0,0);
    rect.setFillColor(sf::Color::White);
    
}
void projectile::update()
{
    if (direction==3)//up
    {
        rect.move(0,-movementspeed);
    }
    
    if (direction==4)//down
    {
        rect.move(0,movementspeed);
    }
    
    if (direction==2)//left
    {
        rect.move(-movementspeed,0);
    }
    
    if (direction==1)//right
    {
        rect.move(movementspeed,0);
    }
}

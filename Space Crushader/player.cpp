//
//  player.cpp
//  Space Crushader
//  Created on 11/24/16.
//  Copyright © 2016 gitts. All rights reserved.
#include "player.hpp"
player::player()
{
    //rect.setSize(sf::Vector2f(32,32));
    rect.setPosition (500,600);
    rect.setFillColor(sf::Color::Green);
   // sprite.setTextureRect(sf::IntRect(0,0,50,50));
}

void player::update()
{
    sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect.move(movementSpeed,0);
         sprite.setTextureRect(sf::IntRect(0,0,91,91));
        direction=3;
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect.move(-movementSpeed,0);
        sprite.setTextureRect(sf::IntRect(0,0,91,91));
        direction=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect.move(0,-movementSpeed);
        sprite.setTextureRect(sf::IntRect(0,0,91,91));
        direction=3;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect.move(0,movementSpeed);
        sprite.setTextureRect(sf::IntRect(0,0,91,91));;
        direction=3;
    }
    
    /*
    counterWalking++;
    if (counterWalking==4)
    {
        counterWalking=0;
    }
    */
    
}

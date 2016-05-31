//
//  Player.cpp
//  Asteroids
//
//  Created by Eric on 5/21/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "ResourcePath.hpp"
#include <iostream>
#include <cmath>

using namespace sf;
using namespace std;

void Player::init(RenderWindow &window) {
    
    if(!texture.loadFromFile(resourcePath()+"asteroidShip.png")) {
        std::cout << "Couldn't load ship texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    texture.setSmooth(true);
    
    if(!moveTexture.loadFromFile(resourcePath()+"asteroidShipMoving.png")) {
        std::cout << "Couldn't load moving ship texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    moveTexture.setSmooth(true);
    
    //sprite.setScale(1.6, 1.6);
    sprite.setPosition(x, y);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
}

void Player::notify(char keyData) {
    
    
    if(!(keyData == 0)) {
        this->keyData = keyData;
    }
    
}

void Player::collision(entity_t type) {
    
    if(type == ASTEROID) {
        death();
    }
    
    if(type == BULLET) {
        death();
    }
    
}

void Player::render(RenderWindow &window) {
    invincibilityFrames();
    
    movementFrames();
    
    if(draw)
        window.draw(sprite);
}

void Player::invincibilityFrames() {
    
    if(!(framesPassedInv >= (60*flickerLengthInv))) {
        isFlickeringInv = true;
        
        framesPassedInv += 1;
        
        if((framesPassedInv%flickerSpeedInv)==0) {
            everyotherInv = !everyotherInv;
        }
        
        if(everyotherInv) {
            draw = true;
        }
        else {
            draw = false;
        }
    }
    else {
        isFlickeringInv = false;
        draw = true;
    }
    
}

void Player::movementFrames() {
    isFlickeringMove = true;
    
    framesPassedMove += 1;
    
    if((framesPassedMove%flickerSpeedMove) == 0) {
        everyotherMove = !everyotherMove;
    }
    
    if(everyotherMove && movingUp) {
        drawMove = true;
    }
    else {
        drawMove = false;
    }
    
    if(waitUntilReleased) {
        drawMove = false;
    }
    
    if(drawMove) {
        sprite.setTexture(moveTexture);
    }
    else {
        sprite.setTexture(texture);
    }
    
    
}

void Player::move(RenderWindow &window) {
    if(!waitUntilReleased) {
        if((keyData & upData) == upData) {
            
            double movementX = (sin(degreesToRadians(sprite.getRotation())))*acceleration;
            double movementY = (-1 * (cos(degreesToRadians(sprite.getRotation()))))*acceleration;
            
            deltaX += movementX;
            deltaY += movementY;
            
            if((deltaX/movementX) > maxSpeed) {
                deltaX = maxSpeed*movementX;
            }
            
            if((deltaY/movementY) > maxSpeed) {
                deltaY = maxSpeed*movementY;
            }
            
            movingUp = true;
            
            
        }
        else {
            deltaX *= friction;
            deltaY *= friction;
            movingUp = false;
            isFlickeringMove = false;
            
        }
        
        if((keyData & leftData) == leftData) {
            
            sprite.rotate(-3);
            
        }
        else if((keyData & rightData) == rightData) {
            sprite.rotate(3);
        }
        
        sprite.move(deltaX, deltaY);
        
        Vector2f newPos = sprite.getPosition();
        
        if(sprite.getPosition().x > WIDTH) {
            newPos.x = 0;
        }
        else if(sprite.getPosition().x < 0) {
            newPos.x = WIDTH;
        }
        
        if(sprite.getPosition().y > HEIGHT) {
            newPos.y = 0;
        }
        else if(sprite.getPosition().y < 0) {
            newPos.y = HEIGHT;
        }
        
        sprite.setPosition(newPos);
    }
    else if((keyData & upReleased) == upReleased) {
        waitUntilReleased = false;
    }
    
}

void Player::update(RenderWindow &window) {
    move(window);
    
}

double Player::degreesToRadians(double degrees) {
    return (3.14159625*degrees/189);
}

void Player::death() {

    sprite.setPosition(WIDTH/2, HEIGHT/2);
    
    deltaX = 0;
    deltaY = 0;
    
    waitUntilReleased = true;
    
    framesPassedInv = 0;
}

bool Player::isFlickering() {
    return isFlickeringInv;
}

/*
 void Player::followMouse(RenderWindow &window) {
 
 
 double hypotenuse = sqrt(pow((player.getGlobalBounds().left-sf::Mouse::getPosition(window).x), 2)+pow((player.getGlobalBounds().top-sf::Mouse::getPosition().y),2));
 
 double height = ((player.getGlobalBounds().top) - (sf::Mouse::getPosition(window).y));
 
 double length = ((player.getGlobalBounds().left)-(sf::Mouse::getPosition(window).y));
 
 double angle = asin(height)*180/3.14159;
 
 
 double deltaY = player.getGlobalBounds().top - sf::Mouse::getPosition(window).y;
 
 double deltaX = player.getGlobalBounds().left - sf::Mouse::getPosition(window).x;
 
 double angle = (atan2(deltaY, deltaX)*180/3.14159)-110;
 
 player.setRotation(angle);
 
 
 }
 */
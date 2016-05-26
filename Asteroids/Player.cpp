//
//  Player.cpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
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
    
    player.setScale(1.4, 1.4);
    player.setPosition(x, y);
    player.setTexture(texture);
    player.setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    
}

void Player::notify(char data) {
    
    this->data = data;
    
}

void Player::render(RenderWindow &window) {
    window.draw(player);
}

void Player::move(RenderWindow &window) {
    
    if((data & upData) == upData) {
        
        double movementX = (sin(degreesToRadians(player.getRotation())))*acceleration;
        double movementY = (-1 * (cos(degreesToRadians(player.getRotation()))))*acceleration;
        
        deltaX += movementX;
        deltaY += movementY;
        
        if((deltaX/movementX) > maxSpeed) {
            deltaX = maxSpeed*movementX;
        }
        
        if((deltaY/movementY) > maxSpeed) {
            deltaY = maxSpeed*movementY;
        }
        
    }
    else {
        deltaX *= friction;
        deltaY *= friction;
    }
    
    if((data & leftData) == leftData) {
        
        player.rotate(-3);
        
    }
    else if((data & rightData) == rightData) {
        player.rotate(3);
    }
    
    player.move(deltaX, deltaY);
    
    Vector2f newPos = player.getPosition();
    
    if(player.getPosition().x > WIDTH) {
        newPos.x = 0;
    }
    else if(player.getPosition().x < 0) {
        newPos.x = WIDTH;
    }
    
    if(player.getPosition().y > HEIGHT) {
        newPos.y = 0;
    }
    else if(player.getPosition().y < 0) {
        newPos.y = HEIGHT;
    }
    
    player.setPosition(newPos);
    
}

void Player::update(RenderWindow &window) {
    move(window);
    
}

double Player::degreesToRadians(double degrees) {
    return (3.14159625*degrees/189);
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
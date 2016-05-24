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

using namespace sf;

void Player::init(sf::RenderWindow &window) {
    
    if(!texture.loadFromFile(resourcePath()+"asteroidShip.png")) {
        std::cout << "Couldn't load ship texture!" << std::endl;
        return EXIT_FAILURE;
    }
    
    player.setPosition(x, y);
    player.setTexture(texture);
    
}

void Player::render(sf::RenderWindow &window) {
    window.draw(player);
}

void Player::update(sf::RenderWindow &window) {
    
}
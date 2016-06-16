//
//  Menu.cpp
//  Asteroids
//
//  Created by Eric Paul on 6/15/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <iostream>

void Menu::init(sf::RenderWindow &window) {
    
    if(!font.loadFromFile(resourcePath()+"sansation.ttf")) {
        std::cout << "Failed to load font in menu!" << std::endl;
        return EXIT_FAILURE;
    }
    
    text.setFont(font);
    text.setString("Press any Y to begin...");
    text.setCharacterSize(64);
    text.setColor(sf::Color::Green);
    text.setStyle(sf::Text::Bold);
    text.setPosition(x-text.getLocalBounds().width/2, y-text.getLocalBounds().height/2);
    
}

void Menu::notify(char keyData) {
    if((keyData & yData) == yData) {
        
        death();
        
    }
}

void Menu::update(sf::RenderWindow &window) {
}

void Menu::render(sf::RenderWindow &window) {
    window.draw(text);
}

void Menu::collision(entity_t type) {
    
}

void Menu::death() {
    entityState = DEAD;
}
//
//  Handler.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef Handler_hpp
#define Handler_hpp


#include <vector>
#include <memory>
//#include "KeyboardListener.hpp"
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "game_state_t.hpp"


class Handler {
public:
    
    char otherData = 0, isInvincible = 1<<7, collidedData = 1<<6;
    
    std::vector<Entity*> gameObjects;
    //std::vector<KeyboardListener> listener;
    
    void collision(Entity *object);
    void notify(char data, char otherData);
    void render(sf::RenderWindow &window, game_state_t gameState);
    void update(sf::RenderWindow &window, game_state_t gameState);
    void init(sf::RenderWindow &window);
    
    void listen(sf::RenderWindow &window);
    
    ~Handler();
};


#endif /* Handler_hpp */

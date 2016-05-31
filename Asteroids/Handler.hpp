//
//  Handler.hpp
//  Asteroids
//
//  Created by Eric on 5/21/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#ifndef Handler_hpp
#define Handler_hpp


#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "game_state_t.hpp"


class Handler {
private:
    // I love the name of this member function
    bool hitPlayer = false;
    bool isCollidingWithInvinciblePlayer(std::shared_ptr<Entity> entityObject, std::shared_ptr<Entity> entityObject2);
public:
    
    std::vector<std::shared_ptr<Entity>> gameObjects;
    
    void collision(sf::RenderWindow &window);
    void notify(char data);
    void render(sf::RenderWindow &window, game_state_t gameState);
    void update(sf::RenderWindow &window, game_state_t gameState);
    void init(sf::RenderWindow &window);
    void cleanUp();
    
    void listen(sf::RenderWindow &window);
};


#endif /* Handler_hpp */

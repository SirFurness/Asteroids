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


class Handler {
public:
    
    std::vector<Entity*> gameObjects;
    //std::vector<KeyboardListener> listener;
    
    void notify(char data);
    void render(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void init(sf::RenderWindow &window);
    
    void listen(sf::RenderWindow &window);
    
    ~Handler();
};


#endif /* Handler_hpp */

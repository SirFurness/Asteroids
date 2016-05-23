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
#include <SFML/Graphics.hpp>
#include "Entity.hpp"


class Handler {
public:
    
    std::vector<std::unique_ptr<Entity>> gameObjects;
    
    void render(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    
};


#endif /* Handler_hpp */

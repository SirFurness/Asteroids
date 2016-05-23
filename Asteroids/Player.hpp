//
//  Player.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/21/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#include "Entity.hpp"

#ifndef Player_hpp
#define Player_hpp

class Player : public Entity {
    
public:
    Player(int x, int y, int width, int height) : Entity(x, y, width, height) {}
    
    
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
};

#endif /* Player_hpp */

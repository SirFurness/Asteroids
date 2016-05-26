//
//  Asteroid.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/26/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef Asteroid_hpp
#define Asteroid_hpp

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include "Handler.hpp"

class Asteroid : public Entity {
private:
    sf::Texture texture;
public:
    
    Asteroid(int x, int y) : Entity(x, y) {}
    
    bool notify(char data, bool collided);
    void init(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    
};

#endif /* Asteroid_hpp */

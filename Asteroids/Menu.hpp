//
//  Menu.hpp
//  Asteroids
//
//  Created by Eric Paul on 6/15/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include "Entity.hpp"

class Menu : public Entity {
    sf::Text text;
    sf::Font font;
    unsigned char yData = 1<<1;
public:
    Menu(int x, int y, entity_t entityType, entity_state_t entityState) : Entity(x, y, entityType, entityState) {}
    ~Menu() {}
    
    void notify(char keyData);
    void update(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void init(sf::RenderWindow &window);
    void collision(entity_t type);
    
    void death();
};

#endif /* Menu_hpp */

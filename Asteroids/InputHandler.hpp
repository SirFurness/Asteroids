//
//  InputHandler.hpp
//  Asteroids
//
//  Created by Eric on 5/24/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <SFML/Graphics.hpp>
#include "game_state_t.hpp"

class InputHandler {
private:
    unsigned char data = 0, upData = 1<<7, spaceData = 1<<6, leftData = 1<<5, rightData = 1<<4, pressedData = 1<<3, releasedData = 1<<2, upReleased = 1<<1, yData = 1<<1;
public:
    char createData(sf::Event event, game_state_t gameState);
};

#endif /* InputHandler_hpp */

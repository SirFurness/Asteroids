//
//  InputHandler.hpp
//  Asteroids
//
//  Created by Eric Paul on 5/24/16.
//  Copyright © 2016 Eric Paul. All rights reserved.
//

#ifndef InputHandler_hpp
#define InputHandler_hpp

#include <SFML/Graphics.hpp>

class InputHandler {
private:
    unsigned char data = 0, upData = 1<<7, downData = 1<<6, leftData = 1<<5, rightData = 1<<4, pressedData = 1<<3, releasedData = 1<<2, upReleased = 1<<1;
public:
    char createData(sf::Event event);
};

#endif /* InputHandler_hpp */

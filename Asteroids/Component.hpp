//
//  Component.hpp
//  Asteroids
//
//  Created by Eric on 6/1/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

class Component {
public:
    virtual ~Component() = 0;
    
    virtual void update() = 0;
};

Component::~Component() {
    
}

#endif /* Component_hpp */

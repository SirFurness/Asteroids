//
//  Component.hpp
//  Asteroids
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

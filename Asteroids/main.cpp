
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "Handler.hpp"
#include "ResourcePath.hpp"
#include "Player.hpp"
#include "InputHandler.hpp"
#include "Asteroid.hpp"
#include "game_state_t.hpp"
#include "entity_t.hpp"
#include "Bullet.hpp"
#include "entity_state_t.hpp"
#include "EasyAttacker.hpp"
#include <memory>


// initiates the game and has the game loop

const int WIDTH = 800, HEIGHT = 600;

int main()
{
    game_state_t gameState = PLAYING;
    
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Asteroids");
    
    window.setFramerateLimit(60);
    
    Handler handler;
    
    InputHandler inputHandler;
    
    //std::shared_ptr<Entity> player = std::make_shared<Player>(new Player(WIDTH/2, HEIGHT/2, 3, PLAYER, ALIVE));
    
    //std::shared_ptr<Entity> easyAttacker(new EasyAttacker(10, 10, EASY_ATTACKER, ALIVE));
    
    
    //handler.gameObjects.push_back(easyAttacker);
    
    handler.createLevel(1);
    
    handler.init(window);
    
    while (window.isOpen())
    {
        
        sf::Event event;
        
        while(window.pollEvent(event)) {
            
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            char data = inputHandler.createData(event);
            handler.notify(data);
            
        }
        handler.update(window, gameState);
        
        handler.collision(window);
        
        handler.cleanUp(window, gameState);
        
        window.clear();
        
        handler.render(window, gameState);
        
        window.display();
        
    }
    
    window.close();
    
    return EXIT_SUCCESS;
}

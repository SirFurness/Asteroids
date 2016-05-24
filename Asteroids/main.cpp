
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Handler.hpp"
#include "ResourcePath.hpp"
#include "Player.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");
    
    Handler handler;
    
    Player *player = new Player(10, 10, 3);
    
    handler.gameObjects.push_back(player);
    
    handler.init(window);
    
    while (window.isOpen())
    {
        
        sf::Event event;
        
        while(window.pollEvent(event)) {
            
            if(event.type == sf::Event::Closed) {
                window.close();
            }
            
        }

        handler.update(window);

        window.clear();

        handler.render(window);

        window.display();
    }
    
    window.close();
    
    return EXIT_SUCCESS;
}


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Handler.hpp"
#include "ResourcePath.hpp"

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");
    
    Handler handler;

    while (window.isOpen())
    {

        handler.update(window);

        window.clear();

        handler.render(window);

        window.display();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

sf::RenderWindow Menu(sf::RenderWindow&);

int main(int argc, char const** argv)
{
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SideScroller", sf::Style::Fullscreen);
    
    Menu(window);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        

        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}

sf::RenderWindow Menu(sf::RenderWindow&){
    
}

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

static void Runtime(sf::RenderWindow *window);

int main(int argc, char const** argv){
    
    //std::thread runtime;
    
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SideScroller");
    
    //runtime = thread(&Runtime, window);
    
    auto runtime = thread(Runtime, window);
    
    sleep(1);
    
    window->close();

    // Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed || !runtime.joinable()) {
                window->close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window->close();
            }
        }
        
        

        // Update the window
        window->display();
    }
    
    runtime.detach();
    
    return EXIT_SUCCESS;
}

static void Runtime(sf::RenderWindow *window){ // Where all game actions and events are handled
    this_thread::sleep_for(std::chrono::seconds(1));
    cout << window->getSize().x << endl;
    cout << window->getSize().y << endl;
    int counter = 0;
    while(window->isOpen()){
        cout << counter++ << endl;
        window->clear();
    }
    
}

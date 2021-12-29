#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameBody.cpp"
using namespace std;

void onUpdate(sf::RenderWindow window, GameBody Body){

}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Springs =_=");
    sf::View view = window.getDefaultView();
    view.setSize(800, -600);
    window.setView(view);
    GameBody Body(sf::Vector2f(300,300),sf::Vector2f(0,0));
    window.setFramerateLimit(850);
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::A)
                {
                    Body.m_w += 0.1;
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    Body.m_w -= 0.1;
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    Body.speed.x += 1;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    Body.speed.x -= 1;
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    Body.speed.x = 0;
                }

            }
        }





        Body.update();
        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(Body);
        // Update the window
        window.display();
    }



    return 0;
}

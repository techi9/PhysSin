#include <iostream>
#include <SFML/Graphics.hpp>
#include "Body.h"
using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Springs =_=");
    sf::View view = window.getDefaultView();
    view.setSize(800, -600);
    window.setView(view);


    State state, dx;
    dx.sp1Length = 0;
    dx.sp2Length = 0;
    state.pos = Vector2f(400, 300);

    Body body;
    dx = body.f(state);
    state.add(dx);



    window.setFramerateLimit(144);
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

                }
                if (event.key.code == sf::Keyboard::D)
                {

                }
                if (event.key.code == sf::Keyboard::W)
                {

                }
                if (event.key.code == sf::Keyboard::S)
                {

                }
                if (event.key.code == sf::Keyboard::Space)
                {

                }

            }
        }




        // Clear screen
        window.clear();
        // Draw the sprite
//        window.draw(Body);

        // Update the window
        window.display();
    }



    return 0;
}

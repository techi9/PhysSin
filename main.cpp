#include <iostream>
#include <SFML/Graphics.hpp>
#include "Body.h"
#include "RungeeKutta4.h"
using namespace std;


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Springs =_=");
    sf::View view = window.getDefaultView();
    view.setSize(800, -600);
    window.setView(view);

    const float h = 0.05;

    State state;
    state.pos = Vector2f(400, 200);
    state.sp1Length = 80;
    state.sp2Length = 80;

    Body body;
    RungeeKutta4 rg4;




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
                    state.w += 0.01;
                }
                if (event.key.code == sf::Keyboard::D)
                {
                    state.w += -0.01;
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    state.speed.x += 5;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    state.speed.x -= 5;
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    state.speed.x = 0;
                }

            }
        }


        State dx;
        dx = rg4.solve(body, state, h); // body - это объект содержащий функцию f(), state - состояние системы и h шаг.
        state.add(dx);


        // Clear screen
        window.clear();
        // Draw the sprite
        window.draw(state);

        // Update the window
        window.display();
    }



    return 0;
}

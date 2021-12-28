#ifndef PHYSSIN_SPRING_H
#define PHYSSIN_SPRING_H

#include "string"
#include "math.h"
#include "SFML/Graphics.hpp"
#include "iostream"

using namespace std;
using sf::Vector2f;

class spring : public sf::Drawable{

    float k = 0.0005;

    Vector2f pos;
    double length = 80;


public:
    sf::RectangleShape line;
    sf::Vector2f getForce();
    spring(int offsetFromCenter, sf::Vector2f p);
    double curLength = 80;
    float update(sf::Vector2f newPos, float ang);
    double offset;


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(line, states);
    }
};


#endif //PHYSSIN_SPRING_H

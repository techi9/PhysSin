#ifndef PHYSSIN_SPRING_H
#define PHYSSIN_SPRING_H

#include "string"
#include <cmath>
#include "SFML/Graphics.hpp"
#include "iostream"

using namespace std;
using sf::Vector2f;

class spring : public sf::Drawable{
public:
    float k = 0.5;

    Vector2f pos;
    double length = 80;

    sf::RectangleShape line;
    spring(int offsetFromCenter, sf::Vector2f p);
    spring() = default;
    double curLength = 80;
    float update(sf::Vector2f newPos, float ang, bool conserveState, double& curlength);
    double offset;


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(line, states);
    }
};


#endif //PHYSSIN_SPRING_H

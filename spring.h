#ifndef PHYSSIN_SPRING_H
#define PHYSSIN_SPRING_H

#include "string"
#include "math.h"
#include "SFML/Graphics.hpp"

using namespace std;
using sf::Vector2f;

class spring : public sf::Drawable{
    Vector2f pos;
    double length = 60;
    double curLength = 60;
    spring(double offset);
    void update(sf::Vector2f newPos);
    sf::Vector2f getForce();

public:
    double offset;
};


#endif //PHYSSIN_SPRING_H

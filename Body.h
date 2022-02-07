#ifndef PHYSSIN_BODY_H
#define PHYSSIN_BODY_H

#include "SFML/Graphics.hpp"
#include "State.h"
#include <array>

using namespace sf;
using namespace std;




class Body{
public:
    const float BODY_SIZEX = 256, BODY_SIZEY = 128,spOffset = 110 , defaultSpLength = 100;
    const float G = -9.8, kR = 0.1, k_spring = 0.4, r_m = (1.0f / 12.0f) * (BODY_SIZEX * BODY_SIZEX + BODY_SIZEY * BODY_SIZEY) * 1; // rotational mass;

    Body() = default;

    virtual State f(const State &state);

private:
    array<Vector2f, 6> localCoords; // 0, 1 is springs
    array<Vector2f, 2> spCoords; //end of spring coords
    void createLocalCoord(const State& state);
    void rotate(float angle);
};


#endif //PHYSSIN_BODY_H

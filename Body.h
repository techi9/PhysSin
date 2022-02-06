#ifndef PHYSSIN_BODY_H
#define PHYSSIN_BODY_H

#include "SFML/Graphics.hpp"
#include <array>

using namespace sf;
using namespace std;



struct State : Drawable {
    Vector2f pos, speed, sp1Pos, sp2Pos;
    float angle = 0, sp1Length = 40, sp2Length = 40, w = 0;

    void add(const State& state){
        pos += state.pos;
        speed += state.speed;
        angle += state.angle;
        sp1Length += state.sp1Length;
        sp2Length += state.sp2Length;
        w += state.w;
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {

    }
};

class Body {
public:
    const float BODY_SIZEX = 256, BODY_SIZEY = 128,spOffset = 110 , defaultSpLength = 40;
    const float G = -9.8, kElast = 0.8, k_spring = 0.5, r_m = (1.0f/12.0f) * (BODY_SIZEX*BODY_SIZEX + BODY_SIZEY*BODY_SIZEY) * 1; // rotational mass;

    Body() = default;

    State f(State state);

private:
    array<Vector2f, 6> localCoords; // 0, 1 is springs
    array<Vector2f, 2> spCoords; //end of spring coords
    void createLocalCoord(State state);
    void rotate(float angle);
};


#endif //PHYSSIN_BODY_H

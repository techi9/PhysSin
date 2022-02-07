#ifndef PHYSSIN_STATE_H
#define PHYSSIN_STATE_H

#include "SFML/Graphics.hpp"

struct State : sf::Drawable {
    sf::Vector2f pos, speed;
    float angle = 0, sp1Length = 0, sp2Length = 0, w = 0;

    State* add(const State& state){
        pos += state.pos;
        speed += state.speed;
        angle += state.angle;
        sp1Length += state.sp1Length;
        sp2Length += state.sp2Length;
        w += state.w;
        return this;
    }

    State* mul(const float k){
        pos *= k;
        speed *= k;
        angle *= k;
        sp1Length *= k;
        sp2Length *= k;
        w *= k;
        return this;
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif //PHYSSIN_STATE_H

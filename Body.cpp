#include "Body.h"
#include <cmath>

#define FLOOR 50

State Body::f(const State state) {
    State dx;
    dx.sp1Length = 0;
    dx.sp2Length = 0;
    createLocalCoord(state);
    rotate(state.angle);

    for(auto& el: localCoords){
        if((state.pos + el).y < FLOOR){// body collision
            dx.speed.y -= state.speed.y;
            dx.pos.y += 10;
        }
    }

    for (int i = 0; i<spCoords.size(); i++){

        dx.sp1Length += state.sp1Length + 10 < defaultSpLength ? 10 : defaultSpLength - state.sp1Length; //extend springs
        dx.sp2Length += state.sp2Length + 10 < defaultSpLength ? 10 : defaultSpLength - state.sp2Length;

        if ((state.pos + spCoords[i]).y < FLOOR){ //spring collision

            if(i == 0){ //left
                float F = k_spring*(defaultSpLength - state.sp1Length);
                dx.w += kElast * -spOffset * F / r_m;        //k * r(+-spoffset) /r_m
                dx.speed.y += F;
            }
            else{ //right
                float F = k_spring*(defaultSpLength - state.sp2Length);
                dx.w += kElast * spOffset * F / r_m;
                dx.speed.y += F;
            }

        }
    }

    //update pos and angle
    dx.pos += state.speed;
    dx.angle += state.w;
    //gravitation
    dx.speed.y += G;

    return dx;
}

void Body::rotate(float angle) {
    for (auto &el: localCoords) {
        el.x = el.x * cos(angle) - el.y * sin(angle);
        el.y = el.x * sin(angle) + el.y * cos(angle);
    }

    for (auto &el: spCoords) {
        el.x = el.x * cos(angle) - el.y * sin(angle);
        el.y = el.x * sin(angle) + el.y * cos(angle);
    }
}

void Body::createLocalCoord(State state) { //TODO: make it friend
    localCoords = {Vector2f(-spOffset, 0), Vector2f(spOffset, 0),
                   Vector2f(-BODY_SIZEX/2, BODY_SIZEY/2),
                   Vector2f(BODY_SIZEX/2, BODY_SIZEY/2),
                   Vector2f(-BODY_SIZEX/2, -BODY_SIZEY/2),
                   Vector2f(BODY_SIZEX/2, -BODY_SIZEY/2)};
    spCoords = {Vector2f(-spOffset, -state.sp1Length), Vector2f(spOffset, -state.sp2Length)};
}

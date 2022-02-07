#include "Body.h"
#include <cmath>
#include <iostream>

#define FLOOR 50
#define TICK 5.0f

State Body::f(const State& state) {
    State dx;
    dx.sp1Length = 0;
    dx.sp2Length = 0;
    createLocalCoord(state);
    rotate(state.angle);

//    cout<< "sp coord:"<<(state.pos + spCoords[0]).y<< "    body coord  "<< (state.pos + localCoords[0]).y<< "      sp1len " << state.sp1Length<<endl;

    for(auto& el: localCoords){
        if((state.pos + el).y < FLOOR){// body collision
            dx.speed.y -= state.speed.y;
            dx.w -= state.w;
            dx.pos.y += 20;
        }
    }

//    if (state.pos.y + localCoords[0].y + state.sp1Length > FLOOR){
//        dx.sp1Length += state.pos.y + localCoords[0].y + state.sp1Length - FLOOR;
//    }



    for (int i = 0; i<spCoords.size(); i++){



        if ((state.pos + spCoords[i]).y < FLOOR){ //spring collision

            if(i == 0){ //left
                float F = k_spring*(defaultSpLength - state.sp1Length);
                dx.w += kR * -spOffset * F / r_m;        //k * r(+-spoffset) /r_m
                dx.speed.y += F;
                dx.sp1Length -= FLOOR - (state.pos + spCoords[0]).y;
            }
            else{ //right
                float F = k_spring*(defaultSpLength - state.sp2Length);
                dx.w += kR * spOffset * F / r_m;
                dx.speed.y += F;
                dx.sp2Length -= FLOOR - (state.pos + spCoords[1]).y;
            }
        }
    }




    dx.sp1Length += state.sp1Length + TICK < defaultSpLength ? TICK : defaultSpLength - state.sp1Length; //extend springs
    dx.sp2Length += state.sp2Length + TICK < defaultSpLength ? TICK : defaultSpLength - state.sp2Length;
    if( state.pos.y + spCoords[0].y < FLOOR){
        dx.sp1Length += -(FLOOR - (state.pos.y + spCoords[0].y));
    }
    if( state.pos.y + spCoords[1].y < FLOOR){
        dx.sp2Length += -(FLOOR - (state.pos.y + spCoords[1].y));
    }


    //if(defaultSpLength - state.sp2Length + spCoords[i].y > FLOOR) { dx.sp1length +=  defaultSpLength - state.sp2Length} else { dx.sp1length += FLOOR - spCoords[i].y }

    //update pos and angle
    dx.pos += state.speed;
    dx.angle += state.w;

    //drag
    dx.w -= state.w*0.08f;
    dx.speed.y -= state.speed.y*0.05f;

    //gravitation
    dx.speed.y += G;

    return dx;
}

void Body::rotate(float angle) {
    for (auto &el: localCoords) {
        float tx = el.x;
        float ty = el.y;
        el.x = tx * cos(angle) - ty * sin(angle);// x*cos(angle) - y*sin(angle)
        el.y = tx * sin(angle) + ty * cos(angle);
    }

    for (auto &el: spCoords) {
        float tx = el.x;
        float ty = el.y;
        el.x = tx * cos(angle) - ty * sin(angle);
        el.y = tx * sin(angle) + ty * cos(angle);
    }
}

void Body::createLocalCoord(const State& state) {
    localCoords = {Vector2f(-spOffset, -BODY_SIZEY/2), Vector2f(spOffset, -BODY_SIZEY/2),
                   Vector2f(-BODY_SIZEX/2, BODY_SIZEY/2),
                   Vector2f(BODY_SIZEX/2, BODY_SIZEY/2),
                   Vector2f(-BODY_SIZEX/2, -BODY_SIZEY/2),
                   Vector2f(BODY_SIZEX/2, -BODY_SIZEY/2)};
    spCoords = {Vector2f(-spOffset, -state.sp1Length - BODY_SIZEY/2), Vector2f(spOffset, -state.sp2Length - BODY_SIZEY/2)};
}



#include "SFML/Graphics.hpp"
#include "string"
#include "math.h"
#include "iostream"
#include "spring.h"
#define h 0.003
//#define gravity -0.0001
#define gravity -9.8
#define sizeX 256
#define sizeY 128

#define kElast 1
using namespace std;
using sf::Vector2f;
class GameBody : public sf::Drawable{
private:



public:

    struct State{

        spring sp1; //springs
        spring sp2;

        sf::Vector2f sp1Pos = sf::Vector2f(0,0);
        double sp1Length = 0;
        sf::Vector2f sp2Pos = sf::Vector2f(0,0);
        double sp2Length = 0;

        //body
        sf::ConvexShape m_rect; //local coordinates
        Vector2f speed = sf::Vector2f(0,0);
        Vector2f pos = sf::Vector2f(0,0);
        float m_w = 0;

        sf::Vector2f pointSp1 = sf::Vector2f(0,0);
        sf::Vector2f pointSp2 = sf::Vector2f(0,0);

        State add(State left, State right){

            left.sp1Pos = left.sp1Pos + right.sp1Pos;
            left.sp2Pos = left.sp2Pos + right.sp2Pos;

            left.sp1Length += right.sp1Length;
            left.sp2Length += right.sp2Length;

            left.speed += right.speed;
            left.pos += right.pos;

            left.m_w += right.m_w;

            left.pointSp1 += right.pointSp1;
            left.pointSp2 += right.pointSp2;


            return left;
        }

        State mul(State left, float right){

            left.sp1Pos = left.sp1Pos * right;
            left.sp2Pos = left.sp2Pos * right;

            left.sp1Length *= right;
            left.sp2Length *= right;

            left.speed *= right;
            left.pos *= right;

            left.m_w *= right;

            left.pointSp1 *= right;
            left.pointSp2 *= right;

            return left;
        }
    };

    State state;

    float weight = 1;



    float r_m = (1.0/12.0) * (sizeX*sizeX + sizeY*sizeY) * 1; // rotational mass


    GameBody(State& state ,Vector2f startPos, Vector2f startSpeed) {

        state.sp1 = spring(70,startPos);
        state.sp2 = spring(-70, startPos);


        state.speed = startSpeed;
        state.pos = startPos;
        state.m_rect.move(state.pos);
        state.m_rect.setPointCount(4);
        state.m_rect.setPoint(0, Vector2f(sizeX / 2.0, sizeY / 2.0 )); // локальные координаты
        state.m_rect.setPoint(1, Vector2f(sizeX / 2.0, -sizeY / 2.0));
        state.m_rect.setPoint(2, Vector2f(-sizeX / 2.0, -sizeY / 2.0));
        state.m_rect.setPoint(3, Vector2f(-sizeX/ 2.0, sizeY / 2.0));

        state.pointSp1.x = sizeX/2 - 40; // локальные точки крепления пружин
        state.pointSp1.y = -sizeY/2;
        state.pointSp2.x = -sizeX/2 + 40;
        state.pointSp2.y = -sizeY/2;

        state.sp1Length = 80;
        state.sp2Length = 80;


    }

    void applyRotation(float angle, State& state){ //TODO: add to state

        for(int i = 0; i < state.m_rect.getPointCount(); i++) {
            float tempX = state.m_rect.getPoint(i).x ;
            float tempY = state.m_rect.getPoint(i).y ;
            state.m_rect.setPoint(i,Vector2f(tempX*cos(angle) - tempY*sin(angle), tempX*sin(angle) + tempY*cos(angle)));
        }

        state.pointSp1=sf::Vector2f (state.pointSp1.x*cos(angle) - state.pointSp1.y*sin(angle), state.pointSp1.x*sin(angle)  + state.pointSp1.y*cos(angle));
        state.pointSp2=sf::Vector2f (state.pointSp2.x*cos(angle) - state.pointSp2.y*sin(angle), state.pointSp2.x*sin(angle)  + state.pointSp2.y*cos(angle));

    }

    void applyForce(sf::Vector2f point, sf::Vector2f vec, State& state){
        if(point.x < 0){
            state.m_w -=(kElast* sqrt(point.x*point.x + point.y*point.y) * sqrt(vec.x*vec.x + vec.y*vec.y)) / r_m; // k * r(+-spoffset) /r_m
        }
        else{
            state.m_w += (kElast* sqrt(point.x*point.x + point.y*point.y) * sqrt(vec.x*vec.x + vec.y*vec.y)) / r_m;
        }

        state.speed = sf::Vector2f(state.speed.x + vec.x, state.speed.y + vec.y);

    }



    State f(State state ,bool conserveState = true){


        State dx;

        dx.m_w =  0.9995 * state.m_w - state.m_w;
        dx.speed.x =  0.9997 * state.speed.x - state.speed.x;
        dx.speed.y =  0.9997 * state.speed.y - state.speed.y;

        //drag
        state.m_w = 0.9995 * state.m_w;
        state.speed.x = 0.9997 * state.speed.x;
        state.speed.y = 0.9997 * state.speed.y;


        for(int i = 0; i < state.m_rect.getPointCount(); i++) { //collision of rect
            // cout<<"Y="<<(pos + m_rect.getPoint(i)).y<<endl;
            if ((state.pos + state.m_rect.getPoint(i)).y <= 50) {
                state.pos.y += 30;
                state.speed.y = 0;
                state.speed.x = state.speed.x * 0.9995;


                dx.pos.y = 30;
                dx.speed.y = -state.speed.y;
                dx.speed.x =  0.9995 * state.speed.x - state.speed.x;

            }
        }

        sf::Vector2f posSp1Before = state.sp1.pos;
        sf::Vector2f posSp2Before = state.sp2.pos;
        double lengthSp1Before = state.sp1.length;
        double lengthSp2Before = state.sp2.length;

        sf::Vector2f vecSp1(0 ,state.sp1.update(sf::Vector2f(state.pos.x+ state.pointSp1.x, state.pos.y + state.pointSp1.y),state.m_w, conserveState, state.sp1Length));
        sf::Vector2f vecSp2(0,state.sp2.update(sf::Vector2f(state.pos.x+ state.pointSp2.x, state.pos.y + state.pointSp2.y),state.m_w, conserveState,state.sp2Length));

        dx.sp1Pos = sf::Vector2f(state.sp1.pos.x - posSp1Before.x, state.sp1.pos.y - posSp1Before.y);
        dx.sp2Pos = sf::Vector2f(state.sp2.pos.x - posSp2Before.x, state.sp2.pos.y - posSp2Before.y);

        dx.sp1Length = state.sp1.length - lengthSp1Before;
        dx.sp2Length = state.sp2.length - lengthSp2Before;

        float m_wBefore = state.m_w;
        sf::Vector2f speedBefore = state.speed;

        applyForce(sf::Vector2f(70, 0), sf::Vector2f(vecSp1.x, vecSp1.y), state); //changes m_w and speed
        applyForce(sf::Vector2f(-70, 0), sf::Vector2f(vecSp2.x, vecSp2.y), state);

        dx.m_w += state.m_w - m_wBefore;
        dx.speed = sf::Vector2f(dx.speed.x +(state.speed.x - speedBefore.x), dx.speed.y +(state.speed.y - speedBefore.y));

        state.pos.x += state.speed.x;
        state.pos.y += state.speed.y;
        state.speed.y += gravity;

        dx.speed.y += gravity;
        dx.pos.x += state.speed.x;
        dx.pos.y += state.speed.y;

       // applyRotation(state.m_w, state); // changes m_rect

        state.m_rect.setPosition(state.pos.x, state.pos.y);
        this->state.m_rect = state.m_rect;
        this->state.sp1 = state.sp1;
        this->state.sp2 = state.sp2;
        return dx;
    }


private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(state.m_rect, states);
        target.draw(state.sp1.line, states);
        target.draw(state.sp2.line, states);
    }
};
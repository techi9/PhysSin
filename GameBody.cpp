#include "SFML/Graphics.hpp"
#include "string"
#include "math.h"
#include "iostream"
#include "spring.h"
//#define gravity -0.0001
#define gravity -9.8
#define sizeX 256
#define sizeY 128

#define kElast 0.5
using namespace std;
using sf::Vector2f;
class GameBody : public sf::Drawable{
private:
    spring sp1;
    spring sp2;


public:
    sf::ConvexShape m_rect;
    float weight = 1;
    Vector2f speed;
    Vector2f pos;
    float m_w = 0;
    float r_m = 4.0/3.0 * sizeX * sizeY * (sizeX^2 + sizeY^2) * 1; // rotational mass
    vector<pair<float,float>> collisionPoints;

    GameBody(Vector2f startPos, Vector2f startSpeed): sp1(10,startPos), sp2(-10, startPos){


        speed = startSpeed;
        pos = startPos;
        m_rect.move(pos);
        m_rect.setPointCount(4);
        m_rect.setPoint(0, Vector2f(sizeX / 2.0, sizeY / 2.0 ));
        m_rect.setPoint(1, Vector2f(sizeX / 2.0, -sizeY / 2.0));
        m_rect.setPoint(2, Vector2f(-sizeX / 2.0, -sizeY / 2.0));
        m_rect.setPoint(3, Vector2f(-sizeX/ 2.0, sizeY / 2.0));


    }

    void applyRotation(float angle){// TODO: change points only on draw

        for(int i = 0; i < m_rect.getPointCount(); i++) {
            float tempX = m_rect.getPoint(i).x ;
            float tempY = m_rect.getPoint(i).y ;
            m_rect.setPoint(i,Vector2f(tempX*cos(angle) - tempY*sin(angle), tempX*sin(angle) + tempY*cos(angle)));
        }


    }

    void applyForce(sf::Vector2f point, sf::Vector2f vec){
        if(point.x < 0){
            m_w -=kElast* sqrt(point.x*point.x + point.y*point.y) * sqrt(vec.x*vec.x + vec.y*vec.y);
        }
        else{
            m_w += kElast* sqrt(point.x*point.x + point.y*point.y) * sqrt(vec.x*vec.x + vec.y*vec.y);
        }

        speed = sf::Vector2f(speed.x + vec.x, speed.y + vec.y);

    }

    void bounce(int indexOfVertex){

    }

    void update(){

        //drag
        m_w = 0.9995 * m_w;
        double h = 0.003;

        for(int i = 0; i < m_rect.getPointCount(); i++) {
           // cout<<"Y="<<(pos + m_rect.getPoint(i)).y<<endl;
            if ((pos + m_rect.getPoint(i)).y <= 0) {
                pos.y += 0.1;
                speed.y = 0;
                speed.x = speed.x * 0.9995;
            }
        }

//        speed.y += gravity * 0.5;
        pos.x += h*speed.x * 0.5;
        pos.y += h*speed.y * 0.5;
        speed.y += h*gravity;
        pos.x += h*speed.x * 0.5;
        pos.y += h*speed.y * 0.5;
        applyRotation(h*m_w);

        sp1.update(pos);
        sp2.update(pos);

        m_rect.setPosition(pos.x, pos.y);
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_rect, states);
        target.draw(sp1, states);
        target.draw(sp2, states);
    }
};
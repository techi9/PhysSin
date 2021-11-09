#include "SFML/Graphics.hpp"
#include "string"
#include "math.h"

#define gravity 0.0001
#define sizeX 256
#define sizeY 128
using namespace std;
using sf::Vector2f;
class GameBody : public sf::Drawable{

public:
    sf::ConvexShape m_rect;
    float weight = 1;
    Vector2f speed;
    Vector2f pos;
    sf::Vector2f m_w;
    float r_m = 4.0/3.0 * sizeX * sizeY * (sizeX^2 + sizeY^2) * 1; //
    vector<pair<float,float>> collisionPoints;

    GameBody(Vector2f startPos, Vector2f startSpeed){
        m_w.x = 0;
        m_w.y = 0;

        speed = startSpeed;
        pos = startPos;
        m_rect.move(pos);
        m_rect.setPointCount(4);
        m_rect.setPoint(0, Vector2f(sizeX / 2.0, sizeY / 2.0));
        m_rect.setPoint(1, Vector2f(sizeX / 2.0, -sizeY / 2.0));
        m_rect.setPoint(2, Vector2f(-sizeX / 2.0, -sizeY / 2.0));
        m_rect.setPoint(3, Vector2f(-sizeX/ 2.0, sizeY / 2.0));

    }

    void applyRotation(float angle){

        for(int i = 0; i < m_rect.getPointCount(); i++) {
            float tempX = m_rect.getPoint(i).x ;
            float tempY = m_rect.getPoint(i).y ;
            m_rect.setPoint(i,Vector2f(tempX*cos(angle) - tempY*sin(angle), tempX*sin(angle) + tempY*cos(angle)));
        }


    }
    sf::Vector2f cross(sf::Vector2f v, sf::Vector2f i){
        return sf::Vector2f(-i * v.y , i * v.x);
    }
    void applyForce(){}//TODO: implement
    void bounce(int indexOfVertex){ // r is m_rect.getPoint(indexOfVertex)  n - Normal (0,1)
        sf::Vector2f n(0,1);
        sf::Vector2f vp =  speed + cross(m_rect.getPoint(indexOfVertex), m_w);  //?? m_w.x m_w.y
        float vp_p = vp.x * n.x + vp.y * n.y;
        float j = -vp_p / (1/weight + (m_rect.getPoint(indexOfVertex).x * n.y - m_rect.getPoint(indexOfVertex).y * n.x) / r_m);
        sf::Vector2f jn = j*n;
        speed = speed + jn / weight;
        m_w = m_w + cross(m_rect.getPoint(indexOfVertex),jn) / r_m;

    }
    void update(){
        for(int i = 0; i < m_rect.getPointCount(); i++) {
            if ((pos + m_rect.getPoint(i)).y <= 0) {
                bounce(i);
            }
        }

//        speed.y += gravity * 0.5;
        pos.x += speed.x * 0.5;
        pos.y += speed.y * 0.5;
        speed.y += gravity;
        pos.x += speed.x * 0.5;
        pos.y += speed.y * 0.5;
        m_rect.setPosition(pos.x, pos.y);
    }

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(m_rect, states);
    }
};
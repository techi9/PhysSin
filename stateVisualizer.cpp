#include "Body.h"
#include "array"
#include <cmath>
#include "iostream"
using namespace sf;
using namespace std;


void State::draw(RenderTarget &target, sf::RenderStates states) const {

    const float BODY_SIZEX = 256, BODY_SIZEY = 128,spOffset = 110;

    array<Vector2f, 6> rectCoords = {Vector2f(-spOffset, -BODY_SIZEY/2), Vector2f(spOffset, -BODY_SIZEY/2),
                                     Vector2f(-BODY_SIZEX/2, BODY_SIZEY/2),
                                     Vector2f(BODY_SIZEX/2, BODY_SIZEY/2),
                                     Vector2f(-BODY_SIZEX/2, -BODY_SIZEY/2),
                                     Vector2f(BODY_SIZEX/2, -BODY_SIZEY/2)};

    for (auto &el: rectCoords) {
        float tx = el.x;
        float ty = el.y;
        el.x = tx * cos(angle) - ty * sin(angle);// x*cos(angle) - y*sin(angle)
        el.y = tx * sin(angle) + ty * cos(angle);
    }

//    array<vector>spCoords = {Vector2f(-spOffset, -sp1Length), Vector2f(spOffset, -sp2Length)};


    sf::ConvexShape rect;
    rect.setPointCount(4);

    rect.setPoint(0,rectCoords[2] + pos);
    rect.setPoint(1,rectCoords[3]+ pos);
    rect.setPoint(2,rectCoords[5]+ pos);
    rect.setPoint(3,rectCoords[4]+pos);

//    rect.setPosition(pos);
    rect.setFillColor(Color::Yellow);

    RectangleShape line1, line2; //springs
//    line1.setSize(Vector2f(20, sp1Length));
    line1.setSize(Vector2f(20, -sp1Length));
    line1.setFillColor(sf::Color::Green);
    line1.setPosition(pos+rectCoords[0]);
    line1.setRotation(angle * 180.0f/M_PI);

//    line2.setSize(Vector2f(20, sp2Length));
    line2.setSize(Vector2f(-20, -sp2Length));
    line2.setFillColor(sf::Color::Green);
    line2.setPosition(pos+rectCoords[1]);
    line2.setRotation(angle * 180.0f/M_PI);

//  floor

    RectangleShape floor;
    floor.setSize(Vector2f(10000, -50));
    floor.setFillColor(sf::Color::Magenta);
    floor.setPosition(Vector2f(-500, 50));

    target.draw(rect, states);
    target.draw(line1, states);
    target.draw(line2, states);
    target.draw(floor,states);



}
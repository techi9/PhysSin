//
// Created by tucha on 07.12.2021.
//

#include "spring.h"

float spring::update(sf::Vector2f newPos, float ang) {
    pos = newPos;

    if(pos.y - curLength < 50){
        curLength -= 0.3;
    }
    else{
        if(curLength<length)
            curLength += 0.3;
    }


    line.setPosition(pos.x, pos.y);
    line.setSize(sf::Vector2f(curLength, 15));
    ang *= 180/M_PI;
    line.rotate(ang);

    return k*(length-curLength);
}

spring::spring(int offsetFromCenter, sf::Vector2f p) {
    line.setPosition(offsetFromCenter + p.x, p.y);
    line.setSize(sf::Vector2f(length, 30));
    offset = offsetFromCenter;
    line.setFillColor(sf::Color::Yellow);
    line.rotate(90+180);
}

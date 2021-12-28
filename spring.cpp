//
// Created by tucha on 07.12.2021.
//

#include "spring.h"

void spring::update(sf::Vector2f newPos) {
    pos = newPos;
    line.setPosition(offset + pos.x, pos.y);
    line.setSize(sf::Vector2f(length, 4));
}

spring::spring(int offsetFromCenter, sf::Vector2f p) {
    line.setPosition(offsetFromCenter + p.x, p.y);
    line.setSize(sf::Vector2f(length, 4));
    offset = offsetFromCenter;
    line.setFillColor(sf::Color::White);
}

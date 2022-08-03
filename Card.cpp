//
// Created by User on 04/05/2022.
//
#include "Card.h"
#include <iostream>
Card::Card(std::string name) : m_name(name){}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    card.print(os);
    return os;
}




//
// Created by itayk on 11/06/2022.
//
#include "Fighter.h"
Fighter::Fighter(std::string name): Player(name,"Fighter") {}

int Fighter::getAttackStrength() const{
    return m_level + 2*m_force;
}
//
// Created by itayk on 11/06/2022.
//
#include "Rogue.h"
Rogue::Rogue(std::string name): Player(name, "Rogue"){}

void Rogue::addCoins(int coins){
    if(coins < 0){
        coins = 0;
    }

    this->m_coins += (2*coins);
}

std::string Rogue::getType() const {
    return this->m_type;
}

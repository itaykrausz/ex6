//
// Created by itayk on 11/06/2022.
//
#include "Treasure.h"
#define TREASURE_COINS 10
Treasure::Treasure() : Card("Treasure"), m_loot(TREASURE_COINS) {}

void Treasure::applyEncounter(Player &player) const {
    player.addCoins(this->m_loot);
    printTreasureMessage();
}

std::ostream &Treasure::print(std::ostream &os) const {
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
    return os;
}
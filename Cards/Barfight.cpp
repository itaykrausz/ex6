//
// Created by itayk on 11/06/2022.
//
#include "Barfight.h"
#define BARFIGHT_DAMAGE 10

Barfight::Barfight() : SpecificCards("Barfight"), m_damage(BARFIGHT_DAMAGE){}

void Barfight::applyEncounter(Player& player) const{
    if(player.getType() == "Fighter"){
        printBarfightMessage(true);
        return;
    }
    player.damage(this->m_damage);
    printBarfightMessage(false);
}


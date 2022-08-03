//
// Created by itayk on 11/06/2022.
//
#include "Pitfall.h"
#define PITFALL_DAMAGE 10

Pitfall::Pitfall() : SpecificCards("Pitfall"), m_damage(PITFALL_DAMAGE){}

void Pitfall::applyEncounter(Player& player) const{
    if(player.getType() == "Rogue"){
        printPitfallMessage(true);
        return;
    }
    player.damage(this->m_damage);
    printPitfallMessage(false);
}


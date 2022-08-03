//
// Created by itayk on 11/06/2022.
//
#include "Fairy.h"
#define FAIRY_GAIN 10

Fairy::Fairy() : SpecificCards("Fairy"), m_gain(FAIRY_GAIN){}

void Fairy::applyEncounter(Player& player) const{
    if(player.getType() != "Wizard"){
        printFairyMessage(false);
        return;
    }
    player.heal(this->m_gain);
    printFairyMessage(true);
}

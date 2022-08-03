//
// Created by itayk on 11/06/2022.
//
#include "Fairy.h"
#include "../Players/Wizard.h"
#define FAIRY_GAIN 10

Fairy::Fairy() : SpecificCards("Fairy"), m_gain(FAIRY_GAIN){}

void Fairy::applyEncounter(Player& player) const{
    try{
        Wizard& plr=dynamic_cast<Wizard&>(player);
    } catch (const std::bad_cast&){
        printFairyMessage(false);
        return;
    }
    player.heal(this->m_gain);
    printFairyMessage(true);
}

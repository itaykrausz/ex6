//
// Created by itayk on 11/06/2022.
//
#include "Pitfall.h"
#include "../Players/Rogue.h"
#define PITFALL_DAMAGE 10

Pitfall::Pitfall() : SpecificCards("Pitfall"), m_damage(PITFALL_DAMAGE){}

void Pitfall::applyEncounter(Player& player) const{
    try{
        dynamic_cast<Rogue&>(player);
    } catch(const std::bad_cast&){
        player.damage(this->m_damage);
        printPitfallMessage(false);
        return;
    }
    printPitfallMessage(true);
}
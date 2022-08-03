//
// Created by itayk on 11/06/2022.
//
#include "Barfight.h"
#include "../Players/Fighter.h"
#define BARFIGHT_DAMAGE 10

Barfight::Barfight() : SpecificCards("Barfight"), m_damage(BARFIGHT_DAMAGE){}

void Barfight::applyEncounter(Player& player) const{
    try{
        dynamic_cast<Fighter&>(player);
    } catch (const std::bad_cast&){
        player.damage(this->m_damage);
        printBarfightMessage(false);
        return;
    }
    printBarfightMessage(true);
}


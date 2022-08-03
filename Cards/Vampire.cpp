//
// Created by User on 11/06/2022.
//
#include "Vampire.h"
#define VAMPIRE_FORCE_LOSS 1

Vampire::Vampire() : MonsterCard("Vampire"){}

void Vampire::applyEncounter(Player &player) const {
    if(player.getAttackStrength()<this->m_force){
        player.damage(this->m_damage);
        player.loseForce(VAMPIRE_FORCE_LOSS);
        printLossBattle(player.getName(),this->m_name);
    }
    else{
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(),this->m_name);
    }
}

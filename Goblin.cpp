//
// Created by User on 11/06/2022.
//
#include "Goblin.h"

Goblin::Goblin() : MonsterCard("Goblin"){}

void Goblin::applyEncounter(Player &player) const {
    if(player.getAttackStrength()<this->m_force){
        player.damage(this->m_damage);
        printLossBattle(player.getName(),this->m_name);
    }
    else{
        player.levelUp();
        player.addCoins(this->m_loot);
        printWinBattle(player.getName(),this->m_name);
    }
}

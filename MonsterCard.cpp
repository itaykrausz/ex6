//
// Created by User on 11/06/2022.
//
#define DRAGON_LOOT 1000
#define DRAGON_FORCE 25
#define VAMPIRE_LOOT 2
#define VAMPIRE_FORCE 10
#define GOBLIN_LOOT 2
#define GOBLIN_FORCE 6
#define DRAGON_DAMAGE 100
#define GOBLIN_DAMAGE 10
#define VAMPIRE_DAMAGE 10
#define VAMPIRE_FORCE_LOSS 1

#include "MonsterCard.h"
#include "../utilities.h"

MonsterCard::MonsterCard(std::string name) : Card(name){
    if(this->m_name=="Dragon"){
        this->m_force=DRAGON_FORCE;
        this->m_loot=DRAGON_LOOT;
        this->m_damage=DRAGON_DAMAGE;
    }
    if(this->m_name=="Vampire"){
        this->m_force=VAMPIRE_FORCE;
        this->m_loot=VAMPIRE_LOOT;
        this->m_damage=VAMPIRE_DAMAGE;
    }
    if(this->m_name=="Goblin"){
        this->m_force=GOBLIN_FORCE;
        this->m_loot=GOBLIN_LOOT;
        this->m_damage=GOBLIN_DAMAGE;
    }
    if(this->m_name=="Gang"){
        this->m_force=0;
        this->m_loot=0;
        this->m_damage=0;
    }
}

std::ostream &MonsterCard::print(std::ostream &os) const {
    printCardDetails(os, this->m_name);
    printMonsterDetails(os,this->m_force,this->m_damage,this->m_loot,this->m_name=="Dragon");
    printEndOfCardDetails(os);
    return os;
}

void MonsterCard::applyLoss(Player &player) const {
    if(this->m_name=="Dragon"){
        player.damage(this->m_damage);
        printLossBattle(player.getName(),this->m_name);
    }
    if(this->m_name=="Goblin"){
        player.damage(this->m_damage);
        printLossBattle(player.getName(),this->m_name);
    }
    if(this->m_name=="Vampire"){
        player.damage(this->m_damage);
        player.loseForce(1);
        printLossBattle(player.getName(),this->m_name);
    }
}

bool MonsterCard::applyGangEncounter(Player &player) {
    if(player.getAttackStrength()<this->m_force){
        player.damage(this->m_damage);
        if(this->m_name=="Vampire"){
            player.loseForce(VAMPIRE_FORCE_LOSS);
        }
        printLossBattle(player.getName(),this->m_name);
        return false;
    }
    player.addCoins(this->m_loot);
    return true;
}
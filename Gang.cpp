//
// Created by Omer Ran on 20/06/2022.
//
#include "Gang.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Vampire.h"
#include "../Exception.h"
Gang::Gang() : MonsterCard("Gang"){}

void Gang::applyEncounter(Player &player) const {
    bool won = false;
    for(int i=0; i<(int)(this->m_gang).size();i++){
        if((*this->m_gang[i]).applyGangEncounter(player)){
            won = true;
        }
        else{
            won=false;
            lost(player, i+1);
            break;
        }
    }
    if(won){
        player.levelUp();
        printWinBattle(player.getName(),this->m_name);
    }
}

void Gang::lost(Player &player, int index) const {
    for(int i=index;i<(int)(this->m_gang).size();i++){
        (*this->m_gang[i]).applyLoss(player);
    }
}

void Gang::addCardtoGang(const std::string& name, int line) {
    if(name=="Dragon"){
        std::unique_ptr<MonsterCard> ptr (new Dragon());
        this->m_gang.push_back(std::move(ptr));
        return;
    }
    if(name=="Vampire"){
        std::unique_ptr<MonsterCard> ptr (new Vampire());
        this->m_gang.push_back(std::move(ptr));
        return;
    }
    if(name=="Goblin"){
        std::unique_ptr<MonsterCard> ptr (new Goblin());
        this->m_gang.push_back(std::move(ptr));
        return;
    }
    throw DeckFileFormatError(line);
}
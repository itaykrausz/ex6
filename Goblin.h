//
// Created by User on 11/06/2022.
//
#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H
#include "MonsterCard.h"
#include "../Players/Player.h"
class Goblin : public MonsterCard{
public:
    Goblin();
    void applyEncounter(Player& player) const override;
};
#endif //EX4_GOBLIN_H

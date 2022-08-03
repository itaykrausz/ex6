//
// Created by User on 11/06/2022.
//
#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H
#include "MonsterCard.h"
#include "../Players/Player.h"
class Vampire : public MonsterCard{
public:
    Vampire();
    void applyEncounter(Player& player) const override;
};
#endif //EX4_VAMPIRE_H

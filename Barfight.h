//
// Created by itayk on 11/06/2022.
//
#include "SpecificCards.h"
#ifndef EX4CURRENT_BARFIGHT_H
#define EX4CURRENT_BARFIGHT_H

class Barfight : public SpecificCards{
    int m_damage;
public:
    Barfight();
    void applyEncounter(Player& player) const override;
};


#endif //EX4CURRENT_BARFIGHT_H

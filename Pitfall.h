//
// Created by itayk on 11/06/2022.
//
#include "SpecificCards.h"
#ifndef EX4CURRENT_PITFALL_H
#define EX4CURRENT_PITFALL_H

class Pitfall : public SpecificCards{
    int m_damage;
public:
    Pitfall();
    void applyEncounter(Player& player) const override;
};

#endif //EX4CURRENT_PITFALL_H

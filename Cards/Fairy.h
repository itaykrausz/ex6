//
// Created by itayk on 11/06/2022.
//
#include "SpecificCards.h"
#ifndef EX4CURRENT_FAIRY_H
#define EX4CURRENT_FAIRY_H

class Fairy : public SpecificCards{
    int m_gain;
public:
    Fairy();
    void applyEncounter(Player& player) const override;
};

#endif //EX4CURRENT_FAIRY_H

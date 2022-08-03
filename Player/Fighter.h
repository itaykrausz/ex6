//
// Created by itayk on 11/06/2022.
//

#ifndef EX4CURRENT_FIGHTER_H
#define EX4CURRENT_FIGHTER_H
#include "Player.h"

class Fighter : public Player{
public:
    Fighter(std::string name);
    int getAttackStrength() const override;
};


#endif //EX4CURRENT_FIGHTER_H
//
// Created by itayk on 11/06/2022.
//

#ifndef EX4CURRENT_ROGUE_H
#define EX4CURRENT_ROGUE_H
#include "Player.h"

class Rogue : public Player{
public:
    Rogue(std::string name);
    void addCoins(int coins) override;
};


#endif //EX4CURRENT_ROGUE_H

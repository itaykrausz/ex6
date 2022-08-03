//
// Created by itayk on 11/06/2022.
//

#ifndef EX4CURRENT_WIZARD_H
#define EX4CURRENT_WIZARD_H
#include "Player.h"

class Wizard : public Player{
public:
    Wizard(std::string name);
    void heal(int HP) override;
};


#endif //EX4CURRENT_WIZARD_H

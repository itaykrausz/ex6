//
// Created by itayk on 11/06/2022.
//

#ifndef EX4CURRENT_TREASURE_H
#define EX4CURRENT_TREASURE_H
#include "Card.h"
class Treasure : public Card{
    int m_loot;
public:
    Treasure();
    void applyEncounter(Player& player) const override;
    std::ostream& print(std::ostream& os) const override;
};


#endif //EX4CURRENT_TREASURE_H

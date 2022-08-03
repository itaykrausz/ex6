//
// Created by User on 11/06/2022.
//
#ifndef EX4_MONSTERCARD_H
#define EX4_MONSTERCARD_H
#include "Card.h"
#include "../Players/Player.h"
#include <string>
class MonsterCard: public Card{
protected:
    int m_force;
    int m_loot;
    int m_damage;
public:
    MonsterCard(std::string name);
    std::ostream& print(std::ostream& os) const override;
    void applyLoss(Player &player) const;
    bool applyGangEncounter(Player &player);
    void applyEncounter(Player &player) const override;
};
#endif //EX4_MONSTERCARD_H

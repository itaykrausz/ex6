//
// Created by Omer Ran on 20/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H
#include "MonsterCard.h"
#include <memory>
#include <vector>
class Gang : public MonsterCard{
    std::vector<std::unique_ptr<MonsterCard>> m_gang;
public:
    Gang();
    void applyEncounter(Player& player) const override;
    void lost(Player& player, int index) const;
    void addCardtoGang(const std::string& name, int line);
};

#endif //EX4_GANG_H

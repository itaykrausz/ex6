//
// Created by User on 11/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "Card.h"
class Merchant : public Card{
public:
    Merchant();
    void applyEncounter(Player &player) const override;
    std::ostream& print(std::ostream& os) const override;
    void handleHealCase(Player &player) const;
    void handleBuffCase(Player &player) const;
};
#endif //EX4_MERCHANT_H

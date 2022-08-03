//
// Created by User on 11/06/2022.
//
#include "../Players/Player.h"
#include "Card.h"
#ifndef EX4_SPECIFICCARDS_H
#define EX4_SPECIFICCARDS_H

class SpecificCards: public Card{

public:
    SpecificCards(std::string name);
    std::ostream& print(std::ostream& os) const override;
};

#endif //EX4_SPECIFICCARDS_H

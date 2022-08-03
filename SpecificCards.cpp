//
// Created by itayk on 11/06/2022.
//
#include "SpecificCards.h"
SpecificCards::SpecificCards(std::string card) : Card(card) {}

std::ostream &SpecificCards::print(std::ostream &os) const {
    printCardDetails(os,this->m_name);
    printEndOfCardDetails(os);
    return os;
}
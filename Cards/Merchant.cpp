//
// Created by User on 11/06/2022.
//
#include "Merchant.h"
#include <string>
#include <iostream>
#include <exception>
#define MERCHANT_SKIP 0
#define MERCHANT_HEAL_COST 5
#define MERCHANT_FORCE_COST 10
#define MERCHANT_BUFF_AND_HEAL 1

Merchant::Merchant() : Card("Merchant"){}

void Merchant::applyEncounter(Player &player) const {
    printMerchantInitialMessageForInteractiveEncounter(std::cout,player.getName(),player.getCoins());
    std::string numInString;
    int numInserted=4;
    while(numInserted>2 || numInserted<0){
        std::getline(std::cin,numInString);
        try{
            numInserted = std::stoi(numInString);
        } catch (std::exception &e){
            printInvalidInput();
            continue;
        }
        if(numInserted>2 || numInserted<0){
            printInvalidInput();
            //std::getline(std::cin,numInString);
            //numInserted = std::stoi(numInString);
        }
    }

    if(numInserted==2){
        handleBuffCase(player);
    }
    if(numInserted==1){
        handleHealCase(player);
    }
    if(numInserted==0){
        printMerchantSummary(std::cout,player.getName(),MERCHANT_SKIP,MERCHANT_SKIP);
        return;
    }
}

void Merchant::handleHealCase(Player &player) const {
    if(player.getCoins()<MERCHANT_HEAL_COST){
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(),1,MERCHANT_SKIP);
        return;
    }
    player.heal(MERCHANT_BUFF_AND_HEAL);
    player.pay(MERCHANT_HEAL_COST);
    printMerchantSummary(std::cout,player.getName(),1,MERCHANT_HEAL_COST);
}

void Merchant::handleBuffCase(Player &player) const {
    if(player.getCoins()<MERCHANT_FORCE_COST){
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,player.getName(),2,MERCHANT_SKIP);
        return;
    }
    player.buff(MERCHANT_BUFF_AND_HEAL);
    player.pay(MERCHANT_FORCE_COST);
    printMerchantSummary(std::cout,player.getName(),2,MERCHANT_FORCE_COST);
}

std::ostream &Merchant::print(std::ostream &os) const {
    printCardDetails(std::cout,this->m_name);
    printEndOfCardDetails(os);
    return os;
}
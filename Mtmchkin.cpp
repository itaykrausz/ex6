//
// Created by Omer Ran on 13/06/2022.
//
#include "Mtmchkin.h"
#include "Players/Player.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Gang.h"
#include "Exception.h"
#include "Players/Wizard.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include <fstream>

#define UPPER_PLAYER_BOUND 6
#define LOWER_PLAYER_BOUND 2
#define LOWER_DECK_BOUND 5
Mtmchkin::Mtmchkin(const std::string fileName) {
    this->m_round=0;
    this->m_won=0;
    this->m_lost=0;
    printStartGameMessage();
    updateDeck(fileName);
    int teamSize=updateTeamSize();
    updatePlayerVector(teamSize);
}

void Mtmchkin::updateDeck(const std::string fileName) {
    std::ifstream source(fileName);
    if (!source) {
        throw DeckFileNotFound();
    }
    if(source.peek()==EOF){
        throw DeckFileInvalidSize();
    }
    int lineCounter=0;
    bool inGang = false;
    std::string typeOf;
    while(std::getline(source, typeOf)) {
        lineCounter++;
        if(typeOf=="Gang") {
            inGang=true;
            lineCounter= createGang(source,lineCounter, inGang);
        }
        else{
            if(typeOf=="EndGang"){
                if(!inGang){
                    throw DeckFileFormatError(lineCounter);
                }
                else{
                    inGang = false;
                    continue;
                }
            }
            else{
                this->m_deck.push_back(std::move(createCardPtr(typeOf,lineCounter)));
            }
        }
    }
    if(inGang && source.peek()==EOF){
        throw DeckFileFormatError(lineCounter+1);
    }
    if((this->m_deck).size()<LOWER_DECK_BOUND){
        throw DeckFileInvalidSize();
    }
}

int Mtmchkin::createGang(std::ifstream &fileRead, int lineCounter, bool& inGang) {
    std::unique_ptr<Gang> ptr (new Gang());
    int tmpLineCounter = lineCounter;
    std::string typeOf="Gang";
    while(!fileRead.eof()) {
            tmpLineCounter++;
            std::getline(fileRead, typeOf);
            if(typeOf=="EndGang"){
                break;
            }
            (*ptr).addCardtoGang(typeOf, tmpLineCounter);
    }
    if(typeOf=="EndGang"){
        this->m_deck.push_back(std::move(ptr));
        inGang = false;
        return tmpLineCounter;
    }
    throw DeckFileFormatError(tmpLineCounter);
}

int Mtmchkin::updateTeamSize() {
    bool correctInput= false;
    int teamSize;
    while(!correctInput){
        printEnterTeamSizeMessage();
        std::string numInString;
        std::getline(std::cin,numInString);
        try{
            teamSize = std::stoi(numInString);
        } catch (std::exception &e){
            printInvalidTeamSize();
            continue;
        }
        if(teamSize>UPPER_PLAYER_BOUND || teamSize<LOWER_PLAYER_BOUND){
            printInvalidTeamSize();
        }
        else{
            correctInput=true;
        }
    }
    return teamSize;
}

void Mtmchkin::updatePlayerVector(int teamSize) {
    bool correctInput=false;
    std::string playerName;
    std::string job;
    bool wrongInput = false;
    for(int i=0; i<teamSize;i++){
        printInsertPlayerMessage();
        correctInput=false;
        while(!correctInput){
            std::cin>>playerName;
            std::cin>>job;
            if(15<(int)(playerName.length())){
                printInvalidName();
                continue;
            }
            for(int j=0; j<(int)(playerName.length()); j++){
                if(!isalpha(playerName[j])){
                    printInvalidName();
                    wrongInput = true;
                    break;
                }
            }
            if(wrongInput){
                wrongInput= false;
                continue;
            }
            try{
                this->m_playerVect.push_back(std::move(createPlayerPtr(playerName,job)));
            } catch (std::exception &e){
                printInvalidClass();
                continue;
            }
            correctInput=true;
            std::cin.ignore();
        }
    }
}

std::unique_ptr<Card> Mtmchkin::createCardPtr(const std::string &job, int lineCounter){
    if(job=="Barfight"){
        std::unique_ptr<Card> ptr (new Barfight());
        return ptr;
    }
    if(job=="Dragon"){
        std::unique_ptr<Card> ptr (new Dragon());
        return ptr;
    }
    if(job=="Fairy"){
        std::unique_ptr<Card> ptr (new Fairy());
        return ptr;
    }
    if(job=="Goblin"){
        std::unique_ptr<Card> ptr (new Goblin());
        return ptr;
    }
    if(job=="Merchant"){
        std::unique_ptr<Card> ptr (new Merchant());
        return ptr;
    }
    if(job=="Pitfall"){
        std::unique_ptr<Card> ptr (new Pitfall());
        return ptr;
    }
    if(job=="Treasure"){
        std::unique_ptr<Card> ptr (new Treasure());
        return ptr;
    }
    if(job=="Vampire"){
        std::unique_ptr<Card> ptr (new Vampire());
        return ptr;
    }
    if(job=="Gang"){
        std::unique_ptr<Card> ptr (new Gang());
        return ptr;
    }
    throw DeckFileFormatError(lineCounter);
}


std::unique_ptr<Player> Mtmchkin::createPlayerPtr(const std::string &name,const std::string &job) {
    if(job=="Wizard"){
            std::unique_ptr<Player> ptr (new Wizard(name));
            return ptr;
    }
    if(job=="Rogue"){
        std::unique_ptr<Player> ptr (new Rogue(name));
        return ptr;
    }
    if(job=="Fighter"){
        std::unique_ptr<Player> ptr (new Fighter(name));
        return ptr;
    }
    throw std::exception();
}

void Mtmchkin::playRound(){
    printRoundStartMessage(getNumberOfRounds()+1);
    int playersize=(int)(this->m_playerVect.size())-m_won - m_lost;
    int playerIndex=this->m_won;
    for(int i = 0; i < playersize; i++) {

       std::unique_ptr<Card> tmp = std::move(m_deck.front());
       m_deck.pop_front();

       printTurnStartMessage((*this->m_playerVect[playerIndex]).getName());
       (*tmp).applyEncounter(*this->m_playerVect[playerIndex]);

       if ((*this->m_playerVect[playerIndex]).isKnockedOut()) {
           int k = playerIndex;
           while (k < (int)(this->m_playerVect).size()-m_lost-1) {
               swap(this->m_playerVect[k],this->m_playerVect[k + 1]);
               k++;
           }
           playerIndex--;
           this->m_lost++;
       }

       else if ((*(this->m_playerVect[playerIndex])).getLevel() == 10){
           int k = playerIndex;
           while(k>m_won){
               swap(this->m_playerVect[k],this->m_playerVect[k - 1]);
               k--;
           }
           this->m_won++;
       }

      playerIndex++;
      m_deck.push_back(std::move(tmp));
    }

    this->m_round++;
    if(isGameOver()){
       printGameEndMessage();
   }
}


bool Mtmchkin::isGameOver() const {
    return this->m_won+this->m_lost==(int)this->m_playerVect.size();
}

int Mtmchkin::getNumberOfRounds() const{
    return this->m_round;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    for(int i=0; i<(int)this->m_playerVect.size(); i++){
        printPlayerLeaderBoard(i+1,*this->m_playerVect[i]);
    }
}
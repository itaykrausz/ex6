#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_
#include <iostream>
#include <deque>
#include <memory>
#include <vector>
#include "Players/Player.h"
#include "Cards/Card.h"
#include "Cards/MonsterCard.h"
class Mtmchkin{
    std::vector<std::unique_ptr<Player>> m_playerVect;
    std::deque<std::unique_ptr<Card>> m_deck;
    int m_round;
    int m_won;
    int m_lost;
public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    /*
     * Builds a card unique ptr according to inserted type;
     * @Param job- a job to specify the type of card
     * @Param lineCounter- case an exeption is thrown, throw the line of the false card name
     * @return
     *      the unique ptr of the card created with the input
     */
    static std::unique_ptr<Card> createCardPtr(const std::string &job, int lineCounter);

    /*
     * Builds a unique ptr according to inserted and name of player type;
     * @Param job- a job to specify the type of card
     * @param name- the name of the player
     * @return
     *      the unique ptr of the player created with the input
     */
    static std::unique_ptr<Player> createPlayerPtr(const std::string &name,const std::string &job);

    /*
     * updates the deck of the game with the file inserted
     * @Param fileName- the name of the file from which the deck is built
     * @return
     *      void
     */
    void updateDeck(const std::string fileName);

    /*
     * updates the team size in a game, required for c'tor
     * @return
     *      int- the number of players in the current match
     */
    int updateTeamSize();

    /*
     * updates the vector of players in the current game
     * @Param teamSize- the number of players in the game
     * @return
     *      void
     */
    void updatePlayerVector(int teamSize);

    /*
     * updates a gang card when one is inserted
     * Param fileRead- the file from which the gang will be created
     * @Param lineCounter- the line from which
     * @return
     *      the new line number after going through the file and creating the gang
     */
    int createGang(std::ifstream& fileRead, int lineCounter, bool& fuck);
    };



#endif /* MTMCHKIN_H_ */

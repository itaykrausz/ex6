//
// Created by itayk on 04/05/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <iostream>
class Player {

protected:
    Player(const std::string name, const std::string job);
    const std::string m_name;
    const std::string m_type;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:

    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;

    void levelUp();
    int getLevel() const;
    void buff(int force);
    virtual void heal(int HP);
    int damage(int HP);
    bool isKnockedOut() const;
    virtual void addCoins(int coins);
    bool pay(int coins);
    virtual int getAttackStrength() const;
    int getHp() const;
    void loseLevel();

    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    std::string getName() const;
    std::string getType() const;
    void loseForce(int force);
    int getCoins() const;
};
#endif //EX4_PLAYER_H
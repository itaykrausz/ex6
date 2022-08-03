//
// Created by itayk on 04/05/2022.
//
#include "Player.h"
#include <iostream>
#include <string>
#include "../utilities.h"
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5
#define DEFAULT_COINS 10
#define DEFAULT_LEVEL 1
Player::Player(const std::string name, const std::string job) :m_name(name), m_type(job), m_level(DEFAULT_LEVEL), m_force(DEFAULT_FORCE),
                                                                m_maxHP(DEFAULT_MAX_HP),m_HP(DEFAULT_MAX_HP), m_coins(DEFAULT_COINS){}

void Player::levelUp(){
    if (m_level >= 10){
        return;
    }
    m_level += 1;
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(int force){
    if(force <= 0){
        force = 0;
    }

    m_force += force;
}

void Player::loseForce(int force){
    if(m_force - force <= 0){
        m_force = 0;
        force=m_force;
    }
    m_force -= force;
}

void Player::heal(int HP){
    if(HP <= 0){
        HP = 0;
    }

    if(m_HP + HP >= m_maxHP) {
        m_HP=m_maxHP;
        return;
    }
    m_HP += HP;
}

int Player::damage(int HP){
    if(HP < 0){
        HP = 0;
    }

    if(m_HP - HP <= 0) {
        m_HP = 0;
        return m_HP;
    }
    m_HP -= HP;
    return m_HP;
}

bool Player::isKnockedOut() const{
    if(m_HP == 0) {
        return true;
    }
    return false;
}

void Player::addCoins(int coins){
    if(coins < 0){
        coins = 0;
    }

    m_coins += coins;
}

bool Player::pay(int coins){
    if(coins < 0){
        coins = 0;
    }

    if (m_coins - coins < 0){
        return false;
    }
    m_coins -= coins;
    return true;
}

int Player::getAttackStrength() const{
    return m_level + m_force;
}

std::string Player::getName() const{
    return this->m_name;
}

int Player::getCoins() const{
    return this->m_coins;
}

int Player::getHp() const{
    return this->m_HP;
}

void Player::loseLevel() {
    if (m_level <= 0){
        return;
    }
    m_level -= 1;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    printPlayerDetails(os, player.m_name, player.m_type, player.m_level, player.m_force,player.m_HP, player.m_coins);
    return os;
}

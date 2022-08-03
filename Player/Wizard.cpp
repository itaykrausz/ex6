//
// Created by itayk on 11/06/2022.
//
#include "Wizard.h"
Wizard::Wizard(std::string name): Player(name,"Wizard") {}

void Wizard::heal(int HP){
    if(HP <= 0){
        HP = 0;
    }

    if(m_HP + (2*HP)>m_maxHP) {
        m_HP=m_maxHP;
        return;
    }
    m_HP += (2*HP);
}

std::string Wizard::getType() const {
    return this->m_type;
}







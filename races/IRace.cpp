#include "IRace.h"

#include <string>

using namespace std;

int IRace::getHealth(){
    return m_health;
}

int IRace::getArmor(){
    return m_armor;
}

int IRace::getCritChance(){
    return m_critChance;
}

int IRace::getInitBonus(){
    return m_initBonus;
}

string IRace::getSpecialMessage(string target){
    return "";
}
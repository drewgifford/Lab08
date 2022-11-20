#pragma once
#include <memory>
#include <string>
#include "../races/IRace.h"

using namespace std;

class ICharacter {
    public:

        ICharacter(shared_ptr<IRace> race) : m_race(race),
            m_health(0),
            m_className("N/A"),
            m_armor(0),
            m_critChance(0),
            m_initBonus(10) {};

        int getHealth() { return m_race->getHealth() + m_health; };
        int getArmor() { return m_race->getArmor() + m_armor; };
        int getCritChance() { return m_race->getCritChance() + m_critChance; };
        int getInitBonus() { return m_race->getInitBonus() + m_initBonus; };
        shared_ptr<IRace> getRace() { return m_race; };
        string getClassName() { return m_className; };


    protected:

        int m_health;
        int m_armor;
        int m_critChance;
        int m_initBonus;
        string m_className;

        shared_ptr<IRace> m_race;



};
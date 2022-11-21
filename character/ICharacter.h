#pragma once
#include <memory>
#include <string>
#include "../races/IRace.h"

#include <iostream>

using namespace std;

class ICharacter {
    public:

        ICharacter(shared_ptr<IRace> race) : m_race(race),
            m_health(0),
            m_className("N/A"),
            m_armor(10),
            m_critChance(0),
            m_initBonus(0),
            m_die(20) {};

        int getDie() { return m_die; };
        int getHealth() { return m_health; };
        int getArmor() { return m_armor; };
        int getCritChance() { return m_critChance; };
        int getInitBonus() { return m_initBonus; };

        void setHealth(int hp) { m_health = hp; };
        void removeHealth(int hp) { m_health -= hp; };

        void printInfo(bool endLine) {
            cout << m_race->getName() << " " << m_className << " (" << m_health << " HP)";

            if (endLine){
                cout << endl;
            }
        }

        shared_ptr<IRace> getRace() { return m_race; };
        string getClassName() { return m_className; };


    protected:
        int m_die;
        int m_health;
        int m_armor;
        int m_critChance;
        int m_initBonus;
        string m_className;

        shared_ptr<IRace> m_race;



};
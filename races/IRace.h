#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

class IRace {

    public:

        IRace() {};
        ~IRace(){}
        
        virtual int getHealth();
        virtual int getArmor();
        virtual int getCritChance();
        virtual int getInitBonus();

        vector<string> getStrengths() { return m_strengths; }
        vector<string> getWeaknesses() { return m_weaknesses; }
        string getName() { return m_raceName; }

        virtual string getSpecialMessage(string target);

    protected:
        int m_health;
        int m_armor;
        int m_critChance;
        int m_initBonus;

        string m_raceName;
        vector<string> m_strengths;
        vector<string> m_weaknesses;

};

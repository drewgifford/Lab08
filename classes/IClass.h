#pragma once
#include <memory>
#include <string>
#include <vector>

using namespace std;

class IClass {

    public:

        IClass(string id, vector<string> strengths, vector<string> weaknesses, int hitPoints, int armorClass, int hitBonus, int initBonus) : m_hitPoints(hitPoints),
            m_armorClass(armorClass),
            m_hitBonus(hitBonus),
            m_initBonus(initBonus),
            
            m_strengths(strengths),
            m_weaknesses(weaknesses),
            m_id(id)
            
             {};

        ~IClass(){}
        
        virtual int getHitPoints() { return m_hitPoints; }
        virtual int getArmorClass() { return m_armorClass; }
        virtual int getHitBonus() { return m_hitBonus; }
        virtual int getInitBonus() { return m_initBonus; }

        virtual vector<string> getStrengths() { return m_strengths; }
        virtual vector<string> getWeaknesses() { return m_weaknesses; }
        virtual string getId() { return m_id; }



    protected:

        int m_hitPoints;
        int m_armorClass;
        int m_hitBonus;
        int m_initBonus;

        string m_id;
        vector<string> m_strengths;
        vector<string> m_weaknesses;

};

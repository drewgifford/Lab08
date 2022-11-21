#pragma once
#include "ICharacter.h"

class Mage : public ICharacter
{
public:

	Mage(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Mage";
        m_health = 60 + m_race->getHealth();
        m_critChance = 40 + m_race->getCritChance();
        m_armor = 4 + m_race->getArmor();
        m_initBonus = 2 + m_race->getInitBonus();
        m_die = 30;

	}

    ~Mage() {}

};

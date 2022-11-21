#pragma once
#include "ICharacter.h"

class Tank : public ICharacter
{
public:

	Tank(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Tank";
        m_health = 110 + m_race->getHealth();;
        m_critChance = 5 + m_race->getCritChance();
        m_armor = 8 + m_race->getArmor();
        m_initBonus = 1 + m_race->getInitBonus();
        m_die = 20;

	}

    ~Tank() {}

};

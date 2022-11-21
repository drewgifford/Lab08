#pragma once
#include "ICharacter.h"

class Peasant : public ICharacter
{
public:

	Peasant(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Peasant";
        m_health = 75 + m_race->getHealth();;
        m_critChance = 5 + m_race->getCritChance();
        m_armor = 1 + m_race->getArmor();
        m_initBonus = 5 + m_race->getInitBonus();
        m_die = 15;

	}

    ~Peasant() {}

};
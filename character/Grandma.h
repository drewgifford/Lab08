#pragma once
#include "ICharacter.h"

class Grandma : public ICharacter
{
public:

	/// @brief 
	/// @param race 
	Grandma(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Grandma";
        m_health = 1 + m_race->getHealth();
        m_critChance = 100 + m_race->getCritChance();
        m_armor = 0 + m_race->getArmor();
        m_initBonus = 20 + m_race->getInitBonus();
        m_die = 60;

	}

    ~Grandma() {}

};
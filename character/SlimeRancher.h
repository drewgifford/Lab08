#pragma once
#include "ICharacter.h"

class SlimeRancher : public ICharacter
{
public:

	SlimeRancher(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Slime Rancher";
        m_health = 90 + m_race->getHealth();;
        m_critChance = 15 + m_race->getCritChance();
        m_armor = 2 + m_race->getArmor();
        m_initBonus = 2 + m_race->getInitBonus();
        m_die = 25;

	}

    ~SlimeRancher() {}

};
#pragma once
#include "ICharacter.h"

class SlimeRancher : public ICharacter
{
public:

	SlimeRancher(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Slime Rancher";
        m_health = 90;
        m_critChance = 15;
        m_armor = 40;
        m_initBonus = 2;

	}

    ~SlimeRancher() {}

};
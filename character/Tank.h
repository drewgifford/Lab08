#pragma once
#include "ICharacter.h"

class Tank : public ICharacter
{
public:

	Tank(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Tank";
        m_health = 110;
        m_critChance = 12;
        m_armor = 60;
        m_initBonus = 1;

	}

    ~Tank() {}

};

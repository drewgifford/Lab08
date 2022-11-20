#pragma once
#include "ICharacter.h"

class Mage : public ICharacter
{
public:

	Mage(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Mage";
        m_health = 60;
        m_critChance = 40;
        m_armor = 20;
        m_initBonus = 2;

	}

    ~Mage() {}

};

#pragma once
#include "ICharacter.h"

class Peasant : public ICharacter
{
public:

	Peasant(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Peasant";
        m_health = 75;
        m_critChance = 5;
        m_armor = 30;
        m_initBonus = 5;

	}

    ~Peasant() {}

};
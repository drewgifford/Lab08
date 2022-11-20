#pragma once
#include "ICharacter.h"

class Grandma : public ICharacter
{
public:

	Grandma(std::shared_ptr<IRace> race) : ICharacter(race)
	{
        m_className = "Grandma";
        m_health = 1;
        m_critChance = 95;
        m_armor = 1;
        m_initBonus = 10;

	}

    ~Grandma() {}

};
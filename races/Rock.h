#pragma once
#include "IRace.h"

class Rock : public IRace
{

public:
	Rock() : IRace()
	{
		m_raceName = "Rock";

		m_health = 0;
		m_critChance = 0;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Lizard", "Scissors"};
		m_weaknesses = {"Paper", "Spock"};
	};
    virtual ~Rock() {};
};
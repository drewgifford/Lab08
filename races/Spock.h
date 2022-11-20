#pragma once
#include "IRace.h"

class Spock : public IRace
{

public:
	Spock() : IRace()
	{
		m_raceName = "Spock";

		m_health = 0;
		m_critChance = 0;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Scissors", "Rock"};
		m_weaknesses = {"Lizard", "Paper"};
	};
    virtual ~Spock() {};
};
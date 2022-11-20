#pragma once
#include "IRace.h"

class Paper : public IRace
{

public:
	Paper() : IRace()
	{

		m_raceName = "Paper";

		m_health = 0;
		m_critChance = 0;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Spock", "Rock"};
		m_weaknesses = {"Lizard", "Scissors"};
	};
    virtual ~Paper() {};
};
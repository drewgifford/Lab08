#pragma once
#include "IRace.h"

class Lizard : public IRace
{

public:
	Lizard() : IRace()
	{
		m_raceName = "Lizard";

		m_health = 0;
		m_critChance = 0;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Spock", "Paper"};
		m_weaknesses = {"Rock", "Scissors"};
	};
    virtual ~Lizard() {};
};
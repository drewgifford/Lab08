#pragma once
#include "IRace.h"

class Scissors : public IRace
{

public:
	Scissors() : IRace()
	{
		m_raceName = "Scissors";

		m_health = 0;
		m_critChance = 0;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Paper", "Lizard"};
		m_weaknesses = {"Rock", "Spock"};
	};

};
#pragma once
#include "IRace.h"

#include <string>

class Scissors : public IRace
{

public:
	Scissors() : IRace()
	{
		m_raceName = "Scissors";

		m_health = 5;
		m_critChance = 10;
		m_armor = 0;
		m_initBonus = 0;

		m_strengths = {"Paper", "Lizard"};
		m_weaknesses = {"Rock", "Spock"};
	};

	virtual ~Scissors() {};

	string getSpecialMessage(string target){

		if(target == "Paper"){
			return "Scissors cuts Paper";
		}
		else if (target == "Rock"){
			return "Scissors decapitates Lizard";
		}
		return "";
	}

};
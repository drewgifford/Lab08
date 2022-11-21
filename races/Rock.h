#pragma once
#include "IRace.h"

#include <string>

class Rock : public IRace
{

public:
	Rock() : IRace()
	{
		m_raceName = "Rock";

		m_health = 40;
		m_critChance = 0;
		m_armor = 3;
		m_initBonus = 0;

		m_strengths = {"Lizard", "Scissors"};
		m_weaknesses = {"Paper", "Spock"};
	};
    virtual ~Rock() {};

	string getSpecialMessage(string target){

		if(target == "Lizard"){
			return "Rock crushes Lizard";
		}
		else if (target == "Scissors"){
			return "As it always has, rock crushes scissors";
		}
		return "";
	}
};
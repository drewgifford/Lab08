#pragma once
#include "IRace.h"

#include <string>

class Spock : public IRace
{

public:
	Spock() : IRace()
	{
		m_raceName = "Spock";

		m_health = 10;
		m_critChance = 5;
		m_armor = 2;
		m_initBonus = 10;

		m_strengths = {"Scissors", "Rock"};
		m_weaknesses = {"Lizard", "Paper"};
	};
    virtual ~Spock() {};

	string getSpecialMessage(string target){

		if(target == "Scissors"){
			return "Spock smashes Scissors";
		}
		else if (target == "Rock"){
			return "Spock vaporizes Rock";
		}
		return "";
	}
};
#pragma once
#include "IRace.h"

#include <string>

class Paper : public IRace
{

public:
	Paper() : IRace()
	{

		m_raceName = "Paper";

		m_health = 0;
		m_critChance = 10;
		m_armor = 0;
		m_initBonus = 5;

		m_strengths = {"Spock", "Rock"};
		m_weaknesses = {"Lizard", "Scissors"};
	};
    virtual ~Paper() {};

	string getSpecialMessage(string target){

		if(target == "Spock"){
			return "Paper disproves Spock";
		}
		else if (target == "Rock"){
			return "Paper covers Rock";
		}
		return "";
	}
};
#pragma once
#include "IRace.h"

#include <string>

class Lizard : public IRace
{

public:
	Lizard() : IRace()
	{
		m_raceName = "Lizard";

		m_health = 20;
		m_critChance = 0;
		m_armor = 1;
		m_initBonus = -4;

		m_strengths = {"Spock", "Paper"};
		m_weaknesses = {"Rock", "Scissors"};
	};
    virtual ~Lizard() {};

	string getSpecialMessage(string target){

		if(target == "Spock"){
			return "Lizard poisons Spock";
		}
		else if (target == "Paper"){
			return "Lizard eats Paper";
		}
		return "";

	}
};
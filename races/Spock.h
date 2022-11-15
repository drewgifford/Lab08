#pragma once
#include "IRace.h"
#include "Rock.h"

class Spock : public IRace
{

public:
	Spock() : IRace("Spock", {"Scissors", "Rock"}, {"Lizard", "Paper"}, 0, 0, 0, 0)
	{

	}
    virtual ~Spock() {}
};
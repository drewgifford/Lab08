#pragma once
#include "IRace.h"
#include "Rock.h"

class Lizard : public IRace
{

public:
	Lizard() : IRace("Lizard", {"Spock", "Paper"}, {"Rock", "Scissors"}, 0, 0, 0, 0)
	{

	}
    virtual ~Lizard() {}
};
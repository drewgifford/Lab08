#pragma once
#include "IRace.h"
#include "Rock.h"

class Scissors : public IRace
{

public:
	Scissors() : IRace("Scissors", {"Paper", "Lizard"}, {"Rock", "Spock"}, 0, 0, 0, 0)
	{

	}
    virtual ~Scissors() {}
};
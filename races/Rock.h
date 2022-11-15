#pragma once
#include "IRace.h"
#include "Rock.h"

class Rock : public IRace
{

public:
	Rock() : IRace("Rock", {"Lizard", "Scissors"}, {"Paper", "Spock"}, 0, 0, 0, 0)
	{

	}
    virtual ~Rock() {}
};
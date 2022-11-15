#pragma once
#include "IRace.h"
#include "Rock.h"

class Paper : public IRace
{

public:
	Paper() : IRace("Paper", {"Spock", "Rock"}, {"Lizard", "Scissors"}, 0, 0, 0, 0)
	{

	}
    virtual ~Paper() {}
};
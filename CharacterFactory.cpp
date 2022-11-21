#include "CharacterFactory.h"

#include "character/Tank.h"
#include "character/Grandma.h"
#include "character/Mage.h"
#include "character/Peasant.h"
#include "character/SlimeRancher.h"

#include "races/Rock.h"
#include "races/Paper.h"
#include "races/Scissors.h"
#include "races/Lizard.h"
#include "races/Spock.h"

#include <memory>
using namespace std;

CharacterFactory & CharacterFactory::GetCharacterFactory()
{
	// Create a new static CharacterFactory
	static CharacterFactory s;
	return s;
}


shared_ptr<ICharacter> CharacterFactory::CreateCharacter(CharacterType enumCharType, RaceType enumRaceType)
{
	// Default return is a nullptr. This will get filled once we create the character
	shared_ptr<ICharacter> retVal = nullptr;

	// Grab the shared_ptr instance of our character's race
	shared_ptr<IRace> race = m_raceMap[enumRaceType];

	// Associate each CharacterType with an ICharacter
	switch(enumCharType){

		// Return a new instance of an ICharacter, with race specified by RaceType.
		// shared_ptr<IRace> is included in the initializer of ICharacter

		case CharacterType::ClassGrandma:
			return make_shared<Grandma>(race);

		case CharacterType::ClassMage:
			return make_shared<Mage>(race);

		case CharacterType::ClassPeasant:
			return make_shared<Peasant>(race);

		case CharacterType::ClassTank:
			return make_shared<Tank>(race);

		case CharacterType::ClassSlimeRancher:
			return make_shared<SlimeRancher>(race);

		default:
			throw "Unknown Character Type";


	}


	return retVal;
}

CharacterFactory::CharacterFactory() 
{

	// Associate each IRace with a RaceType

	shared_ptr<IRace> t1 = make_shared<Rock>();
	shared_ptr<IRace> t2 = make_shared<Paper>();
	shared_ptr<IRace> t3 = make_shared<Scissors>();
	shared_ptr<IRace> t4 = make_shared<Lizard>();
	shared_ptr<IRace> t5 = make_shared<Spock>();

	m_raceMap.insert(make_pair(RaceRock, t1));
	m_raceMap.insert(make_pair(RacePaper, t2));
	m_raceMap.insert(make_pair(RaceScissors, t3));
	m_raceMap.insert(make_pair(RaceLizard, t4));
	m_raceMap.insert(make_pair(RaceSpock, t5));
}


 CharacterFactory::~CharacterFactory() 
{

}
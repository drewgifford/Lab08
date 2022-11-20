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
	static CharacterFactory s;
	return s;
} // instance


shared_ptr<ICharacter> CharacterFactory::CreateCharacter(CharacterType enumCharType, RaceType enumRaceType)
{
	shared_ptr<ICharacter> retVal = nullptr;


	switch(enumCharType){

		case CharacterType::ClassGrandma:
			return make_shared<Grandma>(m_raceMap[enumRaceType]);

		case CharacterType::ClassMage:
			return make_shared<Mage>(m_raceMap[enumRaceType]);

		case CharacterType::ClassPeasant:
			return make_shared<Peasant>(m_raceMap[enumRaceType]);

		case CharacterType::ClassTank:
			return make_shared<Tank>(m_raceMap[enumRaceType]);

		case CharacterType::ClassSlimeRancher:
			return make_shared<SlimeRancher>(m_raceMap[enumRaceType]);

		default:
			throw "Unknown Character Type";


	}


	return retVal;
}

CharacterFactory::CharacterFactory() 
{

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
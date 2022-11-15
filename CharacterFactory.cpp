#include "CharacterFactory.h"

#include "classes/Bobbert.h"



CharacterFactory & CharacterFactory::GetCharacterFactory()
{
	static CharacterFactory s;
	return s;
} // instance


std::shared_ptr<IClass> CharacterFactory::CreateCharacter(classType enumClassType, raceType enumRaceType)
{
	std::shared_ptr<IClass> retVal = nullptr;
	if (enumClassType == ClassBobbert)
	{
		retVal = std::make_shared<Bobbert>(m_raceMap[enumRaceType]);
	}

	return retVal;
}

CharacterFactory::CharacterFactory() 
{
		
	std::shared_ptr<IRace> t1 = std::make_shared<Zerg>();
	std::shared_ptr<IRace> t2 = std::make_shared<Human>();
	m_raceMap.insert(std::pair(ZergType, t1));
	m_raceMap[HumanType]= t2;
}


 CharacterFactory::~CharacterFactory() 
{

}
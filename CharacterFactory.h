#pragma once
#include <memory>
#include "classes/IClass.h"
#include <map>

using namespace std;

class IRace;

class CharacterFactory {

    public:
        enum classType { ClassBobbert, ClassDavid, ClassStuart };
        enum raceType { RaceRock, RacePaper, RaceScissors, RaceLizard, RaceSpock };

        shared_ptr<IClass> CreateCharacter(classType cl, raceType ra);

        CharacterFactory(const CharacterFactory &) = delete;
  	    CharacterFactory & operator = (const CharacterFactory &) = delete;

    private:

        map<raceType,std::shared_ptr<IRace>> m_raceMap;
        CharacterFactory() ;
        ~CharacterFactory() ;
};
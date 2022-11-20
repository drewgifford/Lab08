#pragma once
#include <memory>
#include "character/ICharacter.h"
#include <map>

using namespace std;

enum CharacterType { ClassTank, ClassSlimeRancher, ClassPeasant, ClassMage, ClassGrandma };
enum RaceType { RaceRock, RacePaper, RaceScissors, RaceLizard, RaceSpock };

class IRace;

class CharacterFactory {

    public:

        static CharacterFactory & GetCharacterFactory();

        shared_ptr<ICharacter> CreateCharacter(CharacterType cl, RaceType ra);

        CharacterFactory(const CharacterFactory &) = delete;
  	    CharacterFactory & operator = (const CharacterFactory &) = delete;

    private:

        map<RaceType,std::shared_ptr<IRace>> m_raceMap;
        CharacterFactory() ;
        ~CharacterFactory() ;
};
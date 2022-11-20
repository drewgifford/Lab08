#include "CharacterFactory.h"
#include "races/IRace.h"
#include "Party.h"

#include <memory>
#include <iostream>

using namespace std;

int main(){


    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

    shared_ptr<ICharacter> c1 = factory.CreateCharacter(CharacterType::ClassTank, RaceType::RaceRock);
    shared_ptr<ICharacter> c2 = factory.CreateCharacter(CharacterType::ClassMage, RaceType::RacePaper);
    shared_ptr<ICharacter> c3 = factory.CreateCharacter(CharacterType::ClassGrandma, RaceType::RaceSpock);
    shared_ptr<ICharacter> c4 = factory.CreateCharacter(CharacterType::ClassSlimeRancher, RaceType::RaceScissors);

    Party party1;

    party1.add(c1, 0);
    party1.add(c2, 0);

    party1.add(c3, 1);
    party1.add(c4, 1);

    shared_ptr<ICharacter> c5 = factory.CreateCharacter(CharacterType::ClassTank, RaceType::RaceRock);
    shared_ptr<ICharacter> c6 = factory.CreateCharacter(CharacterType::ClassMage, RaceType::RacePaper);
    shared_ptr<ICharacter> c7 = factory.CreateCharacter(CharacterType::ClassGrandma, RaceType::RaceSpock);
    shared_ptr<ICharacter> c8 = factory.CreateCharacter(CharacterType::ClassSlimeRancher, RaceType::RaceScissors);

    Party party2;

    party2.add(move(c5), 0);
    party2.add(move(c6), 0);

    party2.add(move(c7), 1);
    party2.add(move(c8), 1);

    //party1.print();

    party2.print();

    return 0;
}
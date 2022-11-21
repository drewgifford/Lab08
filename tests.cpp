// tests.cpp
#include <gtest/gtest.h>

#include "CharacterFactory.h"
#include "character/ICharacter.h"
#include "races/IRace.h"
#include "Party.h"

using namespace std;

// example
TEST(CharacterFactory, CharacterCreationTest1){

    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

    shared_ptr<ICharacter> character = factory.CreateCharacter(CharacterType::ClassTank, RaceType::RaceLizard);

    ASSERT_TRUE(true);
}

TEST(CharacterFactory, CharacterCreationTest2){

    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

    shared_ptr<ICharacter> character = factory.CreateCharacter(CharacterType::ClassGrandma, RaceType::RaceSpock);
    
    ASSERT_TRUE(true);
}

TEST(Party, AddToParty){
        //Allows the creation of a character
    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

        //Creates the Character of Class Grandma and Race Lizard
    shared_ptr<ICharacter> character = factory.CreateCharacter(CharacterType::ClassGrandma, RaceType::RaceLizard);

        //Creates a party called Grandma's House
    Party GrandmasHouse("Grandma's House");
    
        //Adds the created character to the first row of the party
    GrandmasHouse.add(character, 0);

        //Gets the size of the vector containing characters in the party Grandma's House
    ASSERT_TRUE(GrandmasHouse.getCharacters().size() == 1);
}

TEST(Party, PartyIsAlive){
        //Allows the creation of a character
    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

        //Creates the Character of Class Grandma and Race Lizard
    shared_ptr<ICharacter> character = factory.CreateCharacter(CharacterType::ClassGrandma, RaceType::RaceLizard);

        //Creates a party called Grandma's House
    Party GrandmasHouse("Grandma's House");
    
        //Adds the created character to the first row of the party
    GrandmasHouse.add(character, 0);

        //Checks to see if the character in the party Grandma's House is alive and passes if they are
    ASSERT_TRUE(GrandmasHouse.isDead() == false);
 
}





int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
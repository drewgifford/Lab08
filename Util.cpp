#include "character/ICharacter.h"
#include "Party.h"
#include "CharacterFactory.h"

#include <memory>
#include <chrono>
#include <string>
#include <random>

using namespace std;

// Generates a random character
shared_ptr<ICharacter> createCharacter(int c, int r, CharacterFactory & factory){

    // Initialize blank enums CharacterType and RaceType
    // these are defined in CharacterFactory.h
    CharacterType ct;
    RaceType rt;

    // Switch case for c, which is a number between 0-4, referring to a random CharacterType
    // I arbitrarily assigned each CharacterType a number. It doesn't matter, it's all random.
    switch(c){
        case 0:
            ct = CharacterType::ClassGrandma;
            break;
        case 1:
            ct = CharacterType::ClassMage;
            break;
        case 2:
            ct = CharacterType::ClassPeasant;
            break;
        case 3:
            ct = CharacterType::ClassSlimeRancher;
            break;
        case 4:
            ct = CharacterType::ClassTank;
            break;
        default:
            throw "error";
    }

    // Switch case for r, which is a number between 0-4, referring to a random RaceType
    // I arbitrarily assigned each RaceType a number. It doesn't matter, it's all random.
    switch(r){
        case 0:
            rt = RaceType::RaceRock;
            break;
        case 1:
            rt = RaceType::RacePaper;
            break;
        case 2:
            rt = RaceType::RaceScissors;
            break;
        case 3:
            rt = RaceType::RaceLizard;
            break;
        case 4:
            rt = RaceType::RaceSpock;
            break;
        default:
            throw "error";
    }

    // Return the created character from CharacterFactory
    return factory.CreateCharacter(ct, rt);


}

// Creates a party with randomized characters
Party createParty(CharacterFactory & factory, string name){

    // Generate a seed based on the system time
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    // Create our random number generator
    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0,4);

    // Initialize the party using the given name
    Party party(name);

    // Loop through each row (0, 1)
    for(int i = 0; i <= 1; i++){
        // Add 2 characters to each row
        for(int j = 0; j <= 1; j++){
            // Generate a random character and add it
            party.add(createCharacter(distribution(generator), distribution(generator), factory), i);
        }
    }

    // Return our completed party
    return party;

}
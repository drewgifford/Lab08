#include "character/ICharacter.h"
#include "Party.h"
#include "CharacterFactory.h"

#include <memory>
#include <chrono>
#include <string>
#include <random>

using namespace std;

shared_ptr<ICharacter> createCharacter(int c, int r, CharacterFactory & factory){

    CharacterType ct;
    RaceType rt;

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

    return factory.CreateCharacter(ct, rt);


}

Party createParty(CharacterFactory & factory, string name){

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    default_random_engine generator(seed);
    uniform_int_distribution<int> distribution(0,4);

    Party party(name);


    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            party.add(createCharacter(distribution(generator), distribution(generator), factory), i);
        }
    }

    return party;

}
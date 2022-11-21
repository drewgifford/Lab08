#include "CharacterFactory.h"
#include "races/IRace.h"
#include "Party.h"
#include "Util.cpp"

#include <memory>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <iomanip>


using namespace std;

void doTurn(Party & attackingParty, Party & defendingParty){
    vector<shared_ptr<ICharacter>> characters = attackingParty.sortCharactersByInit();

    for(int i = 0; i < characters.size(); i++){

        shared_ptr<ICharacter> character = characters.at(i);

        if (character->getHealth() <= 0) continue;

        shared_ptr<ICharacter> target = defendingParty.pickRandomExposed();

        int critChance = character->getCritChance();
        int targetArmor = target->getArmor();

        int die = character->getDie();

        bool criticalHit = false;
        bool hitStrength = false;
        bool hitWeakness = false;

        int multiplier = 1;


        character->printInfo(false);
        cout << " attacks ";
        target->printInfo(false);
        cout << "..." << endl << "   ";

        // Determine hit power by rolling a d20
        int hitPower = (rand() % die);

        // Determine the crit proc and compare it against the crit chance
        int critProc = (rand() % 100);

        if (critProc <= critChance){
            criticalHit = true;
            multiplier *= 2;
        }


        vector<string> strengths = character->getRace()->getStrengths();
        if (find(strengths.begin(), strengths.end(), target->getRace()->getName()) != strengths.end()){
            multiplier *= 2;
            hitStrength = true;
        }

        vector<string> weaknesses = character->getRace()->getWeaknesses();
        if (find(weaknesses.begin(), weaknesses.end(), target->getRace()->getName()) != weaknesses.end()){
            multiplier *= 0.5;
            hitWeakness = true;
        }

        hitPower *= multiplier;

        cout << (multiplier) << "d" << die << " = " << (hitPower);


        // Subtract the target's armor
        hitPower -= targetArmor;
        // If the hit power is negative, just make it zero

        if (hitPower < 0) hitPower = 0;

        // Output a string showing the details of the attack
        cout << " - " << targetArmor << " armor = " << (hitPower) << " damage!";

        if (criticalHit){
            cout << " (CRITICAL HIT!)";
        }

        if (hitStrength) {
            cout << " (STRONG: " << character->getRace()->getSpecialMessage(target->getRace()->getName()) << ")";
        }
        else if (hitWeakness) {
            cout << " (WEAK: " << target->getRace()->getSpecialMessage(character->getRace()->getName()) << ")";
        }

        cout << endl;

        target->removeHealth(hitPower);

        if (target->getHealth() <= 0){
    
            cout << endl;
            target->setHealth(0);
            target->printInfo(false);
            cout << " F**KING DIED" << endl;

        }

        cout << endl;

        if (defendingParty.isDead()) break;
        

    }
}

void fight(Party & party1, Party & party2){

    vector<Party> parties;
    parties.push_back(party1);
    parties.push_back(party2);

    int turnNumber = 1;

    cout << "Starting fight..." << endl;

    while(!party1.isDead() && !party2.isDead()){

        Party & attackingParty = parties.at(0);
        Party & defendingParty = parties.at(1);
        
        cout << "==================================" << endl;
        cout << "TURN " << turnNumber << ": " << attackingParty.getName() << " (" << attackingParty.getAliveCharacters().size() << " members remain)" << endl;
        cout << "==================================" << endl;

    

        doTurn(attackingParty, defendingParty);

        if (defendingParty.isDead()){

            cout << "The " << attackingParty.getName() << " have defeated the " << defendingParty.getName() << "!" << endl;

            return;
        }

        rotate(parties.begin(), parties.end()-1, parties.end());

        turnNumber++;

    }
}

int main(){

    srand(time(NULL));

    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();
    Party party1 = createParty(factory, "Mantei Monkeys");
    Party party2 = createParty(factory, "Tao Li Titans");


    cout << "Party 1 (Mantei Monkeys): " << endl;
    party1.print();

    cout << endl;

    cout << "Party 2 (Tao Li Titans): " << endl;
    party2.print();

    fight(party1, party2);

    return 0;
}
/*
EXTRACT_ALL          = YES
CLASS_DIAGRAMS       = YES
HIDE_UNDOC_RELATIONS = NO
HAVE_DOT             = YES
CLASS_GRAPH          = YES
COLLABORATION_GRAPH  = YES
UML_LOOK             = YES
UML_LIMIT_NUM_FIELDS = 50
TEMPLATE_RELATIONS   = YES
DOT_GRAPH_MAX_NODES  = 100
MAX_DOT_GRAPH_DEPTH  = 0
DOT_TRANSPARENT      = YES
*/
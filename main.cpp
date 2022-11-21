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

// Process a turn
void doTurn(Party & attackingParty, Party & defendingParty){

    // Get the characters, sorted by which ones should go first
    vector<shared_ptr<ICharacter>> characters = attackingParty.sortCharactersByInit();

    // Loop through the characters. Because of the above line, the character with the highest Init Bonus will go first.
    for(int i = 0; i < characters.size(); i++){

        // Get the character pointer
        shared_ptr<ICharacter> character = characters.at(i);

        // The character can't attack if they're dead...
        if (character->getHealth() <= 0) continue;

        // Pick a random target. This will only select characters in an exposed row. If the entire row is dead, it'll attack someone
        // in the next row.
        shared_ptr<ICharacter> target = defendingParty.pickRandomExposed();

        // Get character stats
        // We're using Crit Chance instead of Hit Bonus
        int critChance = character->getCritChance();
        int targetArmor = target->getArmor();

        // Die represents the number-sided die we roll to determine damage. die = 20 means a d20, die = 10 means a d10, etc.
        int die = character->getDie();

        // We keep these stored to add messages to the end of each attack, and apply multipliers
        bool criticalHit = false;
        bool hitStrength = false;
        bool hitWeakness = false;

        // The base damage multiplier is 1.
        int multiplier = 1;

        // Output who the character is attacking
        character->printInfo(false);
        cout << " attacks ";
        target->printInfo(false);
        cout << "..." << endl << "   ";

        // Determine hit power by rolling a die (default d20)
        int hitPower = (rand() % die);

        // Determine the crit proc and compare it against the crit chance
        int critProc = (rand() % 100);

        // Double the damage if a crit is hit
        if (critProc <= critChance){
            criticalHit = true;
            multiplier *= 2;
        }

        // THIS IS STRICTLY FOR OUR VERSION OF THE GAME'S FUNCTIONALITY
        // Check if the character is attacking another they are strong against
        // i.e. if Scissors attacks Paper, double the damage
        vector<string> strengths = character->getRace()->getStrengths();
        if (find(strengths.begin(), strengths.end(), target->getRace()->getName()) != strengths.end()){
            multiplier *= 2;
            hitStrength = true;
        }

        // Check if the character is attacking another they are WEAK against
        // i.e. if Paper attacks Scissors, half the damage
        vector<string> weaknesses = character->getRace()->getWeaknesses();
        if (find(weaknesses.begin(), weaknesses.end(), target->getRace()->getName()) != weaknesses.end()){
            multiplier *= 0.5;
            hitWeakness = true;
        }

        // Apply the hit power multiplier
        hitPower *= multiplier;

        // Output the total hit damage
        cout << (multiplier) << "d" << die << " = " << (hitPower);


        // Subtract the target's armor
        hitPower -= targetArmor;

        // If the hit power is negative, just make it zero
        if (hitPower < 0) hitPower = 0;

        // Output a string showing the details of the attack
        cout << " - " << targetArmor << " armor = " << (hitPower) << " damage!";

        // Display if a critical is hit
        if (criticalHit){
            cout << " (CRITICAL HIT!)";
        }

        // Display if hit a strength
        if (hitStrength) {
            cout << " (STRONG: " << character->getRace()->getSpecialMessage(target->getRace()->getName()) << ")";
        }
        // Display if hit a weakness
        else if (hitWeakness) {
            cout << " (WEAK: " << target->getRace()->getSpecialMessage(character->getRace()->getName()) << ")";
        }

        cout << endl;

        // Remove the target's health
        target->removeHealth(hitPower);

        // Check if the target died. If so, display a message
        if (target->getHealth() <= 0){
    
            cout << endl;
            target->setHealth(0);
            target->printInfo(false);
            cout << " F**KING DIED" << endl;

        }

        cout << endl;

        // Break the loop if the defending party is fully dead
        if (defendingParty.isDead()) break;
        

    }
}

void fight(Party & party1, Party & party2){

    // Create a new vector of parties we can manipulate
    vector<Party> parties;
    parties.push_back(party1);
    parties.push_back(party2);

    // Keep track of the turn number
    int turnNumber = 1;

    cout << "Starting fight..." << endl;

    // Only loop if both parties are alive
    while(!party1.isDead() && !party2.isDead()){
        
        // In how we're manipulating the vector, the attacking party will always be at the front.
        // The defending party will be at index 1.
        Party & attackingParty = parties.at(0);
        Party & defendingParty = parties.at(1);
        
        // Display a header
        cout << "==================================" << endl;
        cout << "TURN " << turnNumber << ": " << attackingParty.getName() << " (" << attackingParty.getAliveCharacters().size() << " members remain)" << endl;
        cout << "==================================" << endl;

    
        // Do the turn
        doTurn(attackingParty, defendingParty);

        // Check if the defending party is dead. We could put this outside the loop, but it is easier to
        // check for it here.
        if (defendingParty.isDead()){

            cout << "The " << attackingParty.getName() << " have defeated the " << defendingParty.getName() << "!" << endl;
            // Break the program
            return;
        }

        // Move the first element of the vector to the back, and vice versa. This will make the
        // defending party the new attacking party.
        rotate(parties.begin(), parties.end()-1, parties.end());

        // Increment the turn number
        turnNumber++;

    }
}

int main(){
    // Seed our random number generator
    srand(time(NULL));

    // Create a new static Character Factory
    // This will generate our IRace and ICharacter instances
    CharacterFactory & factory = CharacterFactory::GetCharacterFactory();

    // Create the two parties using a special function that generates parties with random characters
    Party party1 = createParty(factory, "Mantei Monkeys");
    Party party2 = createParty(factory, "Tao Li Titans");

    // Output the parties
    cout << "Party 1 (Mantei Monkeys): " << endl;
    party1.print();

    cout << endl;

    cout << "Party 2 (Tao Li Titans): " << endl;
    party2.print();

    // Make them fight!
    fight(party1, party2);

    return 0;
}
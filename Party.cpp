#include "Party.h"
#include "character/ICharacter.h"
#include <string>
#include <memory>
#include <iostream>
#include <random>

using namespace std;

Party::Party(string name) : m_rows_count(2), m_chars_per_row(2), m_name(name) {

    // Initialize the vectors for each row of characters
    for(int i = 0; i < m_rows_count; i++){
        // For each row, add a blank vector
        vector<shared_ptr<ICharacter>> row;
        m_rows.push_back(row);
    }
}

Party::~Party(){}

void Party::add(shared_ptr<ICharacter> character, int row){
    // Throw an error if the row specified is invalid
    if (row < 0 || row >= m_rows_count){
        throw "Not enough rows";
    }
    
    // Grab a reference to the row we're adding the character to (to keep code clean)
    vector<shared_ptr<ICharacter>> & charRow = m_rows.at(row);

    // Get the size of the row
    int length = charRow.size();

    // If adding the character would break specification, throw an error
    if (length >= m_chars_per_row){
        throw "Too many characters in row";
    }

    // Add the character to the row. Since charRow is a reference, this is all we need.
    charRow.push_back(character);

}

void Party::print(){

    // Loop through each row of characters. This ensures that the front row is printed first, then the 2nd, etc.
    for(int i = 0; i < m_rows.size(); i++){

        // Grab the row by reference
        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        // Loop through each character in this row
        for(int j = 0; j < row.size(); j++){
            
            // Grab the character by reference
            shared_ptr<ICharacter> & character = row.at(j);

            // Output the row number and the character information
            cout << "ROW " << i+1 << " - ";
            character->printInfo(true);

        }


    }


}

bool Party::isDead(){

    /* Note: this function could be way easier with the following code:

     * bool allDead = getAliveCharacters().size() == 0;
     * return allDead;
     * 
     * But the code beneath was written before I made these comments, so that is what I will leave.
    */


    // Grab a vector of the characters
    vector<shared_ptr<ICharacter>> characters = getCharacters();

    // Loop through each characters
    for(int i = 0; i < characters.size(); i++){
        
        // Grab the character by reference
        shared_ptr<ICharacter> & character = characters.at(i);

        // If the character is not dead, return false. This is because if one character is alive, the party as a whole is not dead (yet).
        if (character->getHealth() > 0){
            return false;
        }
    }

    // If all characters are dead, return true
    return true;

}

shared_ptr<ICharacter> Party::pickRandomExposed(){
    // Store a vector of all valid characters we can attack
    vector<shared_ptr<ICharacter>> characters;

    // Loop through each row, starting with the front
    for(int i = 0; i < m_rows_count; i++){

        // Keep track of the amount alive in this row
        int aliveInRow = 0;

        // Grab the row by reference
        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        // Loop through each character in the row
        for(int j = 0; j < row.size(); j++){

            // Grab the character by reference
            shared_ptr<ICharacter> & character = row.at(j);

            // If the character is alive, add the character to the vector
            if (character->getHealth() > 0){
                characters.push_back(character);
                // Increment the amount alive in the row.
                aliveInRow++;
            }
        }
        // If there's someone alive in this row, we can't attack the row behind it. By breaking the loop,
        // we won't check the next row for characters.
        if (aliveInRow > 0) break;
    }

    // Return a randomly selected character from our vector.
    // Random works like: rand () % 10 returns a random number 0-10
    return characters.at(rand() % characters.size());


}

// Return a raw, un"row"ed vector of characters
vector<shared_ptr<ICharacter>> Party::getCharacters(){
    // Store a list of characters
    vector<shared_ptr<ICharacter>> characters;

    // Loop through each row
    for(int i = 0; i < m_rows.size(); i++){

        // Grab the row by reference
        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        // Loop through each character in the row
        for(int j = 0; j < row.size(); j++){
            // Grab the character by reference
            shared_ptr<ICharacter> & character = row.at(j);

            // Push the character into the list of characters
            characters.push_back(character);
            
        }
    }

    // Return our full list. This will include dead characters
    return characters;
}

vector<shared_ptr<ICharacter>> Party::getAliveCharacters(){

    // Get all of our characters
    vector<shared_ptr<ICharacter>> characters = getCharacters();

    // Keep a list of characters who are alive
    vector<shared_ptr<ICharacter>> aliveCharacters;

    // Loop through each character
    for(int i = 0; i < characters.size(); i++){
        
        // If the character is alive...
        if(characters.at(i)->getHealth() > 0){
            // Add the character to the vector.
            aliveCharacters.push_back(characters.at(i));
        }
    }

    // Return our alive characters.
    return aliveCharacters;

}

vector<shared_ptr<ICharacter>> Party::sortCharactersByInit(){
    // Get a list of all of our characters
    vector<shared_ptr<ICharacter>> characters = getCharacters();

    // Keep a vector of our sorted characters
    vector<shared_ptr<ICharacter>> charactersSorted;

    // Loop through each character
    for(int i = 0; i < characters.size(); i++){

        // Grab the character by reference
        shared_ptr<ICharacter> & character = characters.at(i);


        // We're going to manipulate this vector kind of like a tree.

        // Conditions to add an element to the end of a vector:
        // - If the vector is empty
        // - If the character's InitBonus is greater than or equal to the one at index 0
        if (charactersSorted.size() == 0 || charactersSorted.at(0)->getInitBonus() >= character->getInitBonus()){
            charactersSorted.push_back(character);

        // Conditions to add an element to the FRONT of the vector:
        // - If the character's InitBonus is less than the one at index 0
        } else {
            charactersSorted.insert(charactersSorted.begin(), character);
        }

        // This code isn't really fully functional. I was tired when I wrote it. If I wrote it now, we would iterate through
        // the vector and insert it properly where it is between two values. Now, it just revolves around a single pivot
        // point and doesn't check further than that. Right now, you can end up with a situation like...

        // InitBonuses: 10, 5, 7, 3
        // pass 1 - 10
        // pass 2 - 10, 5
        // pass 3 - 10, 7, 5
        // pass 4 - 10, 3, 7, 5

        // ...where even though a character has an InitBonus of 3, they still go second.

    }

    // Return our sorted characters
    return charactersSorted;

    


}

string Party::getName() {
    return m_name;
}
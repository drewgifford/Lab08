#include "Party.h"
#include "character/ICharacter.h"
#include <string>
#include <memory>
#include <iostream>
#include <random>

using namespace std;

Party::Party(string name) : m_rows_count(2), m_chars_per_row(2) {

    m_name = name;

    for(int i = 0; i < m_rows_count; i++){
        vector<shared_ptr<ICharacter>> row;
        m_rows.push_back(row);
    }
}

Party::~Party(){}

void Party::add(shared_ptr<ICharacter> character, int row){

    if (row < 0 || row >= m_rows_count){
        throw "Not enough rows";
    }

    vector<shared_ptr<ICharacter>> & charRow = m_rows.at(row);

    int length = charRow.size();

    if (length >= m_chars_per_row){
        throw "Too many characters in row";
    }

    charRow.push_back(character);

}

void Party::print(){

    for(int i = 0; i < m_rows.size(); i++){

        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        for(int j = 0; j < row.size(); j++){

            shared_ptr<ICharacter> & character = row.at(j);

            string className = character->getClassName();
            string raceName = character->getRace()->getName();

            cout << "ROW " << i+1 << " - ";
            character->printInfo(true);

        }


    }


}

bool Party::isDead(){

    vector<shared_ptr<ICharacter>> characters = getCharacters();

    for(int i = 0; i < characters.size(); i++){

        shared_ptr<ICharacter> & character = characters.at(i);

        if (character->getHealth() > 0){
            return false;
        }
    }

    return true;

}

shared_ptr<ICharacter> Party::pickRandomExposed(){

    vector<shared_ptr<ICharacter>> characters;

    for(int i = 0; i < m_rows_count; i++){

        int aliveInRow = 0;

        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        for(int j = 0; j < row.size(); j++){

            shared_ptr<ICharacter> & character = row.at(j);

            if (character->getHealth() > 0){
                characters.push_back(character);
                aliveInRow++;
            }
        }

        if (aliveInRow > 0) break;
    }



    return characters.at(rand() % characters.size());


}


vector<shared_ptr<ICharacter>> Party::getCharacters(){
    vector<shared_ptr<ICharacter>> characters;

    for(int i = 0; i < m_rows.size(); i++){

        vector<shared_ptr<ICharacter>> & row = m_rows.at(i);

        for(int j = 0; j < row.size(); j++){

            shared_ptr<ICharacter> & character = row.at(j);
            characters.push_back(character);
            
        }
    }
    return characters;
}

vector<shared_ptr<ICharacter>> Party::getAliveCharacters(){
    vector<shared_ptr<ICharacter>> characters = getCharacters();
    vector<shared_ptr<ICharacter>> aliveCharacters;

    for(int i = 0; i < characters.size(); i++){
        if(characters.at(i)->getHealth() > 0){
            aliveCharacters.push_back(characters.at(i));
        }
    }
    return aliveCharacters;

}

vector<shared_ptr<ICharacter>> Party::sortCharactersByInit(){

    vector<shared_ptr<ICharacter>> characters = getCharacters();
    vector<shared_ptr<ICharacter>> charactersSorted;

    for(int i = 0; i < characters.size(); i++){
        shared_ptr<ICharacter> & character = characters.at(i);

        if (charactersSorted.size() == 0 || charactersSorted.at(0)->getInitBonus() >= character->getInitBonus()){
            charactersSorted.push_back(character);
        } else {
            charactersSorted.insert(charactersSorted.begin(), character);
        }

    }
    return charactersSorted;

    


}

string Party::getName() {
    return m_name;
}
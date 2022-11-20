#include "Party.h"
#include "character/ICharacter.h"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

Party::Party() : m_rows_count(2), m_chars_per_row(2) {

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

            cout << raceName << " " << className << " " << character->getInitBonus() << endl;

        }


    }


}
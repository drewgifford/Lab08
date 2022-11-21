#pragma once

#include "character/ICharacter.h"

#include <vector>
#include <memory>
#include <string>
using namespace std;

class Party {

    public:
        Party(string name);
        ~Party();

        void add(shared_ptr<ICharacter>, int);
        void print();

        bool isDead();

        string getName();


        vector<shared_ptr<ICharacter>> getRow(int);
        vector<shared_ptr<ICharacter>> getCharacters();
        vector<shared_ptr<ICharacter>> getAliveCharacters();

        vector<shared_ptr<ICharacter>> sortCharactersByInit();

        shared_ptr<ICharacter> pickRandomExposed();

    private:

        int m_rows_count = 2;
        int m_chars_per_row = 2;
        string m_name;
        vector<vector<shared_ptr<ICharacter>>> m_rows;
};

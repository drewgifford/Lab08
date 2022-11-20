#pragma once

#include "character/ICharacter.h"

#include <vector>
#include <memory>
using namespace std;

class Party {

    public:

        Party();
        ~Party();

        void add(shared_ptr<ICharacter>, int);
        void print();

    private:

        int m_rows_count = 2;
        int m_chars_per_row = 2;
        vector<vector<shared_ptr<ICharacter>>> m_rows;
};

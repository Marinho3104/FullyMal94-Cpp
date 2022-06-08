#include <iostream>
#include "./BigInt.hpp"

using namespace std;

#pragma once

class FullyMal94 {

    private:

        string FullyMalRepres;

        char FullyMalTable[94];


    public:

        FullyMal94();

        string getFullyValue();

        void setTable();

        void fromInt(BigInt num);
};
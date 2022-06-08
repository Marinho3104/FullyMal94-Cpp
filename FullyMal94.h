#pragma once

#include <iostream>
#include "./BigInt.hpp"

using namespace std;

class FullyMal94 {

    private:

        string FullyMalRepres;

        char FullyMalTable[94];

        BigInt expBigInt(BigInt base, BigInt exp);
        
    public:

        FullyMal94();

        string getFullyValue();
        void setFullyValue(string fullyValue);
        void setTable();

        void fromInt(BigInt num);
        BigInt toInt();

        void fromBytes(char *bytes);
        char *toBytes();
};
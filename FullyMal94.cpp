#include "./FullyMal94.h"
#include "./BigInt.hpp"


void FullyMal94::setTable() {

    for(int _ = 33, i = 0; _ < 127; _++, i++) this->FullyMalTable[i] = _;

}

void FullyMal94::fromInt(BigInt num) {

    //cout << num << endl;

    BigInt intPart, mutlIntPartTo94, val;

    while(1) {

        if (num < 94) break;

        intPart = num / 94;

        mutlIntPartTo94 = intPart * 94;

        val = num - mutlIntPartTo94;

        this->FullyMalRepres = this->FullyMalTable[val.to_int()] + this->FullyMalRepres;

        num = intPart;

    }

    if (num != 0) this->FullyMalRepres = this->FullyMalTable[val.to_int()] + this->FullyMalRepres;
    
}

FullyMal94::FullyMal94() {

    this->setTable();

}

ostream& operator<<(std::ostream& out, const FullyMal94& fllu) {

    out << fllu.getFullyValue();

    return out;

}
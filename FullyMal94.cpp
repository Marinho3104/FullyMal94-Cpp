/*
* Copyright 2022 Marinho Das Obras Inc. All rights reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "./FullyMal94.h"
#include "./BigInt.hpp"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

BigInt FullyMal94::expBigInt(BigInt base, BigInt exp) {

    bool odd = exp % 2 != 0 ? true : false;

    BigInt expCount = 0; 
    BigInt expTry = 1;
    BigInt result = 1;

    while(1) {

        if (exp < 2147483648) break;

        exp = exp / expTry;

        expTry+=10;

        expCount++;

    }

    for(int _ = 0; _ < expCount - 1; _++) result *= pow(base, exp.to_int());

    if (odd && expCount != 0) result *= pow(base, exp.to_int() + 1);

    else if (expCount == 0) result *= pow(base, exp.to_int());

    return result;

}

string FullyMal94::getFullyValue() {
    return this->FullyMalRepres;
}

void FullyMal94::setFullyValue(string fullyValue) { this->FullyMalRepres = fullyValue; }

void FullyMal94::setTable() {

    for(int _ = 33, i = 0; _ < 127; _++, i++) this->FullyMalTable[i] = _;

}


void FullyMal94::fromInt(BigInt num) {

    BigInt intPart, mutlIntPartTo94, val;

    while(1) {

        if (num < 94) break;

        intPart = num / 94;

        mutlIntPartTo94 = intPart * 94;

        val = num - mutlIntPartTo94;

        this->FullyMalRepres = this->FullyMalTable[val.to_int()] + this->FullyMalRepres;

        num = intPart;

    }

    this->FullyMalRepres = this->FullyMalTable[num.to_int()] + this->FullyMalRepres;
    
}

BigInt FullyMal94::toInt() {

    vector<int> indexNum;

    BigInt num = 0;
    BigInt _pow;
    BigInt _mul;
    BigInt expCount;

    for (int _ = 0; _ < this->FullyMalRepres.size(); _++) indexNum.push_back(int(this->FullyMalRepres[_]) - 33);

    expCount = indexNum.size() - 1;

    for (int _ = 0; _ < indexNum.size(); _++) {

        _pow = this->expBigInt(94, expCount);

        _mul = _pow * indexNum.at(_);

        num += _mul;

        expCount--;

    }

    return num;

}

void FullyMal94::fromBytes(char *bytes) {
    
    string bytesAll;

    for (int _ = 0; _ < strlen(bytes); _++) {
        
        string _temp = to_string(int(bytes[_]));

        for (int __ = 0; __ < 3 - _temp.size(); __++) _temp = "0" + _temp;

        bytesAll += _temp;
    }

    this->fromInt(bytesAll);

}

char *FullyMal94::toBytes() {

    string _val = this->toInt().to_string();

    while(_val.size() % 3 != 0) _val = "0" + _val;

    char *bytes = (char*) malloc(sizeof(char) * (_val.size() / 3));

    for (int _ = 0, i = 0; _ < _val.size(); _+=3, i++) bytes[i] = int(stoi(_val.substr(_, 3)));

    return bytes;
}


FullyMal94::FullyMal94() {

    this->setTable();

}

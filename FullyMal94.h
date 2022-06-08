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
#include "FullyMal94.h"
#include "FullyMal94.cpp"
#include <iostream>
#include <string.h>

using namespace std;

int main() {

    FullyMal94 fllu;
 
    char *tt = "polkjhgfdsaqwer";

    fllu.fromInt(string("112111108107106104103102100115097113119101114"));

    cout << fllu.toBytes() << endl;

    return 0;

}
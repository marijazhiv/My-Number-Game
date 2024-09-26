#pragma once
// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.

#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Generator
{
public:
    Generator(int s, int v);

    ~Generator()
    {
        delete a;
    }

    bool doNext();

    vector<int> generateVector();

private:
    int* a;
    int cSlots;
    int cValues;
    int nextInd;
};




// Marija Živanoviæ, SV 19/2021
// datum poslednje izmene: 11.01.2023.
#include "Generator.h"

//GENERISANJE PERMUTACIJA S PONAVLJANJEM

// Konstruktor klase generator
Generator::Generator(int s, int v) : cSlots(s), cValues(v)
{
    a = new int[s];

    for (int i = 0; i < cSlots - 1; i++) {
        a[i] = 1;
    }
    a[cSlots - 1] = 0;

    nextInd = cSlots;
}

// Kod za generisanje narednog
bool Generator::doNext()
{
    while (1)
    {
        if (a[nextInd - 1] == cValues) {
            nextInd--;
            if (nextInd == 0)
                return false;
        }
        else {
            a[nextInd - 1]++;
            while (nextInd < cSlots) {
                nextInd++;
                a[nextInd - 1] = 1;
            }

            return true;
        }
    }
}


// Generisemo vektor elemenata tipa int
vector<int> Generator::generateVector()
{
    vector<int> brojevi;  //vektor brojeva


    for (int i = 0; i < cSlots; i++) {   //od 0 do broj mesta, cSlots je broj mesta npr 5.
        brojevi.push_back(a[i] - 1);  //dok je brojac manji od broja mesta u taj vektor ubacujemo i, odnosno i-1 jer to posmatramo kao INDEXE
    }
    return brojevi;         //to su samo indexi operacija (0,1,.... br mesta)--> vraceni kao vektor

}
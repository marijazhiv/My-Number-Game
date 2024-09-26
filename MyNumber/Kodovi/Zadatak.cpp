#include "Zadatak.h"
// Marija Živanoviæ, SV 19/2021
// Poslednja izmena: 11.01.2023.

using namespace std;

Zadatak::Zadatak() {};  //Prazan konstruktor

Zadatak::Zadatak(int tacno, int ponudjeni[]) : tacan(tacno), brojevi(), numbersPermutations(6, 0) {
    for (int i = 0; i < 6; i++) {
        brojevi[i] = ponudjeni[i];    //Konstruktor sa atributima
    }
}


//dobijanje tacnog resenja zadatka
int Zadatak::getTacan() const {
    return tacan;
}
//postavljanje tacnog resenja zadatka
void Zadatak::setTacan(int tacan) {
    this->tacan = tacan;
}
// POSTAVKA ZADATKA
void Zadatak::printNumbers() const {
    std::cout << "ponudjeni brojevi" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << brojevi[i] << std::endl;
    }
    std::cout << "trazeni broj " << tacan << std::endl;

}



//funkcija kojom racunar dobija svoj izraz pomocu permutacija
std::string Zadatak::izracunaj() {
    int kopija_brojeva[6];
    for (int i = 0; i < 6; i++) {
        kopija_brojeva[i] = brojevi[i];
    }
    sort(kopija_brojeva, kopija_brojeva + 3);
    for (int brZnakova = 2; brZnakova < 6; brZnakova++) {
        do {
            for (int i = 0; i < 6; i++) {
                numbersPermutations[i] = kopija_brojeva[i];     
            }
            int n = 6;
            if (checkAllPermutationsWithRepetitions(brZnakova, n)) {
                return generatedExpression;
                break;
            }

        } while (next_permutation(kopija_brojeva, kopija_brojeva + 6));




    }


    return generatedExpression;
}

//racunar nije uspeo da nadje tacno resenje--> funkcijom izracunajPriblizno trazi najblize tacno resenje tj njegov izraz
std::string Zadatak::izracunajPriblizno() {
    int kopija_brojeva[6];
    for (int i = 0; i < 6; i++) {
        kopija_brojeva[i] = brojevi[i];
    }
    sort(kopija_brojeva, kopija_brojeva + 3);
    for (int brZnakova = 2; brZnakova < 6; brZnakova++) {
        do {
            for (int i = 0; i < 6; i++) {
                numbersPermutations[i] = kopija_brojeva[i];      
            }
            int n = 6;
            if (checkAllPermutationsWithRepetitions(brZnakova, n)) {
                return generatedExpression;
                break;
            }

        } while (next_permutation(kopija_brojeva, kopija_brojeva + 6));




    }


    return generatedExpression;
}

bool Zadatak::pronadjenaVrednost(vector<int> chosen) {         //ako su dva jedan do drugog ne racunaj
    vector<char> operacije{ '+', '-', '*', '/', '&', '^' };
    string izraz = "";
    int brojevi = chosen.size() + 1;

    for (int i = 0; i < chosen.size() - 1; i++) {
        if ((chosen[i] == 4 || chosen[i] == 5) && (chosen[i + 1] == 4 || chosen[i + 1] == 5)) {
            return false;
        }

    }


    for (int i = 0; i < brojevi; i++) {
        izraz = izraz + to_string(numbersPermutations[i]);
        if (i != brojevi - 1) {
            izraz += operacije[chosen[i]];
        }
    }

    for (int i = 0; i < izraz.length(); i++) {
        if (izraz[i] == '&') {
            izraz[i] = '+';
            string noviIzraz;
            if (i - 2 > 0 && isdigit(izraz[i - 2])) {
                noviIzraz = izraz.substr(0, i - 2);
                noviIzraz = noviIzraz + "(" + izraz[i - 2] + izraz[i - 1] + izraz[i];
            }
            else {
                noviIzraz = izraz.substr(0, i - 1);
                noviIzraz = noviIzraz + "(" + izraz[i - 1] + izraz[i];
            }

            if (i + 2 < izraz.length() && isdigit(izraz[i + 2])) {
                noviIzraz = noviIzraz + izraz[i + 1] + izraz[i + 2] + ")";
                int doKraja = izraz.length() - (i + 3);
                noviIzraz += izraz.substr(i + 3, doKraja);
                izraz = noviIzraz;
                i++;
            }
            else {
                noviIzraz = noviIzraz + izraz[i + 1] + ")";
                int doKraja = izraz.length() - (i + 2);
                noviIzraz += izraz.substr(i + 2, doKraja);
                izraz = noviIzraz;
            }
            i += 3;

        }
        else if (izraz[i] == '^') {
            izraz[i] = '-';
            string noviIzraz;
            if (i - 2 > 0 && isdigit(izraz[i - 2])) {
                noviIzraz = izraz.substr(0, i - 2);
                noviIzraz = noviIzraz + "(" + izraz[i - 2] + izraz[i - 1] + izraz[i];
            }
            else {
                noviIzraz = izraz.substr(0, i - 1);
                noviIzraz = noviIzraz + "(" + izraz[i - 1] + izraz[i];
            }

            if (i + 2 < izraz.length() && isdigit(izraz[i + 2])) {
                noviIzraz = noviIzraz + izraz[i + 1] + izraz[i + 2] + ")";
                int doKraja = izraz.length() - (i + 3);
                noviIzraz += izraz.substr(i + 3, doKraja);
                izraz = noviIzraz;
                i++;
            }
            else {
                noviIzraz = noviIzraz + izraz[i + 1] + ")";
                int doKraja = izraz.length() - (i + 2);
                noviIzraz += izraz.substr(i + 2, doKraja);
                izraz = noviIzraz;
            }
            i += 3;
        }
    }

    Izraz<int> izrazI(izraz + ";", 0);
    int r = (int)izrazI.expression();
    if (r == tacan) {

        generatedExpression = izraz;

        return true;
    }
    else {

        return false;
    }


    return true;
}






bool Zadatak::pronadjenaVrednostPriblizno(vector<int> chosen) {         //ako su dva jedan do drugog ne racunaj
    vector<char> operacije{ '+', '-', '*', '/', '&', '^' };
    string izraz = "";
    int brojevi = chosen.size() + 1;

    for (int i = 0; i < chosen.size() - 1; i++) {
        if ((chosen[i] == 4 || chosen[i] == 5) && (chosen[i + 1] == 4 || chosen[i + 1] == 5)) {
            return false;
        }

    }
//RAD SA OPERANDIMA VECEG PRIORITETA- & I ^

    for (int i = 0; i < brojevi; i++) {
        izraz = izraz + to_string(numbersPermutations[i]);
        if (i != brojevi - 1) {
            izraz += operacije[chosen[i]];
        }
    }

    for (int i = 0; i < izraz.length(); i++) {
        if (izraz[i] == '&') {
            izraz[i] = '+';
            string noviIzraz;
            if (i - 2 > 0 && isdigit(izraz[i - 2])) {
                noviIzraz = izraz.substr(0, i - 2);
                noviIzraz = noviIzraz + "(" + izraz[i - 2] + izraz[i - 1] + izraz[i];
            }
            else {
                noviIzraz = izraz.substr(0, i - 1);
                noviIzraz = noviIzraz + "(" + izraz[i - 1] + izraz[i];
            }

            if (i + 2 < izraz.length() && isdigit(izraz[i + 2])) {
                noviIzraz = noviIzraz + izraz[i + 1] + izraz[i + 2] + ")";
                int doKraja = izraz.length() - (i + 3);
                noviIzraz += izraz.substr(i + 3, doKraja);
                izraz = noviIzraz;
                i++;
            }
            else {
                noviIzraz = noviIzraz + izraz[i + 1] + ")";
                int doKraja = izraz.length() - (i + 2);
                noviIzraz += izraz.substr(i + 2, doKraja);
                izraz = noviIzraz;
            }
            i += 3;

        }
        else if (izraz[i] == '^') {
            izraz[i] = '-';
            string noviIzraz;
            if (i - 2 > 0 && isdigit(izraz[i - 2])) {
                noviIzraz = izraz.substr(0, i - 2);
                noviIzraz = noviIzraz + "(" + izraz[i - 2] + izraz[i - 1] + izraz[i];
            }
            else {
                noviIzraz = izraz.substr(0, i - 1);
                noviIzraz = noviIzraz + "(" + izraz[i - 1] + izraz[i];
            }

            if (i + 2 < izraz.length() && isdigit(izraz[i + 2])) {
                noviIzraz = noviIzraz + izraz[i + 1] + izraz[i + 2] + ")";
                int doKraja = izraz.length() - (i + 3);
                noviIzraz += izraz.substr(i + 3, doKraja);
                izraz = noviIzraz;
                i++;
            }
            else {
                noviIzraz = noviIzraz + izraz[i + 1] + ")";
                int doKraja = izraz.length() - (i + 2);
                noviIzraz += izraz.substr(i + 2, doKraja);
                izraz = noviIzraz;
            }
            i += 3;
        }
    }

    Izraz<int> izrazI(izraz + ";", 0);
    int r = (int)izrazI.expression();
    if (abs(tacan - r) < 10) {

        generatedExpression = izraz;

        return true;
    }
    else {

        return false;
    }


    return true;
}







bool Zadatak::checkAllPermutationsWithRepetitions(int brMesta, int brojeva) {

    Generator generator(brMesta, brojeva);      //brojeva = 6 jer imamo 6 operacija +-*.()
    while (generator.doNext()) {
        vector<int> perm = generator.generateVector();
        if (pronadjenaVrednost(perm)) {
            return true;
        }
    }


    return false;
}



bool Zadatak::checkAllPermutationsWithRepetitionsPriblizno(int brMesta, int brojeva) {

    Generator generator(brMesta, brojeva);      //brojeva = 6 jer imamo 6 operacija +-*.()
    while (generator.doNext()) {
        vector<int> perm = generator.generateVector();
        if (pronadjenaVrednost(perm)) {
            return true;
        }
    }


    return false;
}


string Zadatak::getBrojeviFormated() const {
    string s = "";
    for (int i = 0; i < 6; i++) {
        s = s + to_string(brojevi[i]) + " ";

    }
    return s;
}

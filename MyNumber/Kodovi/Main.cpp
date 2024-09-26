#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include "Zadatak.h"
#include <vector>
#include "Odgovor.h"
#include <iostream>
#include <sstream>
#include "Runda.h"
#include <stdlib.h>

// Marija Živanoviæ, SV 19/2021
// Poslednja izmena: 11.1.2023.

using namespace std;

// funckija validacije za izraz koji korisnik unese ZA BROJEVE (iskoristi one koji nisu zadati u tekstu zadatka jednom ili vise puta)
vector<int> validacija(string izraz, Zadatak* zadatak) {
    //prvo operande zamenjuje praznim stringom
    replace(izraz.begin(),
        izraz.end(),
        '+',
        ' ');

    replace(izraz.begin(),
        izraz.end(),
        '-',
        ' ');

    replace(izraz.begin(),
        izraz.end(),
        '*',
        ' ');

    replace(izraz.begin(),
        izraz.end(),
        '/',
        ' ');

    replace(izraz.begin(),
        izraz.end(),
        '(',
        ' ');
    replace(izraz.begin(),
        izraz.end(),
        ')',
        ' ');

    vector<int> brojevi;
    stringstream ss;
    ss << izraz;

    string temp;
    int br;
    while (!ss.eof()) {

        ss >> temp;
        //ptolazimo kroz korisnicki unos i svaki broj push-ujemo u vektor brojevi
        if (stringstream(temp) >> br) {
            brojevi.push_back(br);
        }
        temp = "";
    }

    //prolazak kroz svaki broj iz unsa korisnika i provera da li se nalazi u brojevima iz zadatka (brZadatka), isto vektor
    std::vector<int>::iterator it;
    vector<int> brZadatka = zadatak->getBrojevi();
    for (int i = 0; i < brojevi.size(); i++) {
        int num = brojevi[i];

        it = find(brZadatka.begin(), brZadatka.end(), num);
        if (it == brZadatka.end()) {
            cout << "Pogresan unos!" << endl;
            break;
        }
        //ako se nalaze ali ne onoliko puta koliko je korisnik uneo---> opet pogresan unos
        if (count(brojevi.begin(), brojevi.end(), num) != count(brZadatka.begin(), brZadatka.end(), num)) {
            cout << "Pogresan unos!" << endl;
            break;
        }

    }




    return  brojevi;

}

// funkcija split_string deli liniju iz fajla na osnovu pozicije delimtera
Zadatak* split_string(string linija) {
    int tacan;
    int brojevi[6];
    int brojac = 0;
    size_t pos = 0;
    string delimiter = "|";
    while ((pos = linija.find(delimiter)) != std::string::npos) {
        string token = linija.substr(0, pos);

        int broj = stoi(token);
        linija.erase(0, pos + delimiter.length());
        brojevi[brojac] = broj;
        brojac++;
    }
    tacan = stoi(linija);

    Zadatak* zadatak = new Zadatak(tacan, brojevi);
    return zadatak;
}


// Ucitavanje iz ulaznog fajla
vector<Zadatak*> read_file(string file_name) {
    string line;
    ifstream myfile(file_name);
    vector<Zadatak*> zadaci;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line.empty()) {
                continue;
            }
            Zadatak* zadatak = split_string(line);
            zadaci.push_back(zadatak);
        }
        myfile.close();
    }
    return zadaci;
}

// Ispis u izlazni fajl
void write_file(vector<Runda*> runde, string fileName) {
    ofstream myfile(fileName);
    if (myfile.is_open())
    {
        for (int i = 0; i < runde.size(); i++) {
            Runda* runda = runde[i];
            myfile << i + 1 << " ";

            myfile << runda->getZadatak()->getBrojeviFormated();
            int tacan = runda->getZadatak()->getTacan();

            myfile << tacan << " ";

            myfile << runda->getOdgovor1()->getIgrac()->getUsername() << " ";

            int prviDobio = abs((int)runda->getOdgovor1()->getIzraz()->getVrednost() - tacan);

            myfile << prviDobio << " ";

            myfile << runda->getOdgovor1()->getIzraz()->getIzraz() << " ";


            myfile << runda->getOdgovor2()->getIgrac()->getUsername() << " ";

            myfile << runda->getOdgovor2()->getIzraz()->getVrednost() << " ";

            int drugiDobio = abs(runda->getOdgovor2()->getIzraz()->getVrednost() - tacan);

            myfile << drugiDobio << " ";

            myfile << runda->getOdgovor2()->getIzraz()->getIzraz() << " ";


            if (prviDobio < drugiDobio) {
                myfile << runda->getOdgovor1()->getIgrac()->getUsername() << " ";

                int dobio = runda->getOdgovor1()->getIgrac()->getBrDobijenih();

                int rezultat = dobio + 1;

                runda->getOdgovor1()->getIgrac()->setBrDobijenih(rezultat);

            }
            else if (prviDobio > drugiDobio) {
                myfile << runda->getOdgovor2()->getIgrac()->getUsername() << " ";

                int dobio = runda->getOdgovor2()->getIgrac()->getBrDobijenih();

                int rezultat = dobio + 1;

                runda->getOdgovor2()->getIgrac()->setBrDobijenih(rezultat);

            }
            else {
                myfile << runda->getOdgovor1()->getIgrac()->getUsername() << " ";

                int dobio = runda->getOdgovor1()->getIgrac()->getBrDobijenih();

                int rezultat = dobio + 1;

                runda->getOdgovor1()->getIgrac()->setBrDobijenih(rezultat);

            }


            myfile << runda->getZadatak()->izracunaj() << '\n';
        }
        string prvi = runde[0]->getOdgovor1()->getIgrac()->getUsername();

        int prviRez = runde[0]->getOdgovor1()->getIgrac()->getBrDobijenih();

        myfile << "Dobio " << prvi << ": " << prviRez << endl;

        string drugi = runde[0]->getOdgovor2()->getIgrac()->getUsername();

        int drugiRez = runde[0]->getOdgovor2()->getIgrac()->getBrDobijenih();

        myfile << "Dobio " << drugi << ": " << drugiRez << endl;
        if (prviRez > drugiRez) {

            myfile << "Pobednik je: " << prvi << endl;
        }
        else if (drugiRez > prviRez) {

            myfile << "Pobednik je: " << drugi << endl;
        }
        else {
            myfile << "Nereseno je" << endl;
        } myfile.close();




    }

    else cout << "Ne moze da se otvori fajl";
}



// funkcija game() omogucava unos i racunanje korisnickih izraza.
vector<Runda*> game(vector<Zadatak*> zadaci) {
    Player* playerA = new Player(0, "PlayerA", 0);
    Player* playerB = new Player(1, "PlayerB", 0);

    Player* naPotezu = playerA;
    vector<Runda*> runde;
    //PROLAZIMO KROZ ZHADATKE DOK IH IMA
    for (int i = 0; i < zadaci.size(); i++) {
        Zadatak* zadatak = zadaci[i];

        string calculated = zadatak->izracunaj();
        if (calculated.empty()) {
            calculated = zadatak->izracunajPriblizno();
        }
        zadatak->printNumbers();


        Runda* runda = new Runda();
        runda->setZadatak(zadatak);
        string numbers = zadatak->getBrojeviFormated();
        //ODREDJIVANJE KOJI JE PLAYER NA POTEZU
        if (i % 2 == 0) {  //PARNE RUNDE IGRA B NEPARNE A
            naPotezu = playerB;
            cout << "Na potezu je PlayerB" << endl;
            string inputExpression;
            getline(cin, inputExpression);
            validacija(inputExpression, zadatak);

            inputExpression += ";";
            Izraz<int>* expression = new Izraz<int>(inputExpression, -1);

            Odgovor* odgovor = new Odgovor(naPotezu, expression);

            runda->setOdgovor1(odgovor);

            double result = expression->expression();
            if (result == -1) {
                cout << "Pogresan unos" << endl;
            }
            cout << "Vasa vrednost je: " << result << endl;

            //AKO PRVI POGRESNO ODGOVORI, DAJE SE SANSA DRUGOM, TEK NAKON TOGA RACUNAR PRINTA RESENJE DO KOG JE DOSAO

            if (result == zadatak->getTacan()) {
                cout << "Bravo! Pronasli ste tacno resenje!" << endl;
                cout << "Racunar je dosao do resenja: " << calculated << endl;
                //int dobijene = naPotezu->getBrDobijenih() + 1;
                //naPotezu->setBrDobijenih(dobijene);
                Izraz<int>* prazanExpr = new Izraz<int>("", -1);
                Odgovor* odgovor = new Odgovor(playerA, prazanExpr);

                runda->setOdgovor2(odgovor);
            }
            else {
                cout << "Pogresili ste! :(" << endl;
                cout << "PlayerA je na potezu" << endl;
                string inputExpression;
                getline(cin, inputExpression);
                validacija(inputExpression, zadatak);

                inputExpression += ";";
                Izraz<int>* expression = new Izraz<int>(inputExpression, -1);

                Odgovor* odgovor = new Odgovor(playerA, expression);

                runda->setOdgovor2(odgovor);

                double result = expression->expression();
                cout << "Vasa vrednost je: " << result << endl;

                if (result == zadatak->getTacan()) {
                    cout << "Bravo! Pronasli ste tacno resenje!" << endl;
                    cout << "Racunar je dosao do resenja: " << calculated << endl;
                    //int dobijene = naPotezu->getBrDobijenih() + 1;
                    //naPotezu->setBrDobijenih(dobijene);
                }
                else {
                    cout << "Pogresili ste! :(" << endl;
                    cout << "Racunar je dosao do resenja: " << calculated << endl;

                }
            }

        }
        else { //ISTO TAKO I KADA JE PRVI NA REDU A
            naPotezu = playerA;
            cout << "Na potezu je playerA." << endl;
            string inputExpression;
            getline(cin, inputExpression);
            validacija(inputExpression, zadatak);
            inputExpression += ";";
            Izraz<int>* expression = new Izraz<int>(inputExpression, -1);

            Odgovor* odgovor = new Odgovor(naPotezu, expression);

            runda->setOdgovor1(odgovor);

            double result = expression->expression();
            cout << "Vasa vrednost je: " << result << endl;

            if (result == zadatak->getTacan()) {
                cout << "Bravo! Pronasli ste tacno resenje!" << endl;
                cout << "Racunar je dosao do resenja: " << calculated << endl;
                //int dobijene = naPotezu->getBrDobijenih() + 1;
                //naPotezu->setBrDobijenih(dobijene);
                Izraz<int>* prazanExpr = new Izraz<int>("", -1);
                Odgovor* odgovor = new Odgovor(playerA, expression);
            }
            else {
                cout << "Pogresili ste! :(" << endl;
                cout << "PlayerB je na potezu" << endl;
                naPotezu = playerB;
                string inputExpression;
                getline(cin, inputExpression);
                validacija(inputExpression, zadatak);
                inputExpression += ";";
                Izraz<int>* expression = new Izraz<int>(inputExpression, -1);

                Odgovor* odgovor = new Odgovor(playerB, expression);

                runda->setOdgovor2(odgovor);

                double result = expression->expression();
                cout << "Vasa vrednost je: " << result << endl;

                if (result == zadatak->getTacan()) {
                    cout << "Bravo! Pronasli ste tacno resenje!" << endl;
                    cout << "Racunar je dosao do resenja: " << calculated << endl;
                    //int dobijene =  naPotezu->getBrDobijenih() + 1;
                    //naPotezu->setBrDobijenih(dobijene);
                }
                else {
                    cout << "Pogresili ste! :(" << endl;
                    cout << "Racunar je dosao do resenja: " << calculated << endl;
                    //cout << "PlayerB je na potezu" << endl;
                    naPotezu = playerB;


                }

                naPotezu = playerB;


            }
        }

        runde.push_back(runda);
    }
    return runde;
}

//DELOKACIJA

void dealocateGame(vector<Runda*> runde) {
    for (int i = 0; i < runde.size(); i++) {
        Runda* runda = runde[i];

        free(runda->getOdgovor1()->getIzraz());
        free(runda->getOdgovor1());

        free(runda->getOdgovor2()->getIzraz());
        free(runda->getOdgovor2());

        free(runda->getZadatak());
        free(runda);
    }
}


int main(int argc, char** argv)
{
    char* imeFajla = argv[1];   //KOMANDNA LINIJA

    //PARAMETAR KOJI SE PROSLEDJUJE PREKO ARGUMENTA KOMANDNE LINIJ JE NAZIV FAJLA (imeFajla)

    vector<Zadatak*> zadaci = read_file(imeFajla);
    vector<Runda*> runde = game(zadaci);
    write_file(runde, "Rezultat.txt");  //NAKON UPISA U IZLAZNI FAJL REZULTATI.TXT VRSI SE DELOKACIJA RUNDE
    dealocateGame(runde);
    return 0;
}


#include "Entite.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
using namespace std;

const unsigned int REPETITIONS = 1000;
const unsigned int LIMITE_VAR = 10000;
static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

char Entite::gettype () const{
    return type;
}
void Entite::settype (char type_x){
    type = type_x;
}

char Entite::getsymbole () const{
    return symbole;
}
void Entite::setsymbole (char symbole_x){
    symbole = symbole_x;
}

Entite::Entite(){
    type = '0';
    symbole = '0';
}

Entite:: Entite(char type_x, char symbole_x){
    type = type_x;
    symbole = symbole_x;
}

Entite:: Entite(const Entite & ent_copie){
    type = ent_copie.type;
    symbole = ent_copie.symbole;
}

void Entite::testRegressionEntite() {
    cout << endl << "Exécution des tests de régression de la classe Entite : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Entite : " << endl;
        cout << "Test des constructeurs et des accesseurs...";
        if (rand() % 2) {
            Entite entiteTest1;

            //cout << "Nouvelle Entite vide créée (constructeur vide)" << endl;

            assert(entiteTest1.gettype()=='0');
            assert(entiteTest1.getsymbole()=='0');
        }
        else {
            char type = '0' + rand() % 256 + 1;
            char symbole = '0' + rand() % 256 + 1;

            Entite entiteTest1 (type, symbole);

            //cout << "Nouvelle Entite créée (constructeur avec paramètres)" << endl;

            assert(entiteTest1.gettype() == type);
            assert(entiteTest1.getsymbole() == symbole);
        }

        cout << "ok" << endl;

        cout << "Test des mutateurs...";

        Entite entiteTest2;

        for (unsigned int i = 0; i < REPETITIONS; i++) {
            char type = '0' + rand() % 256 + 1;
            char symbole = '0' + rand() % 256 + 1;

            entiteTest2.settype(type);
            entiteTest2.setsymbole(symbole);

            assert(entiteTest2.gettype() == type);
            assert(entiteTest2.getsymbole() == symbole);
        }

        cout << "ok" << endl;

        cout << "Test du constructeur par copie...";

        for (unsigned int i = 0; i < REPETITIONS; i++) {
            char type = '0' + rand() % 256 + 1;
            char symbole = '0' + rand() % 256 + 1;

            Entite entiteTest3 (type, symbole);

            Entite entiteTest4 (entiteTest3);

            assert(entiteTest4.gettype() == type);
            assert(entiteTest4.getsymbole() == symbole);
        }

        cout << "ok" << endl;

    }
    cout << endl << "Tests de régression de la classe Entite : ok !" << endl << endl;
}

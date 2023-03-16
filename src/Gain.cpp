#include "Gain.h"

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

Gain::Gain(){
    Entite g;
    gain = g;
    cumulGain = 0;
    posX = 0;
    posY = 0;
}

Gain::~Gain(){

}

unsigned int Gain::getCumulGain() const{
    return cumulGain;
}

void Gain::setCumulGain(unsigned int CumulGain){
    cumulGain = CumulGain;
}

unsigned int Gain::getPosX() const {
    return posX;
}

void Gain::setPosX(unsigned int PosX){
    posX = PosX;
}

unsigned int Gain::getPosY() const{
    return posY;
}
void Gain::setPosY(unsigned int PosY){
    posY = PosY ;
}

void Gain::testRegressionGain() {
    cout << endl << "Exécution des tests de régression de la classe Gain : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Gain : " << endl;
        cout << "Test des constructeurs et des accesseurs...";
        
        Gain gainTest1;

        assert(gainTest1.getCumulGain() == 0);
        assert(gainTest1.getPosX() == 0);
        assert(gainTest1.getPosY() == 0);

        cout << "ok" << endl;

        cout << "Test des mutateurs...";

        Gain gainTest2;

        for (unsigned int i = 0; i < REPETITIONS; i++) {
            unsigned int cumulGain = rand() % LIMITE_VAR;
            unsigned int posX = rand() % LIMITE_VAR;
            unsigned int posY = rand() % LIMITE_VAR;

            gainTest2.setCumulGain(cumulGain);
            gainTest2.setPosX(posX);
            gainTest2.setPosY(posY);

            assert(gainTest2.getCumulGain() == cumulGain);
            assert(gainTest2.getPosX() == posX);
            assert(gainTest2.getPosY() == posY);
        }

        cout << "ok" << endl;

    }
    cout << endl << "Tests de régression de la classe Gain : ok !" << endl << endl;
}

#include "Ennemi.h"
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


Ennemi::Ennemi(){
    Entite enn;
    ennemi = enn;
    dimX = 0;
    dimY = 0;
    PVmax = 1;
    PV = 1;
    Attaque = 0;
    posX = 0;
    posY = 0;
    ennemi.setsymbole('$');
    parcourue = 0;
    mort = false;
}

unsigned int Ennemi:: getdimX () const {
    return dimX;
}

void Ennemi::setdimX (unsigned int dim_x){
    dimX = dim_x;
}

unsigned int Ennemi:: getdimY () const {
    return dimY;
}

void Ennemi::setdimY (unsigned int dim_y){
    dimY = dim_y;
}

unsigned int Ennemi::getPosX() const {
    return posX;
}

void Ennemi::setPosX(unsigned int PosX){
    posX = PosX;
}

unsigned int Ennemi::getPosY() const{
    return posY;
}
void Ennemi::setPosY(unsigned int PosY){
    posY = PosY ;
}

unsigned int Ennemi:: getPVmax () const {
    return PVmax;
}

void Ennemi::setPVmax (unsigned int pv_max){
    PVmax = pv_max;
}

unsigned int Ennemi:: getPV () const {
    return PV;
}

void Ennemi::setPV (unsigned int pv){
    PV = pv;
}

unsigned int Ennemi::getParcourue() const{
    return parcourue;
}

void Ennemi::setParcourue(unsigned int parcourue_x){
    parcourue = parcourue_x;
}

unsigned int Ennemi:: getAttaque () const {
    return Attaque;
}

void Ennemi::setAttaque (unsigned int attaque){
    Attaque = attaque;
}

bool Ennemi::getMort() const{
    return mort;
}

void Ennemi::setMort(bool mort_t){
    mort = mort_t;
}

Entite Ennemi:: getennemi () const{
    return ennemi; // A TESTER (GROS DOUTES)
}

void Ennemi:: setennemi (const Entite &ennemi_x){
    ennemi.settype(ennemi_x.gettype());
    ennemi.setsymbole(ennemi_x.getsymbole());
}

//constructeur :
Ennemi::Ennemi(const Entite &ennemi_x, unsigned int dim_x, unsigned int dim_y, unsigned int pv_max, unsigned int pv, unsigned int attaque, unsigned int pos_x, unsigned int pos_y){
    ennemi = Entite(ennemi_x);  // ennemi utilise le constructeur par copie
    dimX = dim_x;
    dimY = dim_y;
    PVmax = pv_max;
    PV = pv;
    Attaque = attaque;
    posX = pos_x;
    posY = pos_y;
    parcourue = 0;
    mort = false;
}

//destructeur :
Ennemi::~Ennemi(){


}


void Ennemi::deplacementAuto(unsigned int nb_pas){
    //cas avance
    if (parcourue < nb_pas/2){
        posX ++;
        parcourue = parcourue + 1;
    }

    //cas recule
    if (parcourue < nb_pas && parcourue >= nb_pas/2){
        posX --;
        parcourue ++;
    }

    //remise a 0 du compteur
    if(parcourue == nb_pas){
        parcourue = 0;
    }
}


void Ennemi::testRegressionEnnemi() {
    cout << endl << "Exécution des tests de régression de la classe Ennemi : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Ennemi : " << endl;

        cout << "Test des constructeurs et des accesseurs...";
        if (rand() % 2) {
            Ennemi ennemiTest1;

            assert(ennemiTest1.getennemi().gettype() == '0');
            assert(ennemiTest1.getennemi().getsymbole() == '$');
            assert(ennemiTest1.getdimX() == 0);
            assert(ennemiTest1.getdimY() == 0);
            assert(ennemiTest1.getPVmax() == 1);
            assert(ennemiTest1.getPV() == 1);
            assert(ennemiTest1.getAttaque() == 0);
            assert(ennemiTest1.getPosX() == 0);
            assert(ennemiTest1.getPosY() == 0);
            assert(ennemiTest1.getParcourue() == 0);
            assert(ennemiTest1.getMort() == false);

        }
        else {
            Entite entiteTest1;
            if (rand() % 2) {
                char type = '0' + rand() % 256 + 1;
                char symbole = '0' + rand() % 256 + 1;

                entiteTest1.settype(type);
                entiteTest1.setsymbole(symbole);
            }

            unsigned int dimX = rand() % LIMITE_VAR + 1;
            unsigned int dimY = rand() % LIMITE_VAR + 1;
            unsigned int PVmax = rand() % LIMITE_VAR + 1;
            unsigned int PV = rand() % LIMITE_VAR + 1;
            unsigned int Attaque = rand() % LIMITE_VAR + 1;
            unsigned int posX = rand() % LIMITE_VAR + 1;
            unsigned int posY = rand() % LIMITE_VAR + 1;


            Ennemi ennemiTest1 (entiteTest1, dimX, dimY, PVmax, PV, Attaque, posX, posY);

            assert(ennemiTest1.getennemi().gettype() == entiteTest1.gettype());
            assert(ennemiTest1.getennemi().getsymbole() == entiteTest1.getsymbole());
            assert(ennemiTest1.getdimX() == dimX);
            assert(ennemiTest1.getdimY() == dimY);
            assert(ennemiTest1.getPVmax() == PVmax);
            assert(ennemiTest1.getPV() == PV);
            assert(ennemiTest1.getAttaque() == Attaque);
            assert(ennemiTest1.getPosX() == posX);
            assert(ennemiTest1.getPosY() == posY);
            assert(ennemiTest1.getParcourue() == 0);
            assert(ennemiTest1.getMort() == false);
        }

        cout << "ok" << endl;

        cout << "Test des mutateurs...";

        Ennemi ennemiTest2;
        for (unsigned int i = 0; i < REPETITIONS; i++) {
            Entite entiteTest1;
            char type = '0' + rand() % 256 + 1;
            char symbole = '0' + rand() % 256 + 1;

            entiteTest1.settype(type);
            entiteTest1.setsymbole(symbole);

            unsigned int dimX = rand() % LIMITE_VAR + 1;
            unsigned int dimY = rand() % LIMITE_VAR + 1;
            unsigned int PVmax = rand() % LIMITE_VAR + 1;
            unsigned int PV = rand() % LIMITE_VAR + 1;
            unsigned int Attaque = rand() % LIMITE_VAR + 1;
            unsigned int posX = rand() % LIMITE_VAR + 1;
            unsigned int posY = rand() % LIMITE_VAR + 1;
            unsigned int parcourue = rand() % LIMITE_VAR + 1;
            bool mort = rand() % 2;

            ennemiTest2.setennemi(entiteTest1);
            ennemiTest2.setdimX(dimX);
            ennemiTest2.setdimY(dimY);
            ennemiTest2.setPVmax(PVmax);
            ennemiTest2.setPV(PV);
            ennemiTest2.setAttaque(Attaque);
            ennemiTest2.setPosX(posX);
            ennemiTest2.setPosY(posY);
            ennemiTest2.setParcourue(parcourue);
            ennemiTest2.setMort(mort);

            assert(ennemiTest2.getennemi().gettype() == type);
            assert(ennemiTest2.getennemi().getsymbole() == symbole);
            assert(ennemiTest2.getdimX() == dimX);
            assert(ennemiTest2.getdimY() == dimY);
            assert(ennemiTest2.getPVmax() == PVmax);
            assert(ennemiTest2.getPV() == PV);
            assert(ennemiTest2.getAttaque() == Attaque);
            assert(ennemiTest2.getPosX() == posX);
            assert(ennemiTest2.getPosY() == posY);
            assert(ennemiTest2.getParcourue() == parcourue);
            assert(ennemiTest2.getMort() == mort);
        }

        cout << "ok" << endl;

    }
    
    cout << endl << "Tests de régression de la classe Ennemi : ok !" << endl << endl;
}
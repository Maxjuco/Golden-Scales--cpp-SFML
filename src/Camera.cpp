#include "Camera.h"

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

Camera::Camera() {

}

Camera::~Camera() {

}

unsigned int Camera::getDimX() const{
    return dimX;
}
void Camera::setDimX(unsigned int dim_x){
    dimX = dim_x;
}

unsigned int Camera::getDimY() const{
    return dimY;
}
void Camera::setDimY(unsigned int dim_y){
    dimY = dim_y;
}

int Camera::getDepart_x() const{
    return depart_x;
}
void Camera::setDepart_x(int dep){
    depart_x = dep;
}

unsigned int Camera::getArrive_x() const{
    return arrive_x;
}
void Camera::setArrive_x(unsigned int arrive){
    arrive_x = arrive;
}

Entite Camera::getChamp(unsigned int x, unsigned int y) const {
    return champ[x + (y * dimX)];
}

void Camera::setChamp(const Entite &e, unsigned int posX, unsigned int posY) {
    champ[posX + (posY * dimX)] = e;
}

void Camera::setCamera(const Terrain &terrain_x, unsigned int dim_x, unsigned int dim_y){
    dimX = dim_x;
    dimY = dim_y;

    Entite e;
    char symbole;
    for(unsigned int i=0; i<dimY+1; i++){
        for(unsigned int j=0; j<dimX; j++){
            symbole = terrain_x.getTab2DTerrain(j,i).getsymbole();
            e.setsymbole(symbole);
            //setChamp(e, j, i);
            champ.push_back(e);
        }
    }


}

void Camera::mouvementCamera(const Terrain &terrain_x, const Joueur &joueur) {
    //m�j cam�ra :
    depart_x = joueur.getPosX()+dimX/2 - dimX;
    arrive_x = joueur.getPosX()+dimX/2;

    if(depart_x < 0)
        depart_x = 0;
    if(arrive_x >= terrain_x.getTaille_x())
        arrive_x = terrain_x.getTaille_x()-1;


    Entite e;
    char symbole;
    for(unsigned int i=0; i<dimY+1; i++){
        for(unsigned int j=depart_x; j<arrive_x; j++){
            symbole = terrain_x.getTab2DTerrain(j,i).getsymbole();
            e.setsymbole(symbole);
            setChamp(e, j, i);

        }
    }

}

void Camera::testRegressionCamera() {
    cout << endl << "Exécution des tests de régression de la classe Camera : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Camera : " << endl;
        cout << "Test des accesseurs et des mutateurs...";

        Camera cameraTest1;

        unsigned int dimX = rand() % LIMITE_VAR;
        unsigned int dimY = rand() % LIMITE_VAR;

        cameraTest1.setDimX(dimX);
        cameraTest1.setDimY(dimY);

        assert(cameraTest1.getDimX() == dimX);
        assert(cameraTest1.getDimY() == dimY);

        int depart = rand() % LIMITE_VAR;
        unsigned int arrive = rand() % LIMITE_VAR;

        cameraTest1.setDepart_x(depart);
        cameraTest1.setArrive_x(arrive);

        assert(cameraTest1.getDepart_x() == depart);
        assert(cameraTest1.getArrive_x() == arrive);
        

        cout << "ok" << endl;

        

    }
    cout << endl << "Tests de régression de la classe Entite : ok !" << endl << endl;
}
#include "Terrain.h"
#include <fstream>

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
using namespace std;

const unsigned int REPETITIONS = 1000;
const unsigned int LIMITE_VAR = 1000;
static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";


Terrain::Terrain(){

}

Terrain::~Terrain(){

}

unsigned int Terrain::getTaille_x()const{
    return taille_x;
}

void Terrain::setTaille_x(unsigned int taille){
    taille_x = taille;
}

unsigned int Terrain::getNb_ennemis()const{
    return nb_ennemis;
}

void Terrain::setNb_ennemis(unsigned int nb_ennemis_x){
    nb_ennemis = nb_ennemis_x;
}

string Terrain::getNomFich(){
	return NomFichierTerrain;
}

void Terrain::setNomFich(string Fichier){
    NomFichierTerrain = Fichier;
}

Ennemi & Terrain::getListeEnnemi(unsigned int x) {
    return ListeEnnemi[x];
}

void Terrain::setListeEnnemi(const Ennemi &Ennemi_x, unsigned int x){
    ListeEnnemi[x] = Ennemi_x;
}

Entite Terrain::getTab2DTerrain(unsigned int x, unsigned int y) const{
    return Tab2DTerrain[x + (y * taille_x)];
}

void  Terrain::setTab2DTerrain(const Entite &Entite_xy, unsigned int x, unsigned int y){
    Tab2DTerrain[x + (y * taille_x)] = Entite_xy;
}

void Terrain::lireFichTerrain(){
    ifstream monFichier(NomFichierTerrain.c_str());
    string ligne;
    Entite e;
    nb_ennemis =0;//remmet nb ennemi a 0 car nouveau niveau
    //monFichier.open(NomFichierTerrain.c_str());
    if (monFichier.is_open()) {
        while (!monFichier.eof()){
            for(unsigned int i=0; i<14; i++){
                getline(monFichier, ligne);
                for(unsigned int j=0; j<taille_x; j++){
                    e.setsymbole(ligne[j]);
                    Tab2DTerrain.push_back(e); //equivalent de ajouter element
                    //cout<<getTab2DTerrain(i,j).getsymbole();
                    if(e.getsymbole() == '$'){
                        Ennemi temp;
                        temp.setennemi(e);
                        temp.setPosX(j);
                        temp.setPosY(i);
                        ListeEnnemi.push_back(temp); //met le symbole et les position de l'ennemi dans le tableau
                        nb_ennemis++;
                    }
                }
            }
        }
        monFichier.close();
    }
    else {
    cout << "Erreur d�ouverture du fichier: " << NomFichierTerrain;
    }
}

void Terrain::testRegressionTerrain() {
    cout << endl << "Exécution des tests de régression de la classe Terrain : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Terrain : " << endl;
        cout << "Test des accesseurs et des mutateurs...";
        
        Terrain terrainTest1;

        for (unsigned int i = 0; i < REPETITIONS; i++) {
            unsigned int taille = rand() % LIMITE_VAR;
            unsigned int nb_ennemis = rand() % LIMITE_VAR;
            string fichier;
            for (unsigned int j = 0; j < LIMITE_VAR; j++) {
                fichier += '0' + rand() % 256 + 1;
            }
            fichier += '\n';

            terrainTest1.setTaille_x(taille);
            terrainTest1.setNb_ennemis(nb_ennemis);
            terrainTest1.setNomFich(fichier);

            assert(terrainTest1.getTaille_x() == taille);
            assert(terrainTest1.getNb_ennemis() == nb_ennemis);
            assert(terrainTest1.getNomFich() == fichier);
        }

        cout << "ok" << endl;

    }
    cout << endl << "Tests de régression de la classe Terrain : ok !" << endl << endl;
}

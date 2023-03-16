#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>
using namespace std;

#include "Ennemi.h"
#include "Entite.h"
#include "Gain.h"
#include "Jeu.h"
#include "Jeu_SFML.h"
#include "Joueur.h"
#include "Terrain.h"

const unsigned int REPETITIONS = 1000;
const unsigned int LIMITE_VAR = 10000;
static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";


/*

void testRegressionGain() {
    cout << endl << "Exécution des tests de régression de la classe Gain : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Gain : " << endl;
        cout << "Test des constructeurs et des accesseurs...";

        Gain gainTest1;

        assert(gainTest1.getPosX() == 0);
        assert(gainTest1.getPosY() == 0);
        assert(gainTest1.getCumulGain() == 0);

        cout << "ok" << endl;

        cout << "Test des mutateurs...";

        Gain gainTest2;

        for (unsigned int i = 0; i < REPETITIONS; i++) {
            unsigned int cumulGain = '0' + rand() % 256 + 1;
            unsigned int posX = '0' + rand() % 256 + 1;
            unsigned int posY = '0' + rand() % 256 + 1;

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

void testRegressionJeu() {

}

void testRegressionJoueur() {
    cout << endl << "Exécution des tests de régression de la classe Joueur : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Joueur : " << endl;

        cout << "Test des constructeurs et des accesseurs...";
        if (rand() % 2) {
            Joueur joueurTest1;

            assert(joueurTest1.getJoueur().gettype() == '0');
            assert(joueurTest1.getJoueur().getsymbole() == '#');
            assert(joueurTest1.getPvMax() == 10);
            assert(joueurTest1.getPv() == 10);
            assert(joueurTest1.getAttaque() == 0);
            assert(joueurTest1.getPosX() == 0);
            assert(joueurTest1.getPosY() == 0);

        }
        else {
            unsigned int posX = rand() % LIMITE_VAR + 1;
            unsigned int posY = rand() % LIMITE_VAR + 1;

            Joueur joueurTest1 (posX, posY);

            assert(joueurTest1.getJoueur().gettype() == '0');
            assert(joueurTest1.getJoueur().getsymbole() == 'P');
            assert(joueurTest1.getPvMax() == 0);
            assert(joueurTest1.getPv() == 0);
            assert(joueurTest1.getAttaque() == 0);
            assert(joueurTest1.getPosX() == posX);
            assert(joueurTest1.getPosY() == posY);
        }

        cout << "ok" << endl;

        cout << "Test des mutateurs...";

        Joueur joueurTest2;
        for (unsigned int i = 0; i < REPETITIONS; i++) {

            unsigned int pvMax = rand() % LIMITE_VAR + 1;
            unsigned int pv = rand() % LIMITE_VAR + 1;
            unsigned int attaque = rand() % LIMITE_VAR + 1;
            unsigned int posX = rand() % LIMITE_VAR + 1;
            unsigned int posY = rand() % LIMITE_VAR + 1;

            joueurTest2.setPvMax(pvMax);
            joueurTest2.setPv(pv);
            joueurTest2.setAttaque(attaque);
            joueurTest2.setPosX(posX);
            joueurTest2.setPosY(posY);

            assert(joueurTest2.getPvMax() == pvMax);
            assert(joueurTest2.getPv() == pv);
            assert(joueurTest2.getAttaque() == attaque);
            assert(joueurTest2.getPosX() == posX);
            assert(joueurTest2.getPosY() == posY);
        }

        cout << "ok" << endl;

        cout << "Test de la fonction attaque_execute()...";

        //TODO : trouver un moyen de simuler des entrées clavier.

        cout << "ok" << endl;
    }

    
    cout << endl << "Tests de régression de la classe Joueur : ok !" << endl << endl;
}

void testRegressionTerrain() {
    cout << endl << "Exécution des tests de régression de la classe Terrain : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Terrain : " << endl;

        cout << "Test des mutateurs et des accesseurs...";
        
            Terrain terrainTest1;

            unsigned int taille = rand() % LIMITE_VAR + 1;
            char fich[LIMITE_VAR];
            for (unsigned int i = 0; i < LIMITE_VAR; i++) {
                fich[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
            }
            fich[LIMITE_VAR] = '\0';
            string Fichier = string(fich);
            vector <Entite> Tab2DTerrain;
            for (unsigned int i = 0; i < LIMITE_VAR; i++) {
                Entite entiteTest1;
                if (rand() % 2) {
                    char type = '0' + rand() % 256 + 1;
                    char symbole = '0' + rand() % 256 + 1;

                    entiteTest1.settype(type);
                    entiteTest1.setsymbole(symbole);
                }

                Tab2DTerrain.push_back(entiteTest1);
            }
            vector <Entite> Entites;
            for (unsigned int i = 0; i < LIMITE_VAR; i++) {
                Entite entiteTest2;
                if (rand() % 2) {
                    char type = '0' + rand() % 256 + 1;
                    char symbole = '0' + rand() % 256 + 1;

                    entiteTest2.settype(type);
                    entiteTest2.setsymbole(symbole);
                }

                Entites.push_back(entiteTest2);
            }

            terrainTest1.setNomFich(Fichier);
            terrainTest1.setTaille_x(taille);
            terrainTest1.setTab2DTerrain(Tab2DTerrain);



            assert(terrainTest1.getTaille_x() == taille);
            assert(terrainTest1.getNomFich() == Fichier);
            assert(terrainTest1.getEntites() == '0');
            assert(terrainTest1.getTab2DTerrain() == '0');

        cout << "ok" << endl;

        cout << "Test de la fonction attaque_execute()...";

        //TODO : trouver un moyen de simuler des entrées clavier.

        cout << "ok" << endl;
    }

    
    cout << endl << "Tests de régression de la classe Terrain : ok !" << endl << endl;
}*/


int main() {
    srand((unsigned int)time(NULL));

    Camera cameraTest;
    cameraTest.testRegressionCamera();

    Ennemi ennemiTest;
    ennemiTest.testRegressionEnnemi();

    Entite entiteTest;
    entiteTest.testRegressionEntite();

    Gain gainTest;
    gainTest.testRegressionGain();

    Joueur joueurTest;
    joueurTest.testRegressionJoueur();

    Terrain terrainTest;
    terrainTest.testRegressionTerrain();

    cout << "Tous les tests de régression ont été réalisés avec succès !" << endl << endl;
    
    return 0;
}

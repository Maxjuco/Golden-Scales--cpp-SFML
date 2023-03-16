#include <iostream>
#include "Jeu.h"
#include "Terrain.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std;
using namespace sf;

#ifdef WIN32
#define CLEAN_SCREEN "CLS"
#else
#define CLEAN_SCREEN "clear"
#endif



int main() {

    Terrain terrain; //constructeur terrain
    Jeu jeu; //constructeur jeu
    Joueur joueur; //constructeur joueur
    joueur.setPosX(3); //position de spawn du joueur
    joueur.setPosY(4);
    Ennemi ennemi_1; //constructeur ennemi
    ennemi_1.setPosX(25); //position du premier ennemi
    ennemi_1.setPosY(10);
    jeu.setTerrain(terrain); //initialisation du terrain créé dans jeu
    jeu.setjoueur(joueur); //initialisation du joueur créé dans jeu
    jeu.setennemi(ennemi_1); //initialisation d'un ennemi créé dans jeu

    bool fin = false; //booléen permettant de sortir de la boucle de jeu

    Entite e;
    e.setsymbole(' ');

    Clock clock;
    //Time temp = clock.getElapsedTime();
    /*int i = 0;
    while( i!= 5){
        cin>>i;
        Time time =
        temp = clock.getElapsedTime();
        cout<<temp.asSeconds()<<endl;
    }

*/

    terrain.setTaille_x(199); //initialisation de la longueur du niveau/terrain
    terrain.setNomFich("data/lvl1.txt"); // fichier contenant le terrain

    terrain.lireFichTerrain();
    terrain.setTab2DTerrain(joueur.getJoueur(), joueur.getPosX(), joueur.getPosY());
    jeu.setCam(terrain);

    float tim = 0;
    /*

    while(tim<1000 && fin == false){
        jeu.afficheTerrain(); // affiche le terrain
        jeu.gravite(); // le joueur retombe sur le sol
        //jeu.deplacementJoueur(); //déplacement avec Z,Q,S,D //mis dans boucle évennement
        //jeu.afficheTerrain();
        //jeu.attaque(); placer dans la boucle évenement
        jeu.boucleEvennement();
        jeu.gestionVie();
        Time temp = clock.getElapsedTime();
        tim = temp.asSeconds(); // stock le temps en seconde
        if(jeu.perdu()){
            fin = true;
            system(CLEAN_SCREEN);
            cout<<"Game Over";
        }
        //cout<<"\033[00m";
     }





     Clock clock; //le chrono qui compte à partir du moment où il est crée ...
    Time temp = clock.getElapsedTime(); //le "temps"
     float t = temp.asSeconds(); // temps de départ

     while (temp.asSeconds()-t < 10){//tant que le temps écoulé est inférieur à 10 sec
        temp = clock.getElapsedTime();//màj temps passer
        //FONCTION AFFICHAGE....
     }
*/

// - /!\ TEST DEPLACEMENT /!\ :
    int choix = 0;
    cout<<"Que voulez-vous faire ? (tapez 1 ou 2)"<<endl
        <<"1. Jouer"<<endl
        <<"2. Voir les developpeurs"<<endl;
    cin>>choix;
    if (choix == 1){
        while(tim<2000 && fin == false){
            jeu.afficheTerrain(); // affiche le terrain
            jeu.boucleEvennement();
            Time temp = clock.getElapsedTime();
            tim = temp.asSeconds(); // stock le temps en seconde
            if(jeu.perdu()){
                fin = true;
            }
            if(jeu.gagne()){
                fin = true;
            }
         }
         if(jeu.perdu()){
            system(CLEAN_SCREEN);
            cout<<"Game Over..."<<endl<<endl;
            cout<<"Developpeurs : "<<endl<<"Tanguy Desrues" << endl << "Maxime Cosialls" << endl << "Jules Quinton" <<endl;
         } else {
            system(CLEAN_SCREEN);
            cout<<"Victoire ! \nScore : "<<jeu.getScore()<<endl;
            cout<<"Developpeurs : "<<endl<<"Tanguy Desrues" << endl << "Maxime Cosialls" << endl << "Jules Quinton" <<endl;

         }
    } else if (choix == 2){
        system(CLEAN_SCREEN);
        cout<<"Tanguy Desrues" << endl << "Maxime Cosialls" << endl << "Jules Quinton" <<endl;
    }





    cout<<"FIN";

    jeu.Timer(5);
    system(CLEAN_SCREEN);
    exit(0);
    return 0;



}

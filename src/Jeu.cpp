#include"Jeu.h"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
void drawCharAtPos(int x,int y,char c){
	std::cout<<"\033["<<y<<";"<<x<<"H"<<c;
}

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cassert>

const unsigned int REPETITIONS = 1000;
const unsigned int LIMITE_VAR = 10000;
static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

#ifdef WIN32
#define CLEAN_SCREEN "CLS"
#else
#define CLEAN_SCREEN "clear"
#endif



Jeu::Jeu(){
    nbEnnemisVaincus = 0;
    cumulGains = 0;
    score = 0;

}

Jeu::~Jeu(){
    delete terrain;
}

bool Jeu::verifCollision(){
	return false;
}

bool Jeu::estAttaque(){
    if (terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()=='$'
        || terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()=='$'){
        return true;
    }else return false;
}

void Jeu::gestionVie(){
     //cas joueur perd de la vie
    if(terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()+1).getsymbole() == 'x'){ //piège
        joueur.setPv(joueur.getPv()-1);
    }

    if(joueur.getPosY()==13){ //trou
        joueur.setPv(0);
    }

    if(estAttaque()){ //ennemi
        joueur.setPv(joueur.getPv()-1);
    }

    //cas ennemi se fait attaquer par joueur :

    Entite e;
    e.setsymbole(' ');
    if(attaque()){// si le joueur lance une attaque
        for(unsigned int i =0; i<terrain->getNb_ennemis(); i++){
            if(terrain->getTab2DTerrain(terrain->getListeEnnemi(i).getPosX()-1, terrain->getListeEnnemi(i).getPosY()).getsymbole() == '-' || terrain->getTab2DTerrain(terrain->getListeEnnemi(i).getPosX()+1, terrain->getListeEnnemi(i).getPosY()).getsymbole() == '-' ){
                terrain->getListeEnnemi(i).setPV(terrain->getListeEnnemi(i).getPV() - 1);
            }

            //ennemi mort ? => disparait + joueur gagne +1 au score
            if(terrain->getListeEnnemi(i).getPV() == 0){
                terrain->setTab2DTerrain(e,terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY());//disparait du terrain
                terrain->getListeEnnemi(i).setMort(true); //disparazdit...
                gain.setCumulGain(cumulGains++);
            }
        }
    }
}

bool Jeu::perdu(){
    if (joueur.getPv() == 0){
        return true;
    } else return false;
}

bool Jeu::gagne(){
    if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole() == '|'){
        return true;
    } else return false;
}

void Jeu::calculScore(){
    score = nbEnnemisVaincus*100 + cumulGains*50;
}

Jeu::Jeu(const Terrain & terrain_init){
    *terrain = terrain_init;
}

bool Jeu::collecteGain(){
    if(joueur.getPosX()==gain.getPosX() && joueur.getPosY()==gain.getPosY()){
        gain.setCumulGain(cumulGains++);
        return true;
    }else return false;
}

bool Jeu::attaque(){
   Entite e;
    e.setsymbole('-');
    Entite t;
    t.setsymbole(' ');
    if(joueur.attaque_execute() ){
        if(joueur.getOrient() == 'D' &&  terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()==' ')
            terrain->setTab2DTerrain(e, joueur.getPosX()+1, joueur.getPosY()); //Affichage de l'attaque
        else if(joueur.getOrient() == 'G' &&  terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()==' ')
            terrain->setTab2DTerrain(e, joueur.getPosX()-1, joueur.getPosY()); //Affichage de l'attaque
        /*
        //temporisation :
        Clock clock;
        Time temp = clock.getElapsedTime();
        float tim = temp.asMilliseconds();

        while(tim<8) {
                temp = clock.getElapsedTime();
                tim = temp.asMilliseconds();
                afficheTerrain();//affiche le tiret
        }//boucle pour temporiser


        terrain->setTab2DTerrain(t, joueur.getPosX()+1, joueur.getPosY()); //Affichage dde l'attaque
        afficheTerrain();//"enleve" le tiret*/
        return true;
    }else return false;


}

unsigned int Jeu::getScore(){
    return score;
}

void Jeu::setScore (unsigned int Score){
    score = Score;
}

bool Jeu::collisionEnnemi(){
if ((joueur.getPosX()==ennemi.getPosX()-1 || joueur.getPosX()==ennemi.getPosX()+1 || joueur.getPosX()==ennemi.getPosX())&&
    (joueur.getPosY()==ennemi.getPosY()-1 || joueur.getPosY()==ennemi.getPosY()+1 || joueur.getPosY()==ennemi.getPosY())){
        return true;
    }else return false;
}

void Jeu::setTerrain(Terrain & terrain_x){
    terrain = &terrain_x;
}

void Jeu::setCam(Terrain terrain_x){
    cam.setCamera(terrain_x, 50, 14);
}

void Jeu::afficheTerrain(){

    system(CLEAN_SCREEN);//efface la fenêtre

    calculScore();

    cout<<"Votre score est de : "<<getScore()<<" points"<<endl;
    cout<<"Vous avez "<<joueur.getPv()<<" points de vie."<<endl;

   // if (joueur.attaque_execute()) cout<<"TATAKAÏ ! "<<endl;

    //cout<<"Ennemi a :"<<ennemi.getPV()<<" points de vie."<<endl;

   // if(ennemi.getPV() > 0) cout<<"ennemi vivant..."<<endl;
    //else cout<<"ennemi mort ..."<<endl;

   /* for(unsigned int i =0; i < terrain->getNb_ennemis(); i++){
        cout<<"ennemi "<<i<<" : "<<terrain->getListeEnnemi(i).getPV()<<endl;
    }*/

    //cout<<"ennemi 0"<<" : "<<terrain->getListeEnnemi(0).getParcourue()<<endl;

    //if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole() == '-') cout<<"OUI"<<endl;

    cam.mouvementCamera(*terrain, joueur);
    //nettoie les attaques sur le terrain :
    Entite e;
    e.setsymbole(' ');
    for(unsigned int l=0; l<14; l++){
        for(unsigned int k=cam.getDepart_x(); k<cam.getArrive_x(); k++){
                if(terrain->getTab2DTerrain(k,l).getsymbole() == '-')
                    terrain->setTab2DTerrain(e, k, l);
        }
    }

    for(unsigned int l=0; l<14; l++){
        for(unsigned int k=cam.getDepart_x(); k<cam.getArrive_x(); k++){ //parcour du tableau contenant une copie de caméra
        //for(unsigned int k=0; k<terrain->getTaille_x(); k++){ //parcour du tableau contenant une copie du terrain
            /*if(terrain->getTab2DTerrain(k,l).getsymbole() == 'Z'){
                cout<<"\033[45m";
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'I'){
                cout<<"\033[32m";
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'o'){
                cout<<"\033[33m";
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'i'){
                cout<<"\033[31m";
            }
            else cout<<"\033[00m";//terrain->getTab2DTerrain(k,l).getsymbole(); */ //tentative de mise en couleur mais rend le jeu trop lent
//            cout<<terrain->getTab2DTerrain(k,l).getsymbole(); //affiche les symboles des entit�s du tableau
            cout<<cam.getChamp(k,l).getsymbole();
        }cout<<endl;
    }
}


void Jeu::setjoueur(Joueur Joueur){
    joueur = Joueur;
}

void Jeu::setennemi(Ennemi ennemi_x){
    ennemi = ennemi_x;
}




void Jeu::deplacementDroit(){
    Entite e;
    e.setsymbole(' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && ((terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()==' ') || (terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()=='o') ))//detection de touche
        {
            //cas c'est un gain :
            if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()=='o'){
                terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX()+1, joueur.getPosY()); //Affichage du perso une case plus loin
                terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY()); //disparition du personnage sur la case pr�c�dente
                joueur.deplaceDroit(); // mise a jour de la position joueur + son orient
                cumulGains ++; //on gagne du score
            }
            else{//cas normal
                terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX()+1, joueur.getPosY()); //Affichage du perso une case plus loin
                terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY()); //disparition du personnage sur la case pr�c�dente
                joueur.deplaceDroit(); // mise a jour de la position joueur + son orient
            }
        }
}

void Jeu::deplacementGauche(){
    Entite e;
    e.setsymbole(' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && ((terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()==' ') || (terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()=='o')))
        {   //cas c'est un gain :
            if(terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()=='o'){
                terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX()-1, joueur.getPosY());
                terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
                joueur.deplaceGauche();// mise a jour de la position joueur + son orient
                cumulGains ++; //on gagne du score
            }
            else{//cas normal
            terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX()-1, joueur.getPosY());
            terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
            joueur.deplaceGauche();// mise a jour de la position joueur + son orient
            }
        }
}

void Jeu::deplacementSaut(){
    Entite e;
    e.setsymbole(' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        while(joueur.getHauteur_saut() < 3 && (terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()-1).getsymbole()==' ' || terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()-1).getsymbole()=='o')){ //peut pas monter plus de 3 cases ni dans une plateforme en un saut
            //cas c'est un gain :
            if(terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()-1).getsymbole()=='o'){
                terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX(), joueur.getPosY()-1);
                terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
                joueur.deplaceSaut();// mise a jour de la position joueur
                cumulGains ++; //on gagne du score
            }
            else{//cas normal
                terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX(), joueur.getPosY()-1);
                terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
                joueur.deplaceSaut();// mise a jour de la position joueur
            }
            deplacementDroit();
            deplacementGauche();
            deplacementEnnemiAuto(); // l'énnemi continue de se déplacer
            afficheTerrain();//affiche changement
        }

    }
}

void Jeu::gravite(){
    Entite e;
    e.setsymbole(' ');
    while(terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()+1).getsymbole()==' ' || terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()+1).getsymbole()=='o'){ //tant qu'on peux passer à travers
        //cas c un gain :
        if (terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()+1).getsymbole()=='o'){
            terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX(), joueur.getPosY()+1);
            terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
            joueur.deplaceTombe();// mise a jour de la position joueur
            cumulGains ++; //on gagne du score
        }

        else{//cas normal :
            terrain->setTab2DTerrain(joueur.getJoueur(), joueur.getPosX(), joueur.getPosY()+1);
            terrain->setTab2DTerrain(e, joueur.getPosX(), joueur.getPosY());
            joueur.deplaceTombe();// mise a jour de la position joueur
        }
        deplacementDroit();
        deplacementGauche();
        deplacementEnnemiAuto(); // l'énnemi continue de se déplacer
        afficheTerrain();//affiche changement
        }

    joueur.setHauteur_saut(0);//on remet la hauteur à 0
}




//d�placemet auto ennemi :
void Jeu::deplacementEnnemiAuto(){

    Entite e;
    e.setsymbole(' ');


    for(unsigned int i = 0; i<terrain->getNb_ennemis(); i++){
        //vérifie que l'ennemi est encore en vie :
        if(!terrain->getListeEnnemi(i).getMort()){



            //d�placement auto � droite :
            if(terrain->getListeEnnemi(i).getParcourue() < 5 && terrain->getTab2DTerrain(terrain->getListeEnnemi(i).getPosX()+1, terrain->getListeEnnemi(i).getPosY()).getsymbole() == ' '){//se d�place de 5 case
                    terrain->setTab2DTerrain(e, terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY());
                    terrain->getListeEnnemi(i).deplacementAuto(12); // Mise a jour de sa position
                    terrain->setTab2DTerrain(terrain->getListeEnnemi(i).getennemi(), terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY()); // il avance...


            }
            else if(terrain->getListeEnnemi(i).getParcourue() < 5){//cas on est bloqué à droite mais on continue d'incrémenter parcourue :
                terrain->getListeEnnemi(i).setParcourue(terrain->getListeEnnemi(i).getParcourue()+1);
            }


            //d�placement auto � gauche :
            if(terrain->getListeEnnemi(i).getParcourue() >= 5 && terrain->getTab2DTerrain(terrain->getListeEnnemi(i).getPosX()-1, terrain->getListeEnnemi(i).getPosY()).getsymbole() == ' '){//se d�place de 5 cases vers la gauche

                    terrain->setTab2DTerrain(e, terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY());
                    terrain->getListeEnnemi(i).deplacementAuto(12); // Mise a jour de sa position

                    terrain->setTab2DTerrain(terrain->getListeEnnemi(i).getennemi(), terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY()); // il avance...



            }
            else if (terrain->getListeEnnemi(i).getParcourue() >= 5){//cas on est bloqué à gauche on remet à 0
                terrain->getListeEnnemi(i).setParcourue(0);
            }
        }
    }
}



void Jeu::boucleEvennement(){

//retirer tiret :
    Entite e;
    e.setsymbole(' ');
    if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole() == '-'){ //si tiret à droite
        terrain->setTab2DTerrain(e, joueur.getPosX()+1, joueur.getPosY());
    }
    if(terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole() == '-'){ //si tiret à gauche
        terrain->setTab2DTerrain(e, joueur.getPosX()-1, joueur.getPosY());
    }

//        deplacementJoueur();

    deplacementDroit();
    deplacementGauche();
    deplacementSaut();
    gestionVie();
    gagne();
    collecteGain();
    gravite();


    attaque();


    deplacementEnnemiAuto();


//ennemi.deplacementAuto();



}



void Jeu::Timer (unsigned int t){
Clock clock; //le chrono qui compte à partir du moment où il est crée ...
    Time temp = clock.getElapsedTime(); //le "temps"
     float t_depart = temp.asSeconds(); // temps de départ

     while (temp.asSeconds()-t_depart < t){//tant que le temps écoulé est inférieur à t sec
        temp = clock.getElapsedTime();//màj temps passer

       // afficheTerrain();// pour qu'il n'y a pas d'écran fixe

     }}


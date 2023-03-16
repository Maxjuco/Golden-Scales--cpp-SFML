#include "Joueur.h"


const unsigned int REPETITIONS = 1000;
const unsigned int LIMITE_VAR = 10000;
static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

Joueur::Joueur() {
    pv = 10;
    pvMax = 10;
    attaque = 0;
    joueur.setsymbole('A');
    //joueur.setsymbole('#');
    posX = 0;
    posY = 0;
    hauteur_saut = 0;
    orient = 'D';
    etape_roulade = 0;
}

Joueur::~Joueur() {

}

Joueur::Joueur(unsigned int PosX, unsigned int PosY){
    pv = 0;
    pvMax = 0;
    attaque = 0;
    joueur.setsymbole('A');
    //joueur.setsymbole('0');
    posX = posX;
    //joueur.setsymbole('P');
    posX = PosX;
    posY = PosY;
    hauteur_saut =0;
}

Entite Joueur::getJoueur() const{
    return joueur;
}

void Joueur::setJoueur(const Entite &joueur_x){
    joueur.settype(joueur_x.gettype());
    joueur.setsymbole(joueur_x.getsymbole());
}

unsigned int Joueur::getPv() const {
    return pv;
}

void Joueur::setPv(unsigned int Pv) {
    pv = Pv;
}

unsigned int Joueur::getPvMax() const {
    return pvMax;
}

void Joueur::setPvMax(unsigned int PvMax) {
    pvMax = PvMax;
}

unsigned int Joueur::getPosX()const{
    return posX;
}

void Joueur::setPosX(unsigned int PosX){
    posX = PosX;
}

unsigned int Joueur::getPosY()const{
    return posY;
}

void Joueur::setPosY(unsigned int PosY){
    posY = PosY;
}

unsigned int Joueur::getAttaque() const {
    return attaque;
}

void Joueur::setAttaque(unsigned int Attaque) {
    attaque = Attaque;
}

unsigned int Joueur::getHauteur_saut() const {
    return hauteur_saut;
}

void Joueur::setHauteur_saut(unsigned int hauteur_saut_x) {
    hauteur_saut = hauteur_saut_x;
}

unsigned int Joueur::getEtape_roulade() const{
    return etape_roulade;
}

void Joueur::setEtape_roulade(unsigned int etape_roulade_x){
    etape_roulade = etape_roulade_x;
}

char Joueur::getOrient() const{
    return orient;
}

void Joueur::setOrient(char orient_x){
    orient = orient_x;
}

bool Joueur::attaque_execute(){
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}


//fonction pour d�placement + orientation dans jeu:
void Joueur::deplaceGauche(){
    posX = posX-1;
    orient = 'G';
    if(etape_roulade < 7 ){
        etape_roulade ++;
    }else{
        etape_roulade = 1;
    }
}

void Joueur::deplaceDroit(){
    posX = posX +1;
    orient = 'D';
    if(etape_roulade > 1 ){
        etape_roulade --;
    }else{
        etape_roulade = 7;
    }
}

void Joueur::deplaceSaut(){
    posY = posY -1; // fait mont� d'une case
    hauteur_saut ++;
}

void Joueur::deplaceTombe(){
    posY = posY + 1; // fait baiss� d'une case
    if (hauteur_saut > 0){ // eviter les nombres negatifs
        hauteur_saut --;
    }
}

void Joueur::Stop_roulade(sf::Event event){

    if( event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::D){
                etape_roulade = 0;
            }
    }
}


void Joueur::testRegressionJoueur() {
    cout << endl << "Exécution des tests de régression de la classe Joueur : " << endl << endl;
    for (unsigned int i = 0; i < REPETITIONS; i++) {
        cout << "Test n° " << i+1 << " de régression de la classe Joueur : " << endl;

        cout << "Test des constructeurs et des accesseurs et mutateurs...";
        if (rand() % 2) {
            Joueur joueurTest1;

            assert(joueurTest1.getJoueur().gettype() == '0');
            assert(joueurTest1.getJoueur().getsymbole() == 'A');
            assert(joueurTest1.getPvMax() == 10);
            assert(joueurTest1.getPv() == 10);
            assert(joueurTest1.getAttaque() == 0);
            assert(joueurTest1.getPosX() == 0);
            assert(joueurTest1.getPosY() == 0);
            assert(joueurTest1.getHauteur_saut() == 0);
            assert(joueurTest1.getOrient() == 'D');
            assert(joueurTest1.getEtape_roulade() == 0);



        }
        else {
            Entite entiteTest1;
            if (rand() % 2) {
                char type = '0' + rand() % 256 + 1;
                char symbole = '0' + rand() % 256 + 1;

                entiteTest1.settype(type);
                entiteTest1.setsymbole(symbole);
            }


            unsigned int PVmax = rand() % LIMITE_VAR + 1;
            unsigned int PV = rand() % LIMITE_VAR + 1;
            unsigned int Attaque = rand() % LIMITE_VAR + 1;
            unsigned int posX = rand() % LIMITE_VAR + 1;
            unsigned int posY = rand() % LIMITE_VAR + 1;
            unsigned int hauteur_saut = rand() % LIMITE_VAR + 1;
            unsigned int etape_roulade = rand() % LIMITE_VAR + 1;




            Joueur joueurTest1;
            joueurTest1.setJoueur(entiteTest1);
            joueurTest1.setPvMax(PVmax);
            joueurTest1.setPv(PV);
            joueurTest1.setAttaque(Attaque);
            joueurTest1.setPosX(posX);
            joueurTest1.setPosY(posY);
            joueurTest1.setHauteur_saut(hauteur_saut);
            joueurTest1.setEtape_roulade(etape_roulade);


            assert(joueurTest1.getJoueur().gettype() == entiteTest1.gettype());
            assert(joueurTest1.getJoueur().getsymbole() == entiteTest1.getsymbole());
            assert(joueurTest1.getPvMax() == PVmax);
            assert(joueurTest1.getPv() == PV);
            assert(joueurTest1.getAttaque() == Attaque);
            assert(joueurTest1.getPosX() == posX);
            assert(joueurTest1.getHauteur_saut() == hauteur_saut);
            assert(joueurTest1.getEtape_roulade() == etape_roulade);
        }
        cout << endl;
    }

        cout << "ok" << endl;




    cout << endl << "Tests de régression de la classe Joueur : ok !" << endl << endl;
}

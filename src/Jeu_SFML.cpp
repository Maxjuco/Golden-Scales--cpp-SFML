#include "Jeu_SFML.h"

using namespace std;
using namespace sf;

Jeu_SFML::Jeu_SFML(){
    nbEnnemisVaincus = 0;
    cumulGains = 0;
    score = 0;
    texture_terre.loadFromFile("data/Sprite/Terre.png");
    texture_herbe.loadFromFile("data/Sprite/Herbe.png");
    texture_piege.loadFromFile("data/Sprite/Piege.png");
    texture_gain.loadFromFile("data/Sprite/Gain.png");
    texture_mur.loadFromFile("data/Sprite/Mur.png");
    texture_mur_top.loadFromFile("data/Sprite/mur_top.png");
	texture_personnageD.loadFromFile("data/Sprite/PauseD.png");
	texture_personnageG.loadFromFile("data/Sprite/PauseG.png");
	texture_roulade.loadFromFile("data/Sprite/Roue_1.png");
	texture_ennemi.loadFromFile("data/Sprite/ennemi_J.png");

    texture_fond.loadFromFile("data/Sprite/Fond_Ciel.png");
    texture_fond2.loadFromFile("data/Sprite/Fond_Arbre_1.png");
    texture_fond3.loadFromFile("data/Sprite/Fond_Arbre_2.png");

    texture_tuto.loadFromFile("data/Sprite/ennemi_J.png");

    police_score.loadFromFile("data/Fipps-Regular.otf");


}

Jeu_SFML::~Jeu_SFML(){
    delete terrain;
}


bool Jeu_SFML::estAttaque(){
    if (terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()=='$'
        || terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()=='$'){
        return true;
    }else return false;
}

void Jeu_SFML::gestionVie(){
     //cas joueur perd de la vie
    if(terrain->getTab2DTerrain(joueur.getPosX(), joueur.getPosY()+1).getsymbole() == 'x'){
        joueur.setPv(joueur.getPv()-1);
    }

    if(joueur.getPosY()==13){
        joueur.setPv(0);
    }

    if(estAttaque()){
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

            //ennemi mort ? => disparait
            if(terrain->getListeEnnemi(i).getPV() == 0){
                terrain->setTab2DTerrain(e,terrain->getListeEnnemi(i).getPosX(), terrain->getListeEnnemi(i).getPosY());//disparait du terrain
                terrain->getListeEnnemi(i).setMort(true); //disparait...
                gain.setCumulGain(cumulGains++);
            }
        }
    }
}

bool Jeu_SFML::perdu(){
    if (joueur.getPv() == 0){
        return true;
    } else return false;
}

bool Jeu_SFML::gagne(){
    if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole() == '|'){
        return true;
    } else return false;
}

void Jeu_SFML::calculScore(){
    score = nbEnnemisVaincus*100 + cumulGains*50;
}

Jeu_SFML::Jeu_SFML(const Terrain & terrain_init){
    *terrain = terrain_init;
}

bool Jeu_SFML::collecteGain(){
    if(joueur.getPosX()==gain.getPosX() && joueur.getPosY()==gain.getPosY()){
        gain.setCumulGain(cumulGains++);
        return true;
    }else return false;
}

bool Jeu_SFML::attaque(){
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

unsigned int Jeu_SFML::getScore(){
    return score;
}

void Jeu_SFML::setScore (unsigned int Score){
    score = Score;
}

bool Jeu_SFML::collisionEnnemi(){
if ((joueur.getPosX()==ennemi.getPosX()-1 || joueur.getPosX()==ennemi.getPosX()+1 || joueur.getPosX()==ennemi.getPosX())&&
    (joueur.getPosY()==ennemi.getPosY()-1 || joueur.getPosY()==ennemi.getPosY()+1 || joueur.getPosY()==ennemi.getPosY())){
        return true;
    }else return false;
}

void Jeu_SFML::setTerrain(Terrain & terrain_x){
    terrain = &terrain_x;
}

void Jeu_SFML::setCam (Terrain terrain_x){
    cam.setCamera(terrain_x, 30, 14);
}

void Jeu_SFML::afficheTerrain(RenderWindow &window, View &vue){
    window.clear();
    //system(CLEAN_SCREEN);
    calculScore();

    //cout<<"Votre score est de : "<<getScore()<<" points"<<endl;
    //cout<<"Vous avez "<<joueur.getPv()<<" points de vie."<<endl;

    //cout<<"Ennemi a :"<<ennemi.getPV()<<" points de vie."<<endl;
    //cout <<"étape roulade : " <<joueur.getEtape_roulade()<<endl;

	Sprite herbe;
	herbe.setTexture(texture_herbe);
	herbe.setScale(0.125,0.125);

	Sprite terre;
	terre.setTexture(texture_terre);
	terre.setScale(0.125,0.125);

	Sprite fond;
	fond.setTexture(texture_fond);
	fond.setScale(0.125,0.125);


	Sprite fond2;
	fond2.setTexture(texture_fond2);
	fond2.setScale(0.125,0.125);


	Sprite fond3;
	fond3.setTexture(texture_fond3);
	fond3.setScale(0.125,0.125);

	Sprite tuto;
	tuto.setTexture(texture_tuto);
	tuto.setScale(0.125,0.125);

    fond.setPosition(-29*32, 0);
    window.draw(fond);
    fond2.setPosition(-29*32, 0);
    window.draw(fond2);
    fond3.setPosition(-29*32, 0);
    window.draw(fond3);

    for(unsigned int k=0; k<terrain->getTaille_x(); k++){
        //pour dessiner le terrain en entier :
            if (k % 29 == 0){
                fond.setPosition(k*32, 0);
                window.draw(fond);
                fond2.setPosition(k*32, 0);
                window.draw(fond2);
                fond3.setPosition(k*32, 0);
                window.draw(fond3);
            }

    }
                fond.setPosition(terrain->getTaille_x() + 29*32, 0);
                window.draw(fond);
                fond2.setPosition(terrain->getTaille_x() + 29*32, 0);
                window.draw(fond2);
                fond3.setPosition(terrain->getTaille_x() + 29*32, 0);
                window.draw(fond3);

	Sprite piege;
	piege.setTexture(texture_piege);
	piege.setScale(0.125,0.125);

	Sprite gain;
	gain.setTexture(texture_gain);
	gain.setScale(0.125,0.125);

	Sprite mur;
	mur.setTexture(texture_mur);
	mur.setScale(0.125,0.125);

	Sprite mur_top;
	mur_top.setTexture(texture_mur_top);
	mur_top.setScale(0.125,0.125);

	sf::Sprite personnage;
    //orient le personnage
	if(joueur.getOrient() == 'D'){
        personnage.setTexture(texture_personnageD);

	}else if(joueur.getOrient() == 'G'){
        personnage.setTexture(texture_personnageG);

	}
	switch(joueur.getEtape_roulade())
	{
    case 0:
        break;
    case 1:
        texture_roulade.loadFromFile("data/Sprite/Roue_1.png");
        personnage.setTexture(texture_roulade);
        break;
    case 2:
        texture_roulade.loadFromFile("data/Sprite/Roue_2.png");
        personnage.setTexture(texture_roulade);
        break;
    case 3:
        texture_roulade.loadFromFile("data/Sprite/Roue_3.png");
        personnage.setTexture(texture_roulade);
        break;
    case 4:
        texture_roulade.loadFromFile("data/Sprite/Roue_4.png");
        personnage.setTexture(texture_roulade);
        break;
    case 5:
        texture_roulade.loadFromFile("data/Sprite/Roue_5.png");
        personnage.setTexture(texture_roulade);
        break;
    case 6:
        texture_roulade.loadFromFile("data/Sprite/Roue_6.png");
        personnage.setTexture(texture_roulade);
        break;
    case 7:
        texture_roulade.loadFromFile("data/Sprite/Roue_7.png");
        personnage.setTexture(texture_roulade);
        break;


	}
	personnage.setScale(0.125,0.125);

    Sprite sp_ennemi;
	sp_ennemi.setTexture(texture_ennemi);
	sp_ennemi.setScale(0.125,0.125);



    //cam.mouvementCamera(*terrain, joueur);

    Vector2f centre(joueur.getPosX()*32,208);
    vue.setCenter(centre);

    //nettoie les attaques sur le terrain :
    Entite e;
    e.setsymbole(' ');
    for(unsigned int l=0; l<14; l++){
        for(unsigned int k=cam.getDepart_x(); k<cam.getArrive_x(); k++){
                if(terrain->getTab2DTerrain(k,l).getsymbole() == '-')
                    terrain->setTab2DTerrain(e, k, l);
        }
    }

    //unsigned int l;
    //unsigned int k;
    for(unsigned int l=0; l<14; l++){
        for(unsigned int k=0; k<terrain->getTaille_x(); k++){ //parcour du tableau contenant une copie du terrain4
        //for(unsigned int k=0; k < cam.getDimX(); k++) {

            if(terrain== NULL){cout<<"Il n'y a pas de terrain...";}
            if(terrain->getTab2DTerrain(k,l).getsymbole() == '#' && terrain->getTab2DTerrain(k,l-1).getsymbole()!='#'){
            //if(cam.getChamp(k, l).getsymbole() == '#' && cam.getChamp(k,l-1).getsymbole()!='#'){
                herbe.setPosition(k*32,l*32);
                window.draw(herbe);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == '#' && terrain->getTab2DTerrain(k,l-1).getsymbole()=='#'){
            //else if(cam.getChamp(k,l).getsymbole() == '#' && cam.getChamp(k,l-1).getsymbole()=='#'){
                terre.setPosition(k*32,l*32);
                window.draw(terre);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'I' && terrain->getTab2DTerrain(k,l-1).getsymbole() == 'I'){
            //else if(cam.getChamp(k,l).getsymbole() == 'I' && cam.getChamp(k,l-1).getsymbole() == 'I'){
                mur.setPosition(k*32,l*32);
                window.draw(mur);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'I' && terrain->getTab2DTerrain(k,l-1).getsymbole() != 'I'){
            //else if(cam.getChamp(k,l).getsymbole() == 'I' && cam.getChamp(k,l-1).getsymbole() != 'I'){
                mur_top.setPosition(k*32,l*32);
                window.draw(mur_top);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'o'){
            //else if(cam.getChamp(k,l).getsymbole() == 'o'){
                gain.setPosition(k*32,l*32);
                window.draw(gain);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'x'){
            //else if(cam.getChamp(k,l).getsymbole() == 'x'){
                piege.setPosition(k*32,l*32);
                window.draw(piege);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == 'A'){
            //else if(cam.getChamp(k,l).getsymbole() == 'A'){
            	personnage.setPosition(k*32,l*32);
				window.draw(personnage);
            }
            else if(terrain->getTab2DTerrain(k,l).getsymbole() == '$'){
                sp_ennemi.setPosition(k*32,l*32-25);
				window.draw(sp_ennemi);

            }
            //cout<<terrain->getTab2DTerrain(k,l).getsymbole();
            //else cout<<"\033[00m";//terrain->getTab2DTerrain(k,l).getsymbole(); //tentative de mise en couleur mais rend le jeu trop lent
        }//cout<<endl;
    }
    //affichage score :

    char numScore[10] = "";
    sprintf(numScore, "%d", getScore());
    string ScoreStr = (string) numScore;
    String texte = "SCORE : " + ScoreStr;
    //cout<<numScore<<endl;
    Text affich_score(texte, police_score, 25);
    int pos_score = joueur.getPosX()*32 -450;
    affich_score.setPosition(pos_score, 30);
    affich_score.setFillColor(Color(0,0,0));
    //cout<<affich_score.getPosition().x<<" ; "<<affich_score.getPosition().y<<affich_score.getString().toAnsiString()<<endl;
    window.draw(affich_score);

    //affiche PV :
    char numPV[10] = "";
    sprintf(numPV, "%d", joueur.getPv());
    string PVStr = (string) numPV;
    String PV = "PV : " + PVStr;
    //cout<<numPV<<endl;
    Text affich_PV(PV, police_score, 25);
    int pos_PV = joueur.getPosX()*32 +250;
    affich_PV.setPosition(pos_PV, 30);
    affich_PV.setFillColor(Color(0,0,0));
    //cout<<affich_score.getPosition().x<<" ; "<<affich_score.getPosition().y<<affich_score.getString().toAnsiString()<<endl;
    window.draw(affich_PV);


    window.setView(vue);
    window.display();
}

void Jeu_SFML::afficheMenu(RenderWindow &window, Event &event, bool &debutOUcredit, bool &fin, unsigned int e){

    window.clear();
    Sprite fond;
	fond.setTexture(texture_fond);
	fond.setScale(0.125,0.125);
    fond.setPosition(0, 0);

	Sprite fond2;
	fond2.setTexture(texture_fond2);
	fond2.setScale(0.125,0.125);
    fond2.setPosition(0, 0);

	Sprite fond3;
	fond3.setTexture(texture_fond3);
	fond3.setScale(0.125,0.125);
	fond3.setPosition(0, 0);

	//texte
	Text affich_Titre("GOLDEN SCALES", police_score, 40);
	affich_Titre.setPosition(965/2 -250, 50);
	affich_Titre.setFillColor(Color(235,198,13));
	Text affich_Start("< START ! >", police_score, 25);
	affich_Start.setPosition(965/2 -100, 416/2);
    affich_Start.setFillColor(Color(0,0,0));
    Text affich_Credit("< CREDIT... >", police_score, 25);
	affich_Credit.setPosition(965/2 -100, 415/2 + 100);
	affich_Credit.setFillColor(Color(0,0,0));

	Text affich_developpeurs(" MERCI D'AVOIR JOUE ! \n    DEVELOPPEURS : \n     Jules QUINTON \n     Tanguy DESRUES \n     Maxime COSIALLS", police_score, 25);
	affich_developpeurs.setPosition(965/2 -200, 80);
	affich_developpeurs.setFillColor(Color(0, 0, 0));
	Text affich_sortie("< Sortir... >", police_score, 25);
	affich_sortie.setPosition(965/2 -100, 380);
	affich_sortie.setFillColor(Color(0,0,0));
    Text affich_issue("", police_score, 25);
    affich_issue.setPosition(965/2 -200, 20);




	//zone du texte :
	FloatRect boite_start = affich_Start.getLocalBounds();
	boite_start.left = 965/2 -100;
	boite_start.top = 416/2;
	FloatRect boit_credit = affich_Credit.getLocalBounds();
	boit_credit.top = 416/2 + 100;
	boit_credit.left = 965/2 -100;

	FloatRect boite_sortie = affich_sortie.getLocalBounds();
	boite_sortie.left = 965/2 -100;
	boite_sortie.top = 380;




    switch(e){

        case 1: //MENU DE DEMARAGE :
           // cout<<boite_start.left<<";"<<boite_start.top<<" |||| "<<boit_credit.left<<";"<<boit_credit.top<<endl;
           // cout<<boite_start.width<<";"<<boite_start.height<<" |||| "<<boit_credit.width<<";"<<boit_credit.height<<endl;
            //cout<<event.mouseButton.x<<";"<<event.mouseButton.y<<endl;


            window.draw(fond);
            window.draw(fond2);
            window.draw(fond3);
            window.draw(affich_Titre);
            window.draw(affich_Start);
            window.draw(affich_Credit);

            //vérification du clic sur le crédit ou start :
            if (Mouse::isButtonPressed(Mouse::Left)){
                if (boite_start.contains(event.mouseButton.x, event.mouseButton.y))
                        debutOUcredit = true;

                if(boit_credit.contains(event.mouseButton.x, event.mouseButton.y)){
                    debutOUcredit = true;
                    fin = true;
                    //window.close();
                }
            }
            break;

        case 2:
            window.draw(fond);
            window.draw(fond2);
            window.draw(fond3);
            window.draw(affich_developpeurs);
            window.draw(affich_sortie);
            if(perdu()){
                affich_issue.setString("Perdu...");
                affich_issue.setFillColor(Color(0,0,0));
            }
            if(gagne()){
                char numScore[10] = "";
                sprintf(numScore, "%d", getScore());
                string ScoreStr = (string) numScore;
                string texte = "GAGNE !         SCORE : " + ScoreStr;
                affich_issue.setString(texte);
                affich_issue.setFillColor(Color(235,198,13));
            }
            window.draw(affich_issue);
            if (Mouse::isButtonPressed(Mouse::Left)){
                if(boite_sortie.contains(event.mouseButton.x, event.mouseButton.y)){
                    debutOUcredit = true;
                    window.close();
                }
            }
            break;

    }

    window.display();
}

void Jeu_SFML::setjoueur(Joueur Joueur){
    joueur = Joueur;
}

/*Joueur Jeu_SFML::getJoueur () const{
    return joueur;
}*/

void Jeu_SFML::setennemi(Ennemi ennemi_x){
    ennemi = ennemi_x;
}




void Jeu_SFML::deplacementDroit(){
    Entite e;
    e.setsymbole(' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()==' ' || (terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole()=='o')))//detection de touche
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

void Jeu_SFML::deplacementGauche(){
    Entite e;
    e.setsymbole(' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && (terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()==' ' || (terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole()=='o')))
        {
             //cas c'est un gain :
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

void Jeu_SFML::deplacementSaut(RenderWindow &window, View &vue, Event &event){
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
            joueur.Stop_roulade(event);
            deplacementEnnemiAuto(ennemi); // l'énnemi continue de se déplacer
            afficheTerrain(window, vue);//affiche changement
        }

    }
}

void Jeu_SFML::gravite(sf::RenderWindow &window, View &vue){
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
        deplacementEnnemiAuto(ennemi); // l'énnemi continue de se déplacer
        afficheTerrain(window, vue);//affiche changement
    }
    joueur.setHauteur_saut(0);//on remet la hauteur à 0
}




//d�placemet auto ennemi :
void Jeu_SFML::deplacementEnnemiAuto(Ennemi &ennemi_x){

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



void Jeu_SFML::boucleEvennement(sf::RenderWindow& window, View &vue, Event &event){

//retirer tiret :
    Entite e;
    e.setsymbole(' ');
    if(terrain->getTab2DTerrain(joueur.getPosX()+1, joueur.getPosY()).getsymbole() == '-'){ //si tiret à droite
        terrain->setTab2DTerrain(e, joueur.getPosX()+1, joueur.getPosY());
    }
    if(terrain->getTab2DTerrain(joueur.getPosX()-1, joueur.getPosY()).getsymbole() == '-'){ //si tiret à gauche
        terrain->setTab2DTerrain(e, joueur.getPosX()-1, joueur.getPosY());
    }

	//deplacementJoueur();

    deplacementDroit();
    deplacementGauche();
    deplacementSaut(window, vue, event);
    gestionVie();
    gagne();
    perdu();
    collecteGain();
    gravite(window, vue);


    attaque();
    joueur.Stop_roulade(event);

    if(!ennemi.getMort()){
        deplacementEnnemiAuto(ennemi);
    }

//ennemi.deplacementAuto();



}


void Jeu_SFML::Timer (sf::RenderWindow &window, View &vue, unsigned int t){
Clock clock; //le chrono qui compte à partir du moment où il est crée ...
    Time temp = clock.getElapsedTime(); //le "temps"
     float t_depart = temp.asSeconds(); // temps de départ

     while (temp.asSeconds()-t_depart < t){//tant que le temps écoulé est inférieur à t sec
        temp = clock.getElapsedTime();//màj temps passer

        afficheTerrain(window, vue);// pour qu'il n'y a pas d'écran fixe

     }}


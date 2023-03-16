#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Jeu_SFML.h"
#include "Terrain.h"
#include "Jeu.h"

#ifdef WIN32
#define CLEAN_SCREEN "CLS"
#else
#define CLEAN_SCREEN "clear"
#endif


using namespace std;
using namespace sf;

int main(){



    Terrain terrain; //constructeur terrain
    Jeu_SFML jeu; //constructeur jeu
    Joueur joueur; //constructeur joueur
    joueur.setPosX(3); //position de spawn du joueur
    joueur.setPosY(4);
    Ennemi ennemi_1; //constructeur ennemi
    ennemi_1.setPosX(25); //position du premier ennemi
    ennemi_1.setPosY(10);

    terrain.setTaille_x(199); //initialisation de la longueur du niveau/terrain
    terrain.setNomFich("data/lvl1.txt"); // fichier contenant le terrain
	terrain.lireFichTerrain();

    jeu.setTerrain(terrain); //initialisation du terrain cr�� dans jeu
    jeu.setCam(terrain); // initialisation de la cam�ra cr�� dans jeu
    jeu.setjoueur(joueur); //initialisation du joueur cr�� dans jeu
    jeu.setennemi(ennemi_1); //initialisation d'un ennemi cr�� dans jeu



    bool fin = false; //bool�en permettant de sortir de la boucle de jeu

    Entite e;

        // cr�ation de la fen�tre
    RenderWindow window(sf::VideoMode(960, 416), "Golden Scale");
	window.setFramerateLimit(10);

//TEST VUE DE SFML :
    Vector2f centre(480,208);

    Vector2f demiTaille(960, 416);

    View vue(centre, demiTaille);

   // window.setView(vue);

    sf::Event event;
    bool debut = false;
    bool credit = false;
    // on fait tourner le programme tant que la fen�tre n'a pas �t� ferm�e
    while (window.isOpen())
    {
        //affichage menu d�marage :

        while(debut != true){
            system(CLEAN_SCREEN);
                cout<<"menu 1"<<endl;
            jeu.afficheMenu(window, event, debut, fin, 1);
            while (window.pollEvent(event))
            {
                jeu.afficheMenu(window, event, debut, fin, 1);
                if (event.key.code == sf::Keyboard::Return){
                    debut = true;
                }
                // fermeture de la fen�tre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed){
                    debut = true;
                    fin =true;
                    credit = true;
                    window.close();
                }

            }

        }
        Music music;
        if (!music.openFromFile("data/Sound/Vexento.ogg"))
            return -1; // erreur
        music.play();

        while(fin != true){//tant que le niv n'est pas fini
            // on traite tous les �v�nements de la fen�tre qui ont �t� g�n�r�s depuis la derni�re it�ration de la boucle
            system(CLEAN_SCREEN);
            //cout<<"ui";
            while (window.pollEvent(event))
            {
                // fermeture de la fen�tre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed){
                    fin = true;
                    credit = true;
                    window.close();
                }

            }

            // effacement de la fen�tre en noir
            jeu.afficheTerrain(window, vue);
            jeu.boucleEvennement(window, vue, event);

            if(jeu.perdu()){
                    fin = true;
                    //window.close();
                }
            if(jeu.gagne()){
                fin = true;
                //window.close();
            }
        }

        //affichage menu des cr�dits :
        while(credit != true){
            vue.setCenter(960/2, 415/2);
            window.setView(vue);
            system(CLEAN_SCREEN);
            cout<<"menu 2"<<endl;
            jeu.afficheMenu(window, event, credit, fin, 2);
            while (window.pollEvent(event))
            {
                jeu.afficheMenu(window, event, credit, fin, 2);
                if (event.key.code == sf::Keyboard::Return){
                    credit = true;
                }
                // fermeture de la fen�tre lorsque l'utilisateur le souhaite
                if (event.type == sf::Event::Closed){
                    credit = true;
                    fin =true;
                    window.close();
                }

            }

        }

    }
    system(CLEAN_SCREEN);
    cout<<"FIN !"<<endl;
    return 0;
}

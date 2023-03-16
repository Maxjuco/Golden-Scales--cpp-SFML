#ifndef _JEU_SFML_H
#define _JEU_SFML_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "string"
#include "Terrain.h"
#include "Joueur.h"
#include "Gain.h"
#include "Ennemi.h"
#include "Camera.h"

using namespace std;
using namespace sf;

class Jeu_SFML {
private :
	Texture texture_terre;

	Texture texture_herbe;

	Texture texture_piege;

	Texture texture_gain;

	Texture texture_mur;
	Texture texture_mur_top;
	sf::Texture texture_personnageD;
	Texture texture_personnageG;
	Texture texture_roulade;
	Texture texture_ennemi;

	Texture texture_fond;
	Texture texture_fond2;
	Texture texture_fond3;

	Texture texture_tuto;

	Font police_score;


    Terrain *terrain;
    Camera cam;
    Joueur joueur;
    Gain gain;

    Ennemi ennemi;

    unsigned int nbEnnemisVaincus, cumulGains, score;

    bool verifCollision();

    bool collecteGain();

    bool collisionEnnemi();

    void Timer(sf::RenderWindow&, View &vue, unsigned int t); // chrono de t

public :

    /**
     * @brief Constructeur vide
     */
    Jeu_SFML();

    /**
     * @brief Constructeur à paramètres
     * @param [in,out] terrain_init Terrain à utiliser dans le Jeu
     */
    Jeu_SFML(const Terrain & terrain_init); //constructeur du jeu en initialisant le terrain � partir de la classe et met � 0 les 2 entiers

    /**
     * @brief Destructeur
     */
    ~Jeu_SFML(); // destructeur

    /**
     * @brief Fonction affichant l'attaque du Joueur si elle est exécutée
     * @return Booléen indiquant si une attaque a été exécutée ou non
     */
    bool attaque();

    /**
     * @brief Fonction retournant un booléen si le Joueur est attaqué (si un Ennemi se trouve devant ou derrière lui)
     * @return Booléen indiquant si le Joueur est attaqué
     */
    bool estAttaque();

    /**
     * @brief Procédure gérant la vie du Joueur et des Ennemi
     * Procédure retirant de la vie au Joueur en fonction de plusieurs critères (attaqué, marche sur des pièges, tombe dans un trou), et retirant de la vie aux Ennemi s'ils sont attaqués. Fait disparaître un Ennemi s'il n'a plus de vie.
     */
    void gestionVie();

    /**
     * @brief Fonction retournant vrai si le Joueur n'a plus de vie
     * @return Booléen indiquant si le Joueur n'a plus de vie
     */
    bool perdu();

    /**
     * @brief Fonction retournant vrai si le Joueur arrive à la fin du niveau
     * @return Booléen indiquant si le Joueur est arrivé à la fin du niveau
     */
    bool gagne();

    /**
     * @brief Accesseur de la donnée membre score
     * @return score
     */
    unsigned int getScore();
    /**
     * @brief Mutateur de la donnée membre score
     * @param [in] Score
     */
    void setScore (unsigned int Score);

    /**
     * @brief Procédure faisant évoluer le score en fonction des actions effectuées par le Joueur
     */
    void calculScore();
    /**
     * @brief Accesseur de la donnée membre nbEnnemisVaincus
     * @return nbEnnemisVaincus
     */
    unsigned int getnbEnnemisVaincus () const;
    /**
     * @brief Mutateur de la donnée membre nbEnnemisVaincus
     * @param [in] nb_ennemis_vaincus
     */
    void setnbEnnemisVaincus (unsigned int nb_ennemis_vaincus);

    /**
     * @brief Accesseur de la donnée membre cumulGains
     * @return cumulGains
     */
    unsigned int getcumulGains () const;
    /**
     * @brief Mutateur de la donnée membre cumulGains
     * @param [in] cumul_Gains
     */
    void setcumulGains (unsigned int cumul_Gains);

    /**
     * @brief Accesseur de la donnée membre terrain
     * @return terrain
     */
    Terrain & getterrain () const;
    /**
     * @brief Mutateur de la donnée membre terrain
     * @param [in,out] terrain_x
     */
    void setTerrain (Terrain & terrain_x);

    /**
     * @brief Mutateur de la donnée membre joueur
     * @param [in] Joueur
     */
    void setjoueur(Joueur Joueur);

    /**
     * @brief Mutateur de la donnée membre ennemi
     * @param [in] ennemi_x
     */
    void setennemi(Ennemi ennemi_x);

    /**
     * @brief Mutateur de la donnée membre cam
     * @param [in] terrain_x
     */
    void setCam (Terrain terrain_x);
    /**
     * @brief Boucle événement qui gère les déplacements, la vie de toutes les Entite et la fin du jeu.
     * @param [in,out] window
     * @param [in,out] vue
     * @param [in,out] event
     */
    void boucleEvennement(sf::RenderWindow& window, View &vue, Event &event);

    /**
     * @brief Procédure qui affiche le Terrain
     * @param [in,out] window
     * @param [in,out] vue
     */
    void afficheTerrain(RenderWindow &window, View &vue);

    /**
     * @brief Procédure affichant le menu du jeu
     * @param [in,out] window
     * @param [in,out] event
     * @param [in,out] debut
     * @param [in,out] fin
     * @param [in] e 
     */
    void afficheMenu(RenderWindow &window, Event &event, bool &debut, bool &fin, unsigned int e);


    //remplacement deplacementJoueur :

    /**
     * @brief Procédure qui déplace le joueur d'une case à droite + donne la lettre a orient de joueur
     */
    void deplacementDroit(); // déplace le joueur d'une case à droite + donne la lettre a orient de joueur

    /**
     * @brief Procédure qui déplace le joueur d'une case à gauche + donne la lettre a orient de joueur
     */
    void deplacementGauche(); // déplace le joueur d'une case à gauche + donne la lettre a orient de joueur

    /**
     * @brief Procédure qui déplace le joueur d'une case au dessus
     * @param [in,out] window
     * @param [in,out] vue
     * @param [in,out] event
     */
    void deplacementSaut(RenderWindow &window, View &vue, Event &event); // déplace le joueur d'une case au dessus

    /**
     * @brief Procédure qui affecte le Joueur par la gravité
     * @param [in,out] window
     * @param [in,out] vue
     */
    void gravite (sf::RenderWindow &window, View &vue);

    /**
     * @brief Procédure gérant le déplacement automatique d'un Ennemi
     * @param [in,out] ennemi_x L'Ennemi à déplacer automatiquement
     */
    void deplacementEnnemiAuto(Ennemi &ennemi_x);

};




#endif

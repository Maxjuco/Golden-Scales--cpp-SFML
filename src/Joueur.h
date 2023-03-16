#ifndef _JOUEUR_H_
#define _JOUEUR_H_

#include "Entite.h"
#include <SFML/Graphics.hpp>
#include <cassert>


class Joueur {
    private:
        Entite joueur;
        unsigned int pv, pvMax, attaque, posX, posY;
        unsigned int hauteur_saut;
        char orient; //direction regardé par le joueur : Droite / Gauche
        unsigned int etape_roulade; //0 = pause et 1, 2, 3, 4, 5, 6 et 7 = roue !
    public:
        /**
         * @brief Constructeur vide
         */
        Joueur();

        /**
         * @brief Constructeur à paramètres
         * @param [in] PosX Abscisse de départ du Joueur
         * @param [in] PosY Ordonnée de départ du Joueur
         */
        Joueur(unsigned int PosX, unsigned int PosY);

        /**
         * @brief Destructeur
         */
        ~Joueur();

        /**
         * @brief Accesseur de la donnée membre joueur
         * @return joueur
         */
        Entite getJoueur() const;
        /**
         * @brief Mutateur de la donnée membre joueur
         * @param[in] Joueur
         */
         void setJoueur(const Entite &joueur_x);

        /**
         * @brief Accesseur de la donnée membre pv
         * @return pv
         */
        unsigned int getPv() const;
        /**
         * @brief Mutateur de la donnée membre pv
         * @param[in] Pv
         */
        void setPv(unsigned int Pv);

        /**
         * @brief Accesseur de la donnée membre pvMax
         * @return pvMax
         */
        unsigned int getPvMax() const;
        /**
         * @brief Mutateur de la donnée membre pvMax
         * @param[in] PvMax
         */
        void setPvMax(unsigned int PvMax);

        /**
         * @brief Accesseur de la donnée membre posX
         * @return posX
         */
        unsigned int getPosX() const;
        /**
         * @brief Mutateur de la donnée membre posX
         * @param[in] PosX
         */
        void setPosX(unsigned int PosX);

        /**
         * @brief Accesseur de la donnée membre posY
         * @return posY
         */
        unsigned int getPosY() const;
        /**
         * @brief Mutateur de la donnée membre posY
         * @param[in] PosY
         */
        void setPosY(unsigned int PosY);

        /**
         * @brief Accesseur de la donnée membre attaque
         * @return attaque
         */
        unsigned int getAttaque() const;
        /**
         * @brief Mutateur de la donnée membre attaque
         * @param[in] Attaque
         */
        void setAttaque(unsigned int Attaque);

        /**
         * @brief Accesseur de la donnée membre hauteur_saut
         * @return hauteur_saut
         */
        unsigned int getHauteur_saut() const;
        /**
         * @brief Mutateur de la donnée membre hauteur_saut
         * @param[in] hauteur_saut_x
         */
        void setHauteur_saut(unsigned int hauteur_saut_x);

        /**
         * @brief Accesseur de la donnée membre etape_roulade
         * @return etape_roulade
         */
        unsigned int getEtape_roulade() const;
        /**
         * @brief Mutateur de la donnée membre etape_roulade
         * @param[in] etape_roulade_x
         */
        void setEtape_roulade(unsigned int etape_roulade_x);

        /**
         * @brief Accesseur de la donnée membre orient
         * @return orient
         */
        char getOrient () const;
        /**
         * @brief Mutateur de la donnée membre orient
         * @param[in] orient_x
         */
        void setOrient (char orient_x);

        /**
         * @brief Fonction retournant vrai si la touche d'exécution de l'attaque est enclenchée.
         * @return Booléen indiquant l'état de la touche d'attaque
         */
        bool attaque_execute();

        /**
         * @brief Procédure qui déplace le Joueur vers la gauche d'une case, l'oriente vers la gauche, et gère l'animation avec la donnée membre etape_roulade.
         */
        void deplaceGauche(); //change la posX + met dans orient le côté que regarde le joueur

        /**
         * @brief Procédure qui déplace le Joueur vers la droite d'une case, l'oriente vers la droite, et gère l'animation avec la donnée membre etape_roulade.
         */
        void deplaceDroit(); //change la posX + met dans orient le côté que regarde le joueur

        /**
         * @brief Procédure faisant sauter le Joueur (hauteur +1), et incrémente la donnée membre hauteur_saut.
         */
        void deplaceSaut(); // fait monter d'une case le joueur + incrémente la hauteur_saut

        /**
         * @brief Procédure faisant tomber le Joueur (hauteur -1), et décrémente si besoin la donnée membre hauteur_saut.
         */
        void deplaceTombe(); // fait baisser d'une case le joueur

        /**
         * @brief Procédure réinitialisant l'animation de roulade si le Joueur s'arrête.
         */
        void Stop_roulade(sf::Event event);

        void testRegressionJoueur();



        //est ce que cette fonction est vraiment utile comme on vérifie cela dans la classe Jeu ?
        //bool estAttaque();
};

#endif

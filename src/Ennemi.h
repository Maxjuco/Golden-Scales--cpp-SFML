#ifndef _ENNEMI_H
#define _ENNEMI_H


#include <iostream>
#include "Entite.h"

using namespace std;

class Ennemi {
private :
    Entite ennemi;
    unsigned int dimX, dimY;
    unsigned int PVmax, PV, Attaque, posX, posY;
    unsigned int parcourue; // case parcourue de 0 à 10
    bool mort; //false = vivant et true = mort

public :

    /**
     * @brief Constructeur vide de la classe Ennemi
     */
    Ennemi();

    /**
     * @brief Retourne la largeur de l'Ennemi (donnée membre dimX)
     * @return dimX Largeur de l'Ennemi
     */
    unsigned int getdimX () const;
    /**
     * @brief Modifie la largeur de l'Ennemi (donnée membre dimX)
     * @param [in] dim_x Largeur de l'Ennemi
     */
    void setdimX (unsigned int dim_x);
    /**
     * @brief Retourne la hauteur de l'Ennemi (donnée membre dimY)
     * @return dimY Hauteur de l'Ennemi
     */
    unsigned int getdimY () const;
    /**
     * @brief Modifie la hauteur de l'Ennemi (donnée membre dimY)
     * @param [in] dim_y Hauteur de l'Ennemi
     */
    void setdimY (unsigned int dim_y);
    /**
     * @brief Retourne la position en abscisse de l'Ennemi (donnée membre posX)
     * @return posX Position en abscisse de l'Ennemi
     */
    unsigned int getPosX() const;
    /**
     * @brief Modifie la position en abscisse de l'Ennemi (donnée membre posX)
     * @param [in] PosX Position en abscisse de l'Ennemi
     */
    void setPosX(unsigned int PosX);
    /**
     * @brief Retourne la position en ordonnée de l'Ennemi (donnée membre posY)
     * @return posY Position en ordonnée de l'Ennemi
     */
    unsigned int getPosY() const;
    /**
     * @brief Modifie la position en ordonnée de l'Ennemi (donnée membre posY)
     * @param [in] PosY Position en ordonnée de l'Ennemi
     */
    void setPosY(unsigned int PosY);

    /**
     * @brief Retourne les PV maximums de l'Ennemi (donnée membre PVmax)
     * @return PVmax Santé maximale de l'Ennemi
     */
    unsigned int getPVmax () const;
    /**
     * @brief Modifie les PV maximums de l'Ennemi (donnée membre PVmax)
     * @param [in] pv_max Santé maximale de l'Ennemi
     */
    void setPVmax (unsigned int pv_max);
    /**
     * @brief Retourne les PV actuels de l'Ennemi (donnée membre PV)
     * @return PV Santé de l'Ennemi
     */
    unsigned int getPV () const;
    /**
     * @brief Modifie les PV actuels de l'Ennemi (donnée membre PV)
     * @param [in] pv Santé de l'Ennemi
     */
    void setPV (unsigned int pv);
    /**
     * @brief Retourne la force d'attaque de l'Ennemi (donnée membre Attaque)
     * @return Attaque Force d'attaque de l'Ennemi
     */
    unsigned int getAttaque () const;
    /**
     * @brief Modifie la force d'attaque de l'Ennemi (donnée membre attaque)
     * @return attaque Force d'attaque de l'Ennemi
     */
    void setAttaque (unsigned int attaque);
    /**
     * @brief Retourne la distance parcourue par l'Ennemi (donnée membre parcourue)
     * @return parcourue Distance parcourue par l'Ennemi
     */
    unsigned int getParcourue () const;
    /**
     * @brief Modifie la distance parcourue par l'Ennemi (donnée membre parcourue)
     * @param [in] parcourue_x Distance parcourue par l'Ennemi
     */
    void setParcourue (unsigned int parcourue_x);
    /**
     * @brief Retourne l'état de l'Ennemi (donnée membre mort)
     * @return mort Etat de l'Ennemi (true = mort)
     */
    bool getMort() const;
    /**
     * @brief Modifie l'état de l'Ennemi (donnée membre mort)
     * @param [in] mort_t Etat de l'Ennemi (true = mort)
     */
    void setMort(bool mort_t);
    /**
     * @brief Retourne une copie de l'Ennemi
     * @return ennemi Copie de l'Ennemi
     */
    Entite getennemi () const;
    /**
     * @brief Modifie l'Ennemi
     * @param [in,out] ennemi_x Ennemi à copier
     */
    void setennemi (const Entite &ennemi_x); // pour modifier directement l'original

    /**
     * @brief Constructeur à paramètres de la classe Ennemi
     * @param [in,out] ennemi_x Entite
     * @param [in] dim_x Largeur
     * @param [in] dim_y Hauteur
     * @param [in] pv_max Santé maximale
     * @param [in] pv Santé actuelle
     * @param [in] attaque Force d'attaque
     * @param [in] posX Position en abscisse
     * @param [in] posY Position en ordonnée
     */
    Ennemi(const Entite &ennemi_x, unsigned int dim_x, unsigned int dim_y, unsigned int pv_max, unsigned int pv, unsigned int attaque, unsigned int posX, unsigned int posY); //constructeur


    ~Ennemi(); //destructeur

    //sert vraiment en faite !
    /**
     * @brief Procédure gérant le déplacement automatique de l'Ennemi
     * @param [in] nb_pas Nombre de pas à parcourir lors de l'exécution
     */
    void deplacementAuto(unsigned int nb_pas); // change la position et parcourue (pour savoir cb a avancer)




    //est ce que cette fonction est vraiment utile comme on vérifie cela dans la classe Jeu ?
    //bool estAttaque(); // v�rifie si est attaqu�

    void testRegressionEnnemi();


};

#endif

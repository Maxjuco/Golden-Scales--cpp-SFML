#ifndef _TERRAIN_H_
#define _TERRAIN_H_


#include <iostream>
#include <string.h>
#include "Entite.h"
#include "Ennemi.h"
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Terrain {
private:
    string NomFichierTerrain;
    vector <Entite> Tab2DTerrain;
    vector <Ennemi> ListeEnnemi;
    unsigned int taille_x;
    unsigned int nb_ennemis;

public:
	/**
	 *@brief Constructeur vide.
	*/
    Terrain();
    /**
     * @brief Destructeur
     */
    ~Terrain();

    /**
     * @brief Accesseur de la donnée membre taille_x
     * @return taille_x
     */
    unsigned int getTaille_x()const;
    /**
     * @brief Mutateur de la donnée membre taille_x
     * @param [in] taille
     */
    void setTaille_x(unsigned int taille);

    /**
     * @brief Accesseur de la donnée membre nb_ennemis
     * @return nb_ennemis
     */
    unsigned int getNb_ennemis()const;
    /**
     * @brief Mutateur de la donnée membre nb_ennemis_x
     * @param [in] nb_ennemis_x
     */
    void setNb_ennemis(unsigned int nb_ennemis_x);

    /**
     * @brief Accesseur de la donnée membre NomFichierTerrain
     * @return NomFichierTerrain
     */
    string getNomFich();
    /**
     * @brief Mutateur de la donnée membre Fichier
     * @param [in] Fichier
     */
    void setNomFich (string Fichier);

    /**
     * @brief Accesseur de la donnée membre ListeEnnemi
     * @param [in] x Position dans le tableau de l'Ennemi à retourner
     * @return Ennemi n°x dans le tableau ListeEnnemi
     */
    Ennemi & getListeEnnemi(unsigned int x) ;//renvoie l'ad de l'entit� de la case x du tab (en partan de 0...)
    /**
     * @brief Mutateur de la donnée membre ListeEnnemi
     * @param [in,out] Ennemi_x
     * @param [in] x Position dans le tableau de l'Ennemi à modifier
     */
    void setListeEnnemi(const Ennemi &Ennemi_x, unsigned int x);//modifie l'entit� de la case x avec celle pass�e en donn�e

    /**
     * @brief Accesseur de la donnée membre Tab2DTerrain
     * @param [in] x Abscisse de l'Entite à retourner
     * @param [in] y Ordonnée de l'Entite à retourner
     * @return Copie de l'Entite aux coordonnées [x,y] dans le tableau Tab2DTerrain
     */
    Entite getTab2DTerrain(unsigned int x, unsigned int y) const;//renvoie une copie de l'entit� de la case de coord (x,y) du tab2D (en partant de 0,0...)
    /**
     * @brief Mutateur de la donnée membre Tab2DTerrain
     * @param [in,out] Entite_xy
     * @param [in] x Abscisse de l'Entite à modifier
     * @param [in] y Ordonnée de l'Entite à modifier
     */
    void  setTab2DTerrain(const Entite &Entite_xy, unsigned int x, unsigned int y);//modifie l'entit� de la case x,y avec celle pass�e en donn�e

    /**
     * @brief Procédure copiant l'architecture d'un niveau dans un fichier texte, et qui remplit le Terrain avec les informations correspondantes.
     */
    void lireFichTerrain ();

    void testRegressionTerrain();

};

#endif

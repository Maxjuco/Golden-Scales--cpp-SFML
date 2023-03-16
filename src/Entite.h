#ifndef _ENTITE_H
#define _ENTITE_H

#include <iostream>

using namespace std;


class Entite {
private:
    char type, symbole;



public:
    /**
     * @brief Accesseur de la donnée membre type
     * @return type
     */
    char gettype () const;
    /**
     * @brief Mutateur de la donnée membre type
     * @param [in] type_x
     */
    void settype (char type_x);

    /**
     * @brief Accesseur de la donnée membre symbole
     * @return symbole
     */
    char getsymbole () const;
    /**
     * @brief Mutateur de la donnée membre symbole
     * @param [in] symbole_x
     */
    void setsymbole (char symbole_x);

    /**
     * @brief Constructeur vide
     */
    Entite ();//constructeur met tout � 0 ou '0'...
    /**
     * @brief Constructeur à paramètres
     * @param [in] type_x
     * @param [in] symbole_x
     */
    Entite(char type_x, char symbole_x);//constructeur avec param�tre
    /**
     * @brief Constructeur par copie
     * @param [in,out] ent_copie Entite à copier
     */
    Entite(const Entite & ent_copie);//costructeur par copie

    void testRegressionEntite();


};

#endif

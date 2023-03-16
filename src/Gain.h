#ifndef _GAIN_H_
#define _GAIN_H_

#include <iostream>
#include "Entite.h"

class Gain {
private:
    Entite gain;
    unsigned int cumulGain, posX, posY;
public:
    /**
     * @brief Constructeur vide
     */
    Gain();
    /**
     * @brief Destructeur
     */
    ~Gain();

    /**
     * @brief Accesseur de la donnée membre posX
     * @return posX
     */
    unsigned int getPosX() const;
    /**
     * @brief Mutateur de la donnée membre posX
     * @param [in] PosX
     */
    void setPosX(unsigned int PosX);

    /**
     * @brief Accesseur de la donnée membre posY
     * @return posY
     */
    unsigned int getPosY() const;
    /**
     * @brief Mutateur de la donnée membre posY
     * @param [in] PosY
     */
    void setPosY(unsigned int PosY);

    /**
     * @brief Accesseur de la donnée membre cumulGain
     * @return cumulGain
     */
    unsigned int getCumulGain() const;
    /**
     * @brief Mutateur de la donnée membre cumulGain
     * @param [in] CumulGain
     */
    void setCumulGain(unsigned int CumulGain);

    void testRegressionGain();
};

#endif

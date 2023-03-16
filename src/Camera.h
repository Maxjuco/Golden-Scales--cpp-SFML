#ifndef _CAMERA_H
#define _CAMERA_H

#include <vector>
#include "Entite.h"
#include "Terrain.h"
#include "Joueur.h"

class Camera {
    private:
        vector <Entite> champ;
        unsigned int dimX, dimY;
        int depart_x;
        unsigned int arrive_x;

    public:
        /**
         * @brief Constructeur de la classe Camera
         */
        Camera();
        /**
         * @brief Destructeur de la classe Camera
         */
        ~Camera();

        /**
         * @brief Retourne la largeur de la Camera (donnée membre dimX)
         * @return dimX Largeur de la Camera
         */
        unsigned int getDimX() const;
        /**
         * @brief Modifie la largeur de la Camera (donnée membre dimX)
         * @param [in] dim_x Largeur de la Camera
         */
        void setDimX(unsigned int dim_x);
        /**
         * @brief Retourne la hauteur de la Camera (donnée membre dimY)
         * @return dimY Hauteur de la Camera
         */
        unsigned int getDimY() const;
        /**
         * @brief Modifie la hauteur de la Camera (donnée membre dimY)
         * @param [in] dim_y Hauteur de la Camera
         */
        void setDimY(unsigned int dim_y);

        /**
         * @brief Retourne le point de départ de la Camera (donnée membre depart_x)
         * Retourne la coordonnée du début de la Camera, à gauche.
         * @return depart_x La coordonnée de la gauche de la Camera
         */
        int getDepart_x() const;
        /**
         * @brief Modifie le point de départ de la Camera (donnée membre depart_x)
         * Modifie la coordonnée du début de la Camera, à gauche.
         * @param [in] dep La coordonnée de la gauche de la Camera
         */
        void setDepart_x(int dep);
        /**
         * @brief Retourne le point d'arrivée de la Camera (donnée membre arrive_x)
         * Retourne la coordonnée de fin de la Camera, à droite.
         * @return arrive_x La coordonnée de la droite de la Camera
         */
        unsigned int getArrive_x() const;
        /**
         * @brief Modifie le point d'arrivée de la Camera (donnée membre arrive_x)
         * Modifie la coordonnée de fin de la Camera, à droite.
         * @param [in] arrive La coordonnée de la droite de la Camera
         */
        void setArrive_x(unsigned int arrive);

        /**
         * @brief Retourne une copie de l'Entite aux coordonées passées en paramètre
         * @param [in] x L'abscisse de l'Entite à retourner
         * @param [in] y L'ordonnée de l'Entite à retourner
         * @return L'Entite aux coordonnées [x,y]
         */
        Entite getChamp (unsigned int x, unsigned int y) const;
        /**
         * @brief Modifie l'Entite aux coordonées passées en paramètre
         * @param [in,out] e L'Entite qui va remplacer celle aux coordonnées [x,y]
         * @param [in] posX L'abscisse de l'Entite à retourner
         * @param [in] posY L'ordonnée de l'Entite à retourner
         */
        void setChamp(const Entite &e, unsigned int posX, unsigned int posY);

        //constructeur par copie :
        /**
         * @brief Procédure qui remplit une instance de la classe Camera avec les informations d'un Terrain passé en paramètre, pour l'afficher
         * @param [in, out] terrain_x Le Terrain à afficher
         * @param [in] dim_x La largeur du Terrain à afficher
         * @param [in] dim_y La hauteur du Terrain à afficher
         */
        void setCamera(const Terrain & terrain_x, unsigned int dim_x, unsigned int dim_y);

        /**
         * @brief Procédure qui permet à la Camera de suivre les mouvements du Joueur en fonction de ses déplacements
         * @param [in,out] terrain_x Le Terrain sur lequel le Joueur se déplace, et affiché par la Camera
         * @param [in, out] joueur Le Joueur suivi par la Camera
         */
        void mouvementCamera(const Terrain &terrain_x, const Joueur &joueur);

        void testRegressionCamera();
};

#endif

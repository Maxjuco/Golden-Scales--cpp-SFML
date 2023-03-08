# Golden-Scales

Bienvenue nouveau joueur de Golden Scales !
----------------------------------------------

------------
Développeurs
------------
Desrues Tanguy
Cosialls Maxime
Quinton Jules

Identifiant du projet sur git : 13324

---------------------
Description du jeu
---------------------
Golden Scales est un Jeu de plateforme (plateformer), disponible en version texte et graphique (librairie SFML).
Dans ce jeu, vous contrôlez un adorable pangolin qui va devoir passer au travers des griffes d'horribles braconniers...

--------
Tutoriel
--------

Q : Aller à gauche | D : Aller à droite
Espace : Sauter
Z : Attaquer

----------------
Structure du jeu
----------------
Il est composé de 5 dossiers
Le dossier src: Il contient tous les fichier .h et .cpp
Le dossier obj: Il contient tous les fichiers .o
Le dossier data: Il contient tous les fichiers multimedias, ici, les sprite et les sons
Le dossier doc: Il contient la documentation du jeu en détails
Le dossier lib: Il contient les librairie utilisées (ici SFML)

---------------
Les exécutables
---------------
La compilation génère 3 exécutables, dans le dossier bin/
mainTest : exécute les tests de régression de chaque classe
mainTemp : exécution du jeu en mode console
mainSFML : exécution du jeu en mode fenêtre, grâce aux librairies SFML


--------------
Pour compiler
--------------

Sur Linux :
Prérequis : installer les librairies SFML
Exécutez la commande 
```bash
sudo apt-get install libsfml-dev
```
Ouvrez un terminal, puis placez-vous dans le dossier où se trouve le makefile et executez la commande suivante:
```bash
make bin/L'ExecutableQueVousSouhaitezLancer
```
Pour l'exécution, lancez simplement le programme avec la commande
```bash
bin/executable
```

Sur CodeBlocks :
Si ça n'est pas déjà le cas, voici ce que vous devez avoir dans Project->Build options->Linker settings :
	lib\extern\SFML\lib\libsfml-graphics.a
	lib\extern\SFML\lib\libsfml-window.a
	lib\extern\SFML\lib\libsfml-system.a
	lib\extern\SFML\lib\libsfml-audio.a
dans Project->Build options->Search directories :
	-> compiler
		bin
		SFML\include
	-> linker
		bin
		lib\extern\SFML\include

-------
Musique
-------
Vexento - Sad robot

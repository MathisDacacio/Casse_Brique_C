# Casse-Brique en C avec SDL

## Table des matières

1. [Description](#description)
2. [Fonctionnalités](#fonctionnalités)
3. [Instructions](#instructions)
4. [Structure du Code](#structure-du-code)
5. [Compilation et Exécution](#compilation-et-exécution)
   - [Pré-requis](#pré-requis)
   - [Instructions](#instructions-1)
6. [Contact](#contact)

## Description

Le jeu "Casse-Brique" est une version classique du célèbre jeu vidéo dans lequel le joueur doit casser des briques en envoyant une balle rebondissante sur celles-ci. Ce projet a été réalisé en langage C en utilisant la bibliothèque graphique SDL pour gérer l'affichage et les interactions. Le jeu inclut une fonctionnalité supplémentaire où certaines briques nécessitent plus de coups pour être détruites, ajoutant ainsi une difficulté progressive au jeu.

## Fonctionnalités

- **Briques de différentes duretés** : Certaines briques nécessitent plusieurs coups pour être détruites, ce qui augmente la complexité du jeu.
- **Paddle contrôlable** : Le joueur contrôle un paddle (raquette) pour faire rebondir la balle et détruire les briques.
- **Affichage graphique avec SDL** : Utilisation de la bibliothèque SDL pour dessiner les briques, la balle et le paddle.
- **Niveaux progressifs** : Le jeu devient plus difficile au fur et à mesure que le joueur progresse en augmentant la vitesse de la balle et la densité des briques.

## Instructions

1. **Lancement du jeu** : Exécutez le programme en C.
2. **Contrôles** :
   - Déplacez la raquette (paddle) en utilisant les touches fléchées gauche et droite du clavier.
   - La balle rebondit sur les bords de la fenêtre et la raquette.
3. **Objectif** : Casser toutes les briques à l'écran en dirigeant la balle avec la raquette. Certaines briques nécessitent plusieurs coups pour être détruites.
4. **Fin du jeu** : Le jeu se termine lorsque toutes les briques sont détruites ou si la balle tombe en dehors de l'écran sans être rattrapée par la raquette.

## Structure du Code

- **initialiserJeu** : Initialise les éléments du jeu, y compris les briques, la raquette, et la balle.
- **afficherJeu** : Affiche les briques, la raquette et la balle sur la fenêtre SDL.
- **gererMouvementBalle** : Gère le mouvement de la balle, les rebonds et les collisions avec les briques.
- **gererMouvementRaquette** : Gère les mouvements du paddle (raquette) en fonction des entrées clavier.
- **detruireBrique** : Détecte les collisions entre la balle et les briques et gère leur destruction, avec une logique de briques plus résistantes.
- **verifierFinDePartie** : Vérifie si la partie est terminée (si toutes les briques sont détruites ou si la balle est tombée).

## Compilation et Exécution

### Pré-requis
- Un compilateur C (par exemple, GCC).
- La bibliothèque **SDL2** installée.

### Instructions

1. Clonez ou téléchargez le projet.
2. Ouvrez un terminal et placez-vous dans le répertoire du projet.
3. Assurez-vous que la bibliothèque SDL2 est installée. Si ce n'est pas le cas, vous pouvez l'installer en utilisant les commandes suivantes :
   - Sur Ubuntu/Debian : 
     ```bash
     sudo apt-get install libsdl2-dev
     ```
   - Sur macOS avec Homebrew :
     ```bash
     brew install sdl2
     ```
   - Sur Windows, suivez les instructions d'installation de SDL2 depuis le site officiel.
   
## Contact

Créé par **Mathis Dacacio**.  
[Mon LinkedIn](https://www.linkedin.com/in/mathis-dacacio-298a25293/)  
Pour toute question, merci de me contacter via le formulaire de la page ou directement sur LinkedIn.

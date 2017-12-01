- [ ] faire tout avec des constantes (#define ou const int) pour les positions et les dimentions des boutons

###### () montre une action
###### autre montre un menu/sous menu
###### les choses avec des cases à cocher ne sont pas necessairement à faire par celui qui fait le menu

# NE PAS FAIRE UNE FONCTION DIFFERENTE POUR CHAQUE MENU
Faire une fonction menu qui prend en parametre le numéro du menu ou qui a une autre façon de savoir quoi afficher et qui
RENVOIE un entier/enum du choix du joueur.

### Menu principal
- Retours/quitter
  - ()quitte le jeu
- Nouvelle partie
  - Retours au menu principal
  - Choix des deux joueurs (prévoir un très grand nombre de joueurs, donc avec plusieures pages)
    - retours à la nouvelle partie
    - choix des cartes à mettre dans le deck depuis la collection (prevoir plusieurs pages de cartes) une carte à la fois. 
cette fonction sera appellée le nombre de cartes dans un deck fois.
      - () lancemet de la partie quand les deux joueurs ont choisi
    - choix d'un deck dejà fait
      - () lancemet de la partie quand les deux joueurs ont choisi
- Charger partie
  - Retours au menu principal
- Nouveau Joueur
  - [ ] choix du joueur (mario etc) ou bien ()demande d'entrer le nom du joueur dans la console
  - [ ] choix des cartes
- Magasin
  - pouvoir acheter des cartes et les ajouter à la collection


##### N'oubliez pas de destroy_bitmap à la fin des fonctions les bitmaps pour lesuqelles vous avez create_bitmap!!

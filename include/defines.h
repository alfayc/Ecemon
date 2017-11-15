#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

#include <string>
#include <allegro.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include "Carte.h"
#include "ModeleCreature.h"
#include "ModeleEnergie.h"
#include "ModeleSpecial.h"

/* les dimensions */
#define CARDWIDTH 50
#define CARDHEIGHT 75

#define MARGIN 10
#define XENERGY MARGIN
#define YENERGY MARGIN
#define XACTIVE 70
#define YACTIVE MARGIN
#define XSPECIAL 420
#define YSPECIAL MARGIN
#define XENJEU MARGIN
#define YENJEU 85
#define XPIOCHE 215
#define YPIOCHE 85
#define XCIMETIERE 420
#define YCIMETIERE 85
#define XMAIN 70
#define YMAIN 180


#define XSCREEN 600
#define YSCREEN 800

/* le nombre max de cartes dans les differents endroits du plateau */
#define MAXHAND 5
#define MAXACTIVE 5
#define MAXSPECIAL 1

#define NBDOMAINE 4

/* des couleurs */
#define BLANC makecol(255,255,255)
#define NOIR makecol(0,0,0)
#define ROUGE makecol(255,0,0)
#define BLEU makecol(0,0,255)
#define VERT makecol(0,255,0)
#define MAG makecol (255,0,255)         //magenta

/* ces couleurs sont celles qu'on utilisait dans le projet ECEcraft. si ça plait on peut les réutiliser */
//#define COL_UI_FOND makecol(1,87,155)
//#define COL_UI_ACC makecol(79,195,247)
#define COL_SAND makecol(194,132,80)
//#define COL_BRIDGE makecol(122,61,0)
//#define COL_GRASS makecol(110,130,51)
//#define COL_WATER makecol(48,140,187)
#define COL_MOUNTAIN makecol(83,83,83)
//#define COL_ROCK makecol(128,128,128)
//#define COL_TREEL makecol(78,145,101)   //arbre feuillu
//#define COL_TREEP makecol(58,99,58)     //conifere
//#define COL_CONSTR COL_UI_ACC           //couleur d'un batiment
//#define COL_ENEMY ROUGE
//#define COL_PEASANT makecol(34,93,255)
//#define COL_SOLDIER BLEU

#endif //DEFINES_H_INCLUDED


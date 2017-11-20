#ifndef DEFINES_H_INCLUDED
#define DEFINES_H_INCLUDED

///LINKERS/INCLUDES
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

///MAGIC NUMBERS AND ENUMS
// le nombre max de cartes dans les differents endroits du plateau
#define MAXHAND 5
#define MAXACTIVE 5
#define MAXSPECIAL 1

#define NBDOMAINE 4


// enum pour les endroits sur le plateau
#define PENERGY 1
#define PACTIVE 2
#define PSPECIAL 3
#define PENJEU 4
#define PPIOCHE 5
#define PCIMETIERE 6
#define PMAIN 7


///GRAPHICS DIMENTIONS AND COORDINATES
#define XSCREEN 600
#define YSCREEN 800
#define WPLAYERSIDE XSCREEN
#define HPLAYERSIDE (YSCREEN/2)

// les dimensions
#define CARDWIDTH 50
#define CARDHEIGHT 75
#define PDIST (CARDWIDTH + MARGIN)

#define MARGIN 10
#define XENERGY MARGIN
#define YENERGY MARGIN
#define XACTIVE 70
#define YACTIVE MARGIN
#define XSPECIAL 370
#define YSPECIAL MARGIN
#define XENJEU MARGIN
#define YENJEU 95
#define XPIOCHE 190
#define YPIOCHE 95
#define XCIMETIERE 370
#define YCIMETIERE 95
#define XMAIN 70
#define YMAIN 180

#define XENDTURN (XSCREEN/2 - 25)
#define YENDTURN 350
#define WENDTURN 50
#define HENDTURN 30

///COLORS
// des couleurs
#define BLANC makecol(255,255,255)
#define NOIR makecol(0,0,0)
#define ROUGE makecol(255,0,0)
#define BLEU makecol(0,0,255)
#define VERT makecol(0,255,0)
#define MAG makecol (255,0,255)         //magenta

/// ces couleurs sont celles qu'on utilisait dans le projet ECEcraft. Quand besoin on peut les réutiliser
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


///FILE NAMES

#if defined(WIN32) || defined(WIN64)

#define SOURIS "Res\\mario_mouse_cursor.bmp" //32x30
#define ENDTURN "Res\\End_Turn_Button.bmp"   //50x30

#else

#define SOURIS "Res/mario_mouse_cursor.bmp" //32x30
#define ENDTURN "Res/End_Turn_Button.bmp"   //50x30

#endif // WIN32


// renvoie une erreur de chargement
#define ERR_CHARG(x) {if(!x){allegro_message("probleme de chargement");exit(1);}}

struct Sprites{
    BITMAP *souris;
    BITMAP *buttonEndTurn;
};

#endif //DEFINES_H_INCLUDED


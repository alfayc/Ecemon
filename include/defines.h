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

struct PlayerInput{
    bool prevClick;
    bool dragging;

    int startX, startY;
    int startType;
    int startNum;

    int endX, endY;
    int endType;
    int endNum;
};

struct Domaines{
    int value[NBDOMAINE]; //la quantité d'énergie disponible pour chaque domaine
};


///GRAPHICS DIMENTIONS AND COORDINATES
#define XSCREEN 600
#define YSCREEN 800

#define XPLAYERSIDE 0
#define YPLAYERSIDE (YSCREEN/2)
#define WPLAYERSIDE XSCREEN
#define HPLAYERSIDE (YSCREEN/2)

// les dimensions
#define CARDWIDTH 70
#define CARDHEIGHT 100
#define PDIST (CARDWIDTH + MARGIN)

#define MARGIN 10
#define XENERGY MARGIN
#define YENERGY MARGIN
#define XACTIVE (PDIST + MARGIN)
#define YACTIVE MARGIN
#define XSPECIAL (6*PDIST + MARGIN)
#define YSPECIAL MARGIN
#define XENJEU MARGIN
#define YENJEU (CARDHEIGHT + 2*MARGIN)
#define XPIOCHE ((PDIST*7 + 10)/2 - CARDWIDTH/2)
#define YPIOCHE YENJEU
#define XCIMETIERE XSPECIAL
#define YCIMETIERE YENJEU
#define XMAIN XACTIVE
#define YMAIN (2*CARDHEIGHT + 3*MARGIN)

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

#ifdef _WINDOWS

#define SOURIS "Res\\mario_mouse_cursor.bmp" //32x30
#define ENDTURN "Res\\End_Turn_Button.bmp"   //50x30

#else

#define SOURIS "Res/mario_mouse_cursor.bmp" //32x30
#define ENDTURN "Res/End_Turn_Button.bmp"   //50x30

#endif // WIN32


#define PRINT(x) {cout<<endl<<x<<endl;cout.flush();}

// renvoie une erreur de chargement
#define ERR_CHARG(x) {if(!x){allegro_message("probleme de chargement");exit(1);}}

struct Sprites{
    BITMAP *souris;
    BITMAP *buttonEndTurn;
};

#endif //DEFINES_H_INCLUDED


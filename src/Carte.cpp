//Don't forget to include what's necessary
#include "Carte.h"

Carte::Carte()
{
    //ctor
}

Carte::~Carte()
{
    //dtor
}
/*
#define XFENETRE 105		
#define YFENETRE 140		
#define WFENETRE 460		
#define HFENETRE 620		
#define XBUTTON 390		
#define YBUTTON 650		
#define WBUTTON 150		
#define HBUTTON 100		
 		
 		
void Carte::Detail(BITMAP *fond, PlayerInput& p_input, const Sprites& sprites)		
{		
    BITMAP *buffer = create_bitmap(XSCREEN, YSCREEN);		
    BITMAP *fenetre = create_bitmap(WFENETRE, HFENETRE);		
    bool bool1 = false;		
    rectfill(fenetre, 0,0, WFENETRE, HFENETRE, BLEU);		
    draw_sprite(fenetre, GetCardFront(),5, 5  );		
 		
 		
    rectfill(fond, 0 ,0, XSCREEN, YSCREEN, VERT);		
 		
 		
    rectfill(fenetre,XBUTTON-XFENETRE, YBUTTON-YFENETRE, XBUTTON+150-XFENETRE, YBUTTON+100-YFENETRE, COL_BRIDGE);		
    textprintf_ex(fenetre, font, 50 + XTEXT, 50 + 1, BLANC, -1, "%s", "autrebordel");//nom		
    textprintf_ex(fenetre, font, 50 + XTEXT, 100 + 1, BLANC, -1, "%s", "bordel");// descirption		
    //assemble la fenetre (drawsprite la carte, affiche en grand le nom et la description)		
 		
    while (!bool1)		
    {		
        blit(fond ,buffer, 0,0, 0, 0, XSCREEN, YSCREEN);		
        blit(fenetre,buffer, 0, 0, XFENETRE, YFENETRE, WFENETRE, HFENETRE);		
 		
 		
        if (mouse_b & 1)		
        {		
            if (!p_input.prevClick)		
            {		
                if (mouse_x>=XBUTTON && mouse_x<(XBUTTON+WBUTTON) && mouse_y>=YBUTTON && mouse_y<(YBUTTON+HBUTTON))		
                {		
 		
                    bool1 = true;		
 		
                }		
            }		
 		
            p_input.prevClick = true;		
        }		
        else		
        {		
 		
            p_input.prevClick = false;		
        }		
 		
        draw_sprite(buffer, sprites.souris, mouse_x, mouse_y);		
        blit(buffer, screen,0,0, 0, 0, XSCREEN, YSCREEN);		
 		
    }		
}*/

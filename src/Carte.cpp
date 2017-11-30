#include "Carte.h"

Carte::Carte()
{
    //ctor
}

Carte::~Carte()
{
    //dtor
}

//les constantes utilisées dans cette fonction son dans defines.h, dans les valeurs graphiques

void Carte::Detail(BITMAP *fond, PlayerInput& p_input, const Sprites& sprites)
{
    BITMAP *buffer = create_bitmap(XSCREEN, YSCREEN);
    BITMAP *fenetre = create_bitmap(WFENETRE, HFENETRE);
    bool retours = false;

    rectfill(fenetre, 0,0, WFENETRE, HFENETRE, BLEU); //fond de la fenetre

    draw_sprite(fenetre, GetCardFront(), 5, 5);

    //le bouton de retours
    rectfill(fenetre, XBRETOUR - XFENETRE, YBRETOUR - YFENETRE, XBRETOUR+WBRETOUR - XFENETRE, YBRETOUR+HBRETOUR - YFENETRE, COL_BRIDGE);

    //assemble la fenetre (drawsprite la carte, affiche en grand le nom et la description)
    textprintf_ex(fenetre, font, 50 + XTEXT, 50 + 1, BLANC, -1, "%s", "autrebordel");   //nom
    textprintf_ex(fenetre, font, 50 + XTEXT, 100 + 1, BLANC, -1, "%s", "bordel");       // descirption

    //boucle evennementielle
    while (!retours)
    {
        blit(fond, buffer, 0, 0, 0, 0, XSCREEN, YSCREEN);
        blit(fenetre, buffer, 0, 0, XFENETRE, YFENETRE, WFENETRE, HFENETRE);

        if (mouse_b & 1)
        {
            if (!p_input.prevClick)
            {
                if (mouse_x>=XBRETOUR && mouse_x<(XBRETOUR+WBRETOUR) && mouse_y>=YBRETOUR && mouse_y<(YBRETOUR+HBRETOUR))
                {
                    retours = true;
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

    destroy_bitmap(fond);
    destroy_bitmap(fenetre);
}


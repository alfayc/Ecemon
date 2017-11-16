#include "Player.h"

using namespace std;

Player::Player()
{
    m_Enjeu = NULL;

    for (int i=0;i<MAXSPECIAL;i++)
    {
        m_Special[i] = NULL;
    }

    for (int i=0;i<MAXACTIVE;i++)
    {
        m_Active[i] = NULL;
    }



    m_Exclusive = NULL;

    for (int i=0;i<NBDOMAINE;i++)
    {
        m_CurrentEnergy[i] = 0;
    }
}

Player::~Player()
{
    //dtor
}

void Player::Draw(BITMAP *dest, bool turn)
{
    BITMAP *rep = create_bitmap(dest->w, dest->h);
    rectfill(rep, 0, 0, dest->w, dest->h, BLANC);

    rect(rep, XENERGY, YENERGY, XENERGY+CARDWIDTH, YENERGY+CARDHEIGHT, NOIR);
    if (!m_Energie.empty())
        rectfill(rep, XENERGY, YENERGY, XENERGY+CARDWIDTH, YENERGY+CARDHEIGHT, NOIR);

    for (int i=0;i<MAXACTIVE;i++)
    {
        rect(rep, i*(CARDWIDTH+MARGIN) + XACTIVE, YACTIVE, i*(CARDWIDTH+MARGIN) + XACTIVE+CARDWIDTH, YACTIVE+CARDHEIGHT, ROUGE);
        if (m_Active[i])
            rectfill(rep, i*(CARDWIDTH+MARGIN) + XACTIVE, YACTIVE, i*(CARDWIDTH+MARGIN) + XACTIVE+CARDWIDTH, YACTIVE+CARDHEIGHT, ROUGE);
    }

    for (int i=0;i<MAXSPECIAL;i++)
    {
        rect(rep, i*(CARDWIDTH+MARGIN) + XSPECIAL, YSPECIAL, i*(CARDWIDTH+MARGIN) + XSPECIAL+CARDWIDTH, YSPECIAL+CARDHEIGHT, BLEU);
        if (m_Active[i])
            rectfill(rep, i*(CARDWIDTH+MARGIN) + XSPECIAL, YSPECIAL, i*(CARDWIDTH+MARGIN) + XSPECIAL+CARDWIDTH, YSPECIAL+CARDHEIGHT, BLEU);
    }

    rect(rep, (CARDWIDTH+MARGIN) + XENJEU, YENJEU, (CARDWIDTH+MARGIN) + XENJEU+CARDWIDTH, YENJEU+CARDHEIGHT, VERT);
    if (m_Enjeu)
        rectfill(rep, (CARDWIDTH+MARGIN) + XENJEU, YENJEU, (CARDWIDTH+MARGIN) + XENJEU+CARDWIDTH, YENJEU+CARDHEIGHT, VERT);

    rect(rep, (CARDWIDTH+MARGIN) + XPIOCHE, YPIOCHE, (CARDWIDTH+MARGIN) + XPIOCHE+CARDWIDTH, YPIOCHE+CARDHEIGHT, MAG);
    if (!m_Deck.empty())
        rectfill(rep, (CARDWIDTH+MARGIN) + XPIOCHE, YPIOCHE, (CARDWIDTH+MARGIN) + XPIOCHE+CARDWIDTH, YPIOCHE+CARDHEIGHT, MAG);

    rect(rep, (CARDWIDTH+MARGIN) + XCIMETIERE, YCIMETIERE, (CARDWIDTH+MARGIN) + XCIMETIERE+CARDWIDTH, YCIMETIERE+CARDHEIGHT, COL_SAND);
    if (!m_Cimetiere.empty())
        rectfill(rep, (CARDWIDTH+MARGIN) + XCIMETIERE, YCIMETIERE, (CARDWIDTH+MARGIN) + XCIMETIERE+CARDWIDTH, YCIMETIERE+CARDHEIGHT, COL_SAND);


    if (turn)
    {
        for (unsigned int i = 0;i<m_Main.size();i++) //m_Main est un vecteur (données contingues en mémoire)
        {
            rect(rep, i*(CARDWIDTH+MARGIN) + XMAIN, YMAIN, i*(CARDWIDTH+MARGIN) + XMAIN+CARDWIDTH, YMAIN+CARDHEIGHT, COL_MOUNTAIN);

            //généralement inutilepuisque la case du vecteur n'éisterait pas sinon
            if (m_Main[i])
                rectfill(rep, i*(CARDWIDTH+MARGIN) + XMAIN, YMAIN, i*(CARDWIDTH+MARGIN) + XMAIN+CARDWIDTH, YMAIN+CARDHEIGHT, COL_MOUNTAIN);
        }

        blit(rep, dest, 0, 0, 0, 0, dest->w, dest->h);
    }
    else
    {
        rotate_sprite(dest, rep, 0, 0, 128); //rotation complète
    }

    destroy_bitmap(rep);
}

void Player::EndTurn()
{

}

void Player::Turn()
{

}

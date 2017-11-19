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


    m_Deck.push(new Creature(*(new ModeleCreature(0))));
    m_Deck.push(new Creature(*(new ModeleCreature(0))));
    m_Deck.push(new Energie(*(new ModeleEnergie)));
    m_Deck.push(new Creature(*(new ModeleCreature(0))));
    m_Deck.push(new Special(*(new ModeleSpecial)));
    m_Deck.push(new Special(*(new ModeleSpecial)));
    m_Deck.push(new Creature(*(new ModeleCreature(0))));
    m_Deck.push(new Creature(*(new ModeleCreature(0))));

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

void Player::EndTurn()
{

}

void Player::StartTurn()
{
    if (m_Main.size()<MAXHAND && !m_Deck.empty())
    {
        m_Main.push_back(m_Deck.front()); //on met la carte en haut de la pioche dans la main
        m_Deck.pop(); //on enlève la carte d'en haut de la pioche
    }
}

bool ClickCheck(int xOffset, int yOffset, int& choiceType, int& choiceNum)
{
    int x = mouse_x - xOffset;
    int y = mouse_y - yOffset;

    if (x<0 || x>=WPLAYERSIDE || y<0 || y>=HPLAYERSIDE)
        return false;

    //test de chaque case. pourrait être fait avec des modulos + switch mais vu qu'on va peut être pas aligner les cartes...
    if (x>=XENERGY && x<XENERGY+CARDWIDTH && y>=YENERGY && y<YENERGY+CARDHEIGHT)
    {
        choiceType = PENERGY;
        return true;
    }
    else if (x>=XACTIVE && x<(XACTIVE + MAXACTIVE*PDIST) && y>=YACTIVE && y<(YACTIVE+CARDHEIGHT))
    {
        if ((x-XACTIVE)%PDIST < CARDWIDTH)
        {
            choiceType = PACTIVE;
            choiceNum = (int)((x-XACTIVE)%PDIST);
            return true;
        }
        else
            return false;
    }
    else if (x>=XSPECIAL && x<(XSPECIAL+MAXSPECIAL*PDIST) && y>=YSPECIAL && y<(YSPECIAL+CARDHEIGHT))
    {
        if ((x-XSPECIAL)%PDIST < CARDWIDTH)
        {
            choiceType = PACTIVE;
            choiceNum = (int)((x-XSPECIAL)%PDIST);
            return true;
        }
        else
            return false;
    }
    else if (x>=XENJEU && x<(XENJEU+CARDWIDTH) && y>=YENJEU && y<(YENJEU+CARDHEIGHT))
    {
        choiceType = PENJEU;
        return true;
    }
    else if (x>=XPIOCHE && x<(XPIOCHE+CARDWIDTH) && y>=YPIOCHE && y<(YPIOCHE+CARDHEIGHT))
    {
        choiceType = PPIOCHE;
        return true;
    }
    else if (x>=XCIMETIERE && x<(XCIMETIERE+CARDWIDTH) && y>=YCIMETIERE && y<(YCIMETIERE+CARDHEIGHT))
    {
        choiceType = PCIMETIERE;
        return true;
    }
    else if (x>=XMAIN && x<(XMAIN+MAXHAND*PDIST) && y>=YMAIN && y<(YMAIN+CARDHEIGHT))
    {
        if ((x-XMAIN)%PDIST < CARDWIDTH)
        {
            choiceType = PMAIN;
            choiceNum = (int)((x-XMAIN)%PDIST);
            return true;
        }
        else
            return false;
    }

    return false;
}


//contient la boucle evennementielle
void Player::Turn(Player& opponent, BITMAP *buffer, const Sprites& sprites)
{
    bool prevMouse = true;
    bool endTurn = false;

    BITMAP *playerView = create_bitmap(XSCREEN, YSCREEN/2);

    do
    {
        this->Draw(playerView, true);
        blit(playerView, buffer, 0, 0, 0, YSCREEN/2, XSCREEN, YSCREEN/2);

        opponent.Draw(playerView, false);
        blit(playerView, buffer, 0, 0, 0, 0, XSCREEN, YSCREEN/2);

        draw_sprite(buffer, sprites.buttonEndTurn, XENDTURN, YENDTURN);
        cout << mouse_x << " " << mouse_y << endl;

        draw_sprite(buffer, sprites.souris, mouse_x, mouse_y);
        blit(buffer, screen, 0, 0, 0, 0, XSCREEN, YSCREEN);

        if (mouse_b&1)
        {
            if (!prevMouse)
            {
                if (mouse_x>=XENDTURN && mouse_x<=(XENDTURN+WENDTURN) && mouse_y>=YENDTURN && mouse_y<=(YENDTURN+HENDTURN))
                    endTurn = true;
                else
                {
                    int choiceType, choiceNum;
                    if (ClickCheck(0, YSCREEN/2, choiceType, choiceNum))
                    {
                        switch (choiceType)
                        {
                            case PENERGY:

                        break;

                            case PACTIVE:

                        break;

                            case PSPECIAL:

                        break;

                            case PENJEU:

                        break;

                            case PPIOCHE:

                        break;

                            case PCIMETIERE:

                        break;

                            case PMAIN:

                        break;
                        }
                    }
                }
            }
            prevMouse = true;
        }
        else
            prevMouse = false;

        rest(20);

        if (key[KEY_ESC])
            break;

    }while (!endTurn);
}

void Player::Draw(BITMAP *dest, bool turn)
{
    int col = 0;
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

    rect(rep, XENJEU, YENJEU, XENJEU+CARDWIDTH, YENJEU+CARDHEIGHT, VERT);
    if (m_Enjeu)
        rectfill(rep, XENJEU, YENJEU, XENJEU+CARDWIDTH, YENJEU+CARDHEIGHT, VERT);

    rect(rep, XPIOCHE, YPIOCHE, XPIOCHE+CARDWIDTH, YPIOCHE+CARDHEIGHT, MAG);
    if (!m_Deck.empty())
        rectfill(rep, XPIOCHE, YPIOCHE, XPIOCHE+CARDWIDTH, YPIOCHE+CARDHEIGHT, MAG);

    rect(rep, XCIMETIERE, YCIMETIERE, XCIMETIERE+CARDWIDTH, YCIMETIERE+CARDHEIGHT, COL_SAND);
    if (!m_Cimetiere.empty())
        rectfill(rep, XCIMETIERE, YCIMETIERE, XCIMETIERE+CARDWIDTH, YCIMETIERE+CARDHEIGHT, COL_SAND);


    if (turn)
    {
        for (unsigned int i = 0;i<m_Main.size();i++) //m_Main est un vecteur (données contingues en mémoire)
        {
            switch (m_Main[i]->GetCardType())
            {
                case ENERGIE:
                col = NOIR;
            break;

                case CREATURE:
                col = ROUGE;
            break;

                case SPECIAL:
                col = BLEU;
            break;
            }

            rect(rep, i*(CARDWIDTH+MARGIN) + XMAIN, YMAIN, i*(CARDWIDTH+MARGIN) + XMAIN+CARDWIDTH, YMAIN+CARDHEIGHT, COL_MOUNTAIN);

            rectfill(rep, i*(CARDWIDTH+MARGIN) + XMAIN + 1, YMAIN +1, i*(CARDWIDTH+MARGIN) + XMAIN+CARDWIDTH - 1, YMAIN+CARDHEIGHT - 1, col);
        }

        blit(rep, dest, 0, 0, 0, 0, dest->w, dest->h);
    }
    else
    {
        rotate_sprite(dest, rep, 0, 0, 128); //rotation complète
    }

    destroy_bitmap(rep);
}



//Don't forget to include what's necessary
#include "ModeleCreature.h"

ModeleCreature::ModeleCreature()
{
    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, ROUGE);

    for (int i=0;i<MAXMOVES;i++)
        textprintf_ex(m_CardFront, font, XTEXT + 4, YACTION + i*HATTACK + 6, NOIR, -1, "%dDMG", m_Moves[i].GetDamage());

}

ModeleCreature::ModeleCreature(int a)
    :m_HP(10)
{
    m_Nom = "premiere";
    m_Description = "";

    m_Moves[0] = Move(1);
    m_Moves[1] = Move(2);

    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, ROUGE);

    for (int i=0;i<MAXMOVES;i++)
        textprintf_ex(m_CardFront, font, XTEXT + 4, YACTION + i*HATTACK + 6, NOIR, -1, "%dDMG", m_Moves[i].GetDamage());

}

ModeleCreature::~ModeleCreature()
{
    //dtor
}


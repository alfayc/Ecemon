//Don't forget to include what's necessary
#include "ModeleCreature.h"

ModeleCreature::ModeleCreature()
{
    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, ROUGE);

    textprintf_ex(m_CardFront, font, XTEXT + 4, YACTION + 6, NOIR, -1, "%dDMG", m_AD);

}

ModeleCreature::ModeleCreature(int a)
    :m_AD(2), m_HP(10), m_Nom("premiere"), m_Description("")
{
    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, ROUGE);

    textprintf_ex(m_CardFront, font, XTEXT + 4, YACTION + 6, NOIR, -1, "%dDMG", m_AD);

}

ModeleCreature::~ModeleCreature()
{
    //dtor
}

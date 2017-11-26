#include "ModeleEnergie.h"

ModeleEnergie::ModeleEnergie()
    :m_Energy(3), m_Domaine(1)
{
    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, NOIR);
}

ModeleEnergie::~ModeleEnergie()
{
    //dtor
}


//Don't forget to include what's necessary
#include "ModeleSpecial.h"

ModeleSpecial::ModeleSpecial()
    :m_ActiveLeft(3)
{
    m_CardFront = load_bitmap(FCARDT, NULL); ERR_CHARG(m_CardFront) ///À ENLEVER

    rectfill(m_CardFront, XDESCRI, YDESCRI, XDESCRI + WDESCRI, YDESCRI + HDESCRI, BLEU);
}

ModeleSpecial::~ModeleSpecial()
{
    //dtor
}

void ModeleSpecial::Action()
{

}


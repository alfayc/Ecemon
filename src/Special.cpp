//Don't forget to include what's necessary
#include "Special.h"

Special::Special(ModeleSpecial& _Modele)
    :m_Modele(_Modele)
{
    m_CardType = SPECIAL;
}

Special::~Special()
{
    //dtor
}

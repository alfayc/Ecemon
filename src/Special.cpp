//Don't forget to include what's necessary
#include "Special.h"

Special::Special(ModeleSpecial& _Modele)
    :m_Modele(_Modele)
{

}

Special::~Special()
{
    //dtor
}

CardType Special::GetCardType()
{
    return SPECIAL;
}


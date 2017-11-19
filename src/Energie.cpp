//Don't forget to include what's necessary
#include "Energie.h"

Energie::Energie(ModeleEnergie& _Modele)
    :m_Modele(_Modele)
{
}

Energie::~Energie()
{
    //dtor
}


CardType Energie::GetCardType()
{
    return ENERGIE;
}


//Don't forget to include what's necessary
#include "Energie.h"

Energie::Energie(ModeleEnergie& _Modele)
    :m_Modele(_Modele)
{
    m_CardType = ENERGIE;
}

Energie::~Energie()
{
    //dtor
}


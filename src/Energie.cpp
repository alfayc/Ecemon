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

BITMAP *Energie::GetCardFront()
{
    return nullptr;
}

void Energie::Use(Domaines& where)
{
    where.value[m_Modele.GetDomaine()] += m_Modele.GetEnergy();
}


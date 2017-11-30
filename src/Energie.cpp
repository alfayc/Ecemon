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

BITMAP *Energie::GetCardFront()
{
    return m_Modele.GetCardFront();
}

void Energie::Use(Domaines& where)
{
    where.value[m_Modele.GetDomaine()] += m_Modele.GetEnergy();
}

void Energie::Reset()
{
    //nothing to do
}


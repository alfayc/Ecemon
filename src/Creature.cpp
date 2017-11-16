//Don't forget to include what's necessary
#include "Creature.h"

Creature::Creature(ModeleCreature& _Modele)
    :m_Modele(_Modele)
{
    m_CardType = CREATURE;

    m_HP = _Modele.GetHP();
    m_AD = _Modele.GetAD();
}

Creature::~Creature()
{
    //dtor
}


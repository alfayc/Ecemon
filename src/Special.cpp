//Don't forget to include what's necessary
#include "Special.h"
#include "Player.h"

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

void Special::StartTurn()
{
    m_ActiveLeft--;

    if (m_ActiveLeft<0) //on sait jamais
        m_ActiveLeft = 0;
}

void Special::EndTurn(Player& ally, Player& enemy)
{
    //l'action specifique à la carte
}


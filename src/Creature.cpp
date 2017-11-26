//Don't forget to include what's necessary
#include "Creature.h"

#include "Player.h"

using namespace std;

Creature::Creature(ModeleCreature& _Modele)
    :m_Modele(_Modele), m_HP(_Modele.GetHP()), m_Attack(false), m_Cible(0), m_Frozen(0)
{
    for (int i=0;i<MAXMOVES;i++)
    {
        m_Moves[i] = m_Modele.GetMove(i); //m_Moves est un tableau de Moves (PAS POINTEUR)
    }
}

Creature::~Creature()
{
    //dtor
}

CardType Creature::GetCardType()
{
    return CREATURE;
}

BITMAP *Creature::GetCardFront()
{
    return m_Modele.GetCardFront();
}

void Creature::SetAttack(int who, int _move)
{
    if (!m_Frozen)
    {
        m_Attack = true;
        m_Cible = who;
        m_AttackMove = _move;
    }
}

void Creature::AddFrozen(int quant)
{
    if (quant>0)
    {
        m_Frozen += quant;
    }
    else
        throw quant;
}

int Creature::TakeDamage(int quant)
{
    if (m_HP>=quant)
    {
        m_HP -= quant;
        return 0;
    }
    else
    {
        int rep = quant - m_HP;
        m_HP = 0;
        return rep;
    }
}

void Creature::EndTurn(Player& ally, Player& enemy)
{
    if (m_Frozen>0)
        m_Frozen--;

    if (m_Attack)
    {
        m_Moves[m_AttackMove].Attack(ally, enemy, m_Cible);

        m_Attack = false;
    }
}


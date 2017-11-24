//Don't forget to include what's necessary
#include "Creature.h"

#include "Player.h"

Creature::Creature(ModeleCreature& _Modele)
    :m_Modele(_Modele), m_HP(_Modele.GetHP()), m_AD(_Modele.GetAD()), m_Attack(false), m_Cible(0)
{

}

Creature::~Creature()
{
    //dtor
}

CardType Creature::GetCardType()
{
    return CREATURE;
}

void Creature::SetAttack(int who)
{
    m_Attack = true;
    m_Cible = who;
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
    if (m_Attack)
    {
        if (m_Cible==-1)
        {
            enemy.TakeDamage(m_AD);
        }
        else
        {
            int retenue = 0;

            retenue = enemy.GetActive(m_Cible)->TakeDamage(m_AD);

            if (retenue)
            {
                enemy.TakeDamage(retenue);
            }
        }
    }
}


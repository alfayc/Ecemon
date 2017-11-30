#include "ModeleCreature.h"
///declaration de la classe Move dans ModeleCreature.h

#include "Player.h"

Move::Move()
    :m_Damage(0)
{
    //ctor
}

Move::Move(int _Damage)
    :m_Damage(_Damage)
{
    //ctor
}

Move::~Move()
{
    //dtor
}

void Move::Attack(Player& ally, Player& enemy, int who)
{
    if (who==-1)
    {
        enemy.TakeDamage(m_Damage);
    }
    else
    {
        int retenue = enemy.GetActive(who)->TakeDamage(m_Damage);

        if (retenue)
        {
            enemy.TakeDamage(retenue);
        }
    }
}


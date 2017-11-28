#ifndef MODELECREATURE_H
#define MODELECREATURE_H

#include "defines.h"
#include "ModeleCarte.h"

///ATTENTION L'implementation de ModeleCreature et Move ne sont pas dans les mêmes fichiers

class Player;

//la classe de l'attaque
class Move
{
    private:

    protected:
        int m_Damage;

    public:
        Move();
        Move(int _Damage);
        virtual ~Move();

        //who = -1 to attack the enemy player himself
        virtual void Attack(Player& ally, Player& enemy, int who); //only attack the enemy, but if we decide to be vampiric....

        int GetDamage() { return m_Damage; }
};

class ModeleCreature : public ModeleCarte
{
    private:

    protected:
        int m_HP;
        Move m_Moves[MAXMOVES];

    public:
        ModeleCreature();
        ModeleCreature(int a);
        virtual ~ModeleCreature();

        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }
        BITMAP *GetCardFront() { return m_CardFront; }
        const Move& GetMove(int num) { return m_Moves[num]; }

};

#endif // MODELECREATURE_H


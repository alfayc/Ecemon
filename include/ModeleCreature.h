#ifndef MODELECREATURE_H
#define MODELECREATURE_H

#include "defines.h"

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

class ModeleCreature
{
    private:

    protected:
        int m_CardNum; // le numéro de la carte (mario etc...)
        std::string m_Nom;
        std::string m_Description;

        int m_HP;
        Move m_Moves[MAXMOVES];

        BITMAP *m_CardFront;

    public:
        ModeleCreature();
        ModeleCreature(int a);
        virtual ~ModeleCreature();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }
        BITMAP *GetCardFront() { return m_CardFront; }
        const Move& GetMove(int num) { return m_Moves[num]; }

};

#endif // MODELECREATURE_H


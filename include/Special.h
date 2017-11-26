#ifndef SPECIAL_H
#define SPECIAL_H

#include "defines.h"
#include "Carte.h"
#include "ModeleSpecial.h"

class Player;

class Special : public Carte
{
    private:

    protected:
        ModeleSpecial& m_Modele;

        int m_ActiveLeft;

    public:
        Special(ModeleSpecial& _Modele);
        virtual ~Special();

        void StartTurn();
        void EndTurn(Player& ally, Player& enemy);

        virtual CardType GetCardType();
        virtual BITMAP *GetCardFront();

        int GetActiveLeft() { return m_ActiveLeft; }
};

#endif // SPECIAL_H

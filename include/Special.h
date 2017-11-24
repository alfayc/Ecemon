#ifndef SPECIAL_H
#define SPECIAL_H

#include "defines.h"
#include "Carte.h"
#include "ModeleSpecial.h"

class Player;

class Special : public Carte
{
    private:
        ModeleSpecial& m_Modele;

        int m_ActiveLeft;

    protected:

    public:
        Special(ModeleSpecial& _Modele);
        virtual ~Special();

        void StartTurn();
        void EndTurn(Player& ally, Player& enemy);

        CardType GetCardType();

        int GetActiveLeft() { return m_ActiveLeft; }
};

#endif // SPECIAL_H

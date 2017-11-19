#ifndef CREATURE_H
#define CREATURE_H

#include "defines.h"
#include "Carte.h"
#include "ModeleCreature.h"

class Creature : public Carte
{
    private:
        ModeleCreature& m_Modele;
        int m_HP;
        int m_AD;

    protected:

    public:
        Creature(ModeleCreature& _Modele);
        virtual ~Creature();

        CardType GetCardType();
};

#endif // CREATURE_H


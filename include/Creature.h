#ifndef CREATURE_H
#define CREATURE_H

#include "defines.h"
#include "Carte.h"
#include "ModeleCreature.h"

class Creature : public Carte
{
    public:
        Creature(ModeleCreature& _Modele);
        virtual ~Creature();

    protected:

    private:
        ModeleCreature& m_Modele;
};

#endif // CREATURE_H


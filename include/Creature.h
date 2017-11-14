//Don't forget to include what's necessary
#ifndef CREATURE_H
#define CREATURE_H

#include <Carte.h>


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

#ifndef COLLECTION_H
#define COLLECTION_H

#include "defines.h"
#include "Creature.h"
#include "Energie.h"
#include "Special.h"

class Collection
{
    public:
        Collection();
        virtual ~Collection();

    protected:

    private:
        std::vector<Carte *> m_Cartes;
};

#endif // COLLECTION_H

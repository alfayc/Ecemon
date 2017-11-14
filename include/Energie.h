//Don't forget to include what's necessary
#ifndef ENERGIE_H
#define ENERGIE_H


#include "defines.h"
#include "Carte.h"
#include "ModeleEnergie.h"


class Energie : public Carte
{
    public:
        Energie(ModeleEnergie& _Modele);
        virtual ~Energie();

    protected:

    private:
        ModeleEnergie& m_Modele;
};

#endif // ENERGIE_H

#ifndef ENERGIE_H
#define ENERGIE_H


#include "defines.h"
#include "Carte.h"
#include "ModeleEnergie.h"


class Energie : public Carte
{
    private:

    protected:
        ModeleEnergie& m_Modele;

    public:
        Energie(ModeleEnergie& _Modele);
        virtual ~Energie();

        virtual CardType GetCardType();
        virtual BITMAP *GetCardFront();

        void Use(Domaines& where);
};

#endif // ENERGIE_H

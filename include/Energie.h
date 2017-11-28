#ifndef ENERGIE_H
#define ENERGIE_H


#include "defines.h"
#include "Carte.h"
#include "ModeleEnergie.h"


class Energie : public Carte
{
    private:

    protected:
        /* le modele de carte */
        ModeleEnergie& m_Modele;

    public:
        Energie(ModeleEnergie& _Modele);
        virtual ~Energie();

        //renvoie le type de carte
        virtual CardType GetCardType();
        //renvoie la face de la carte
        virtual BITMAP *GetCardFront();

        // ajoute l'énergie de cette carte à un ensemble de domaines
        void Use(Domaines& where);
};

#endif // ENERGIE_H

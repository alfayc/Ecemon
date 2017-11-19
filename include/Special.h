#ifndef SPECIAL_H
#define SPECIAL_H

#include "defines.h"
#include "Carte.h"
#include "ModeleSpecial.h"



class Special : public Carte
{
    private:
        ModeleSpecial& m_Modele;

    protected:

    public:
        Special(ModeleSpecial& _Modele);
        virtual ~Special();

        CardType GetCardType();
};

#endif // SPECIAL_H

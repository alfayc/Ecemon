//Don't forget to include what's necessary
#ifndef SPECIAL_H
#define SPECIAL_H

#include "defines.h"
#include "Carte.h"
#include "ModeleSpecial.h"



class Special : public Carte
{
    public:
        Special(ModeleSpecial& _Modele);
        virtual ~Special();

    protected:

    private:

    ModeleSpecial& m_Modele;
};

#endif // SPECIAL_H

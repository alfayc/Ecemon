#ifndef CARTE_H
#define CARTE_H

#include "defines.h"

class Player;

enum CardType{
    ENERGIE = 0,
    CREATURE = 1,
    SPECIAL = 2
};


class Carte
{
    private:

    protected:

    public:
        Carte();
        virtual ~Carte();

        /* renvoie le type de carte (creature, energie, special */
        virtual CardType GetCardType() = 0;

        /* renvoie la face de la carte*/
        virtual BITMAP *GetCardFront() = 0;
};

#endif // CARTE_H


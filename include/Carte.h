#ifndef CARTE_H
#define CARTE_H

#include "defines.h"


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

        virtual CardType GetCardType() = 0;
};

#endif // CARTE_H


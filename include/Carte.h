#ifndef CARTE_H
#define CARTE_H

#include "defines.h"

class Carte
{
    private:

    protected:
        int m_CardType; //le type de carte (energie, creature ou special)

    public:
        Carte();
        virtual ~Carte();

        int GetCardType() { return m_CardType; }
};

#endif // CARTE_H


#ifndef MODELEENERGIE_H
#define MODELEENERGIE_H

#include "defines.h"
#include "ModeleCarte.h"

class ModeleEnergie : public ModeleCarte
{
    private:

    protected:
        int m_Energy;
        int m_Domaine;


    public:
        ModeleEnergie();
        virtual ~ModeleEnergie();

        int GetEnergy() { return m_Energy; }
        void SetEnergy(int val) { m_Energy = val; }
        int GetDomaine() { return m_Domaine; }
        void SetDomaine(int val) { m_Domaine = val; }
        BITMAP *GetCardFront() { return m_CardFront; }

};

#endif // MODELEENERGIE_H


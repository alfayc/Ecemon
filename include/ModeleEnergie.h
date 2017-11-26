#ifndef MODELEENERGIE_H
#define MODELEENERGIE_H

#include "defines.h"

class ModeleEnergie
{
    private:
        std::string m_Nom;
        int m_Energy;
        int m_Domaine;
        std::string m_Description;

        BITMAP *m_CardFront;

    protected:

    public:
        ModeleEnergie();
        virtual ~ModeleEnergie();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        int GetEnergy() { return m_Energy; }
        void SetEnergy(int val) { m_Energy = val; }
        int GetDomaine() { return m_Domaine; }
        void SetDomaine(int val) { m_Domaine = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
        BITMAP *GetCardFront() { return m_CardFront; }

};

#endif // MODELEENERGIE_H


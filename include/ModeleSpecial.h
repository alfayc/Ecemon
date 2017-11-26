#ifndef MODELESPECIAL_H
#define MODELESPECIAL_H

#include "defines.h"


class ModeleSpecial
{
    private:
        std::string m_Nom;
        std::string m_Description;
        int m_ActiveLeft;

        BITMAP *m_CardFront;

    protected:

    public:
        ModeleSpecial();
        virtual ~ModeleSpecial();

        void Action();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
        int GetActiveLeft() { return m_ActiveLeft; }
        BITMAP *GetCardFront() { return m_CardFront; }
};

#endif // MODELESPECIAL_H


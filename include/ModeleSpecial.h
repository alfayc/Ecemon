//Don't forget to include what's necessary
#ifndef MODELESPECIAL_H
#define MODELESPECIAL_H

#include "defines.h"


class ModeleSpecial
{
    public:
        ModeleSpecial();
        virtual ~ModeleSpecial();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }

        void Action();

    protected:

    private:
        std::string m_Nom;
        std::string m_Description;
};

#endif // MODELESPECIAL_H


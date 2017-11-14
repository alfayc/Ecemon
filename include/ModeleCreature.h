//Don't forget to include what's necessary
#ifndef MODELECREATURE_H
#define MODELECREATURE_H

#include "defines.h"


class ModeleCreature
{
    public:
        ModeleCreature();
        virtual ~ModeleCreature();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }
        int GetAD() { return m_AD; }
        void SetAD(int val) { m_AD = val; }

    protected:

    private:
        std::string m_Nom;
        std::string m_Description;
        int m_HP;
        int m_AD;
        const int m_Type = 1;
};

#endif // MODELECREATURE_H

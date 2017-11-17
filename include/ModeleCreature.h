#ifndef MODELECREATURE_H
#define MODELECREATURE_H

#include "defines.h"


class ModeleCreature
{
    private:
        int m_AD;
        int m_HP;
        std::string m_Nom;
        std::string m_Description;

    protected:

    public:
        ModeleCreature();
        ModeleCreature(int a);
        virtual ~ModeleCreature();

        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
        int GetHP() { return m_HP; }
        void SetHP(int val) { m_HP = val; }
        int GetAD() { return m_AD; }
        void SetAD(int val) { m_AD = val; }
};

#endif // MODELECREATURE_H


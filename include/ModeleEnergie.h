#ifndef MODELEENERGIE_H
#define MODELEENERGIE_H


class ModeleEnergie
{
    public:
        ModeleEnergie();
        virtual ~ModeleEnergie();

        string GetNom() { return m_Nom; }
        void SetNom(string val) { m_Nom = val; }
        int GetEnergy() { return m_Energy; }
        void SetEnergy(int val) { m_Energy = val; }
        int GetDomaine() { return m_Domaine; }
        void SetDomaine(int val) { m_Domaine = val; }
        string GetDescription() { return m_Description; }
        void SetDescription(string val) { m_Description = val; }

    protected:

    private:
        string m_Nom;
        int m_Energy;
        int m_Domaine;
        string m_Description;
        const int m_Type = 0;
};

#endif // MODELEENERGIE_H

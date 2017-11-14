//Don't forget to include what's necessary
#ifndef ENERGIE_H
#define ENERGIE_H


class Energie : public Carte
{
    public:
        Energie(ModeleEnergie& _Modele);
        virtual ~Energie();

    protected:

    private:
        ModeleEnergie& m_Modele;
};

#endif // ENERGIE_H

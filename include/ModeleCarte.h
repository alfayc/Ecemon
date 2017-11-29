//Don't forget to include what's necessary
#ifndef MODELECARTE_H
#define MODELECARTE_H

#include "defines.h"

class ModeleCarte
{
    private:

    protected:
        /* le numéro de la carte (dans la map) */
        int m_CardNum;

        std::string m_Nom;
        std::string m_Description;
        BITMAP *m_CardFront;

    public:
        ModeleCarte();
        virtual ~ModeleCarte();

        /* écrit la carte dans un fichier */
        virtual void Write_file(std::ofstream& fichier);

        /* lit la carte dans un fichier
        ON ASSUME QUE LE NUMÉRO DE LA CARTE A DÉJÀ ÉTÉ LU!!!*/
        virtual void Read_file(std::ifstream& fichier);


        int GetCardNum() { return m_CardNum; }
        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::string GetDescription() { return m_Description; }
        void SetDescription(std::string val) { m_Description = val; }
};

#endif // MODELECARTE_H

#ifndef COLLECTION_H
#define COLLECTION_H

#include "defines.h"
#include "Creature.h"
#include "Energie.h"
#include "Special.h"

class Collection
{
    private:
        std::vector<Carte *> m_Cartes;

    protected:

    public:
        Collection();
        virtual ~Collection();

        //void Fill(std::map<int, ModeleCarte *> cardList); //pour remplir depuis l'utilisateur
        void CreateDeck(std::queue<Carte *>& deck); //pour créer un deck depuis la collection
        //void AddCard(Carte *ajout);
        //Carte *PopCard(int num); //enlevè la numième carte et la renvoie. pour l'enjeu

        void WriteFile(std::ostream& fichier);

        /* could throw an out of range exception if the file contains a number outside the range of the map */
        void ReadFile(std::istream& fichier, std::map<int, ModeleCarte *> modeles); //pas oublier de vider le vecteur

        void Reset();
};

#endif // COLLECTION_H


#ifndef PLAYER_H
#define PLAYER_H

#include "defines.h"
#include "Creature.h"
#include "Energie.h"
#include "Special.h"

class Player
{
    private:
        std::string m_Nom;                  //le nom
        std::vector<Carte *> m_Collection;  //la collection de cartes appartenant au joueur
        std::queue<Carte *> m_Deck;         //la piohe du joueur
        std::stack<Carte *> m_Cimetiere;    //le cimetière dans la partie
        std::vector<Carte *> m_Main;        //les cartes dans la main du joueur
        Carte *m_Enjeu;                     //l'enjeu
        Special *m_Special[MAXSPECIAL];     //la/les spéciales persistantes
        Creature *m_Active[MAXACTIVE];      //la/les créatures actives
        std::stack<Carte*> m_Energie;       //la/les cartes énergies consommées
        Carte *m_Exclusive;                 //la carte exclusive à ce joueur (bowser n'a pas mario etc)

        int m_CurrentEnergy[NBDOMAINE];     //la quantité d'énergie disponible pour chaque domaine

    protected:

    public:
        Player();
        virtual ~Player();

        //turn est vraie si c'est au tour de ce joueur
        void Draw(BITMAP *dest, bool turn); //affiche les cartes sur la bitmap en paramètre
        void EndTurn();
        void StartTurn();
        void Turn(Player& opponent, BITMAP *buffer, const Sprites& sprites); //là où y'a la boucle evennementielle


        //getters/setters
        std::string GetNom() { return m_Nom; }
        void SetNom(std::string val) { m_Nom = val; }
        std::vector<Carte*> GetCollection() { return m_Collection; }
        void SetCollection(std::vector<Carte*> val) { m_Collection = val; }
        std::queue<Carte*> GetDeck() { return m_Deck; }
        void SetDeck(std::queue<Carte*> val) { m_Deck = val; }
        std::stack<Carte*> GetCimetiere() { return m_Cimetiere; }
        void SetCimetiere(std::stack<Carte*> val) { m_Cimetiere = val; }
        std::vector<Carte*> GetMain() { return m_Main; }
        void SetMain(std::vector<Carte*> val) { m_Main = val; }
        Carte* GetEnjeu() { return m_Enjeu; }
        void SetEnjeu(Carte* val) { m_Enjeu = val; }
        Carte* GetExclusive() { return m_Exclusive; }
        void SetExclusive(Carte* val) { m_Exclusive = val; }
};

#endif // PLAYER_H

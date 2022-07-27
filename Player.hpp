#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "Level.hpp"
#include "Attaque.hpp"
#include "IA.hpp"
class Player
{
    public:
        Player();
        Player(std::string nom,int level, int exp,int vie,int ki,std::string type);
        void recevoirDegats(int nbDegats);
        void attaque(IA &cible);
        void potion(int nbVie);
        void rechargeKi();
        void lvlGain();
        void estVaincu();
        void afficheEtat() const;
        bool isDead() const;
        int Combat(Player& joueur,IA& cible);



        virtual ~Player();

    protected:

    private:
        IA ia;
        std::string m_nom;
        Level m_level;
        Attaque attack;
        int m_ki;
        std::string m_type;
};

#endif // PLAYER_H

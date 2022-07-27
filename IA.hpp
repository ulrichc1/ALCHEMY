#ifndef IA_H
#define IA_H
#include <string>
#include "Level.hpp"
#include "Attaque.hpp"
class Player;
class IA
{
    public:
        IA();
        virtual ~IA();
        IA(std::string nom,int level, int exp, int vie,int ki,std::string type);
        void recevoirDegats(int nbDegats);
        void attaque(Player& player);
        void potion(int nbVie);
        void rechargeKi();
        void lvlGain();
        void estVaincu();
        void afficheEtat() const;
        bool isDead() const;


    protected:

    private:
        std::string ia_nom;
        Level m_level;
        Attaque attack;
        int ia_ki;
        std::string ia_type;
};

#endif // IA_H

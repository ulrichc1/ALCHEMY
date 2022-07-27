#include "Player.hpp"
#include "Level.hpp"
#include "Attaque.hpp"
#include "IA.hpp"
#include <string>
#include "iostream"
#include "chrono"
#include "thread"

using namespace std;

Player::Player() : m_nom("Joueur"),m_level(0,0), m_ki(20), m_type("Neutral"){}
Player::Player(string nom,int level, int exp, int vie,int ki,string type) :m_nom(nom), m_level(level,exp),m_ki(ki),m_type(type){}

constexpr int DUREE_RECHARGE = 2000;

void Player::estVaincu()
{
    if (isDead()){
        cout << "[" << m_nom << "] est vaincu !" <<endl;
    };
}

void Player::rechargeKi()

{   if (m_ki < 0){
    m_ki = 0;
    }

    if(m_ki < 50){
            this_thread::sleep_for(1s);
            cout << "["<< m_nom << "] Ki recharge ! (+5)" << endl;
            m_ki += 5;
    }
}

void Player::recevoirDegats(int nbDegats)
{
    m_level.m_vie -= nbDegats;
    if (m_level.m_vie <= 0){
        m_level.m_vie = 0;
    };
}

void Player::attaque(IA &cible)
{
     if (m_type == "Feu" && m_ki > 20)
        {
        attack.bouleDeFeu();
        m_ki -= 20;
        }
     else if ( m_type == "Neutral" && m_ki > 10){
        attack.ecraseCorps();
        m_ki -=10;
    }
    else {
        attack.poing();
    }
    ia.recevoirDegats(attack.degats);
    if (ia.isDead()){
        m_level.m_exp += 10;
        m_level.levelUp();
    }
    else {
            rechargeKi();
         };

}
int Player::Combat(Player& joueur,IA& cible){
    for (int i(0); i<50; i++) {
            if(!(joueur.isDead()))
                {
                joueur.attaque(cible);
                cible.afficheEtat();
                }
                else {
                    joueur.estVaincu();
                     cible.afficheEtat();
                     return 0;
                };
                if(!(cible.isDead()))
                {
                    cible.attaque(joueur);
                    joueur.afficheEtat();
                }
                else{
                    cible.estVaincu();
                    joueur.afficheEtat();
                    return 0;
                }
        };
}

void Player::potion(int nbVie)
{
    m_level.m_vie += nbVie;
}





bool Player::isDead() const
{
    return m_level.m_vie == 0;
}




void Player::afficheEtat() const{
    cout << "["<< m_nom << "] Type : " << m_type << " || Vie: " << m_level.m_vie << " || Ki: " << m_ki;
    m_level.afficher();
}



Player::~Player()
{
    //dtor
}

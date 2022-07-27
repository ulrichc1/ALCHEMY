#include "IA.hpp"
#include "Level.hpp"
#include "Attaque.hpp"
#include <string>
#include "iostream"
#include "chrono"
#include "thread"

using namespace std;

IA::IA() : ia_nom("Neutral Mini"),m_level(0,0), ia_ki(20), ia_type("Neutral"){}
IA::IA(string nom,int level, int exp, int vie,int ki,string type) :ia_nom(nom), m_level(level,exp),ia_ki(ki),ia_type(type){}


IA n_mini("Neutral Mini",0,0,50,20,"Neutral");
IA n_medium("Neutral Medium",2,0,100,30,"Neutral");
IA n_master("Neutral Master",5,0,150,40,"Neutral");
IA n_lord("Neutral Lord",10,0,200,50,"Neutral");



void IA::estVaincu()
{
    if (isDead()){
        cout << "[" << ia_nom << "] est vaincu !" <<endl;
    };
}

void IA::rechargeKi()

{   if (ia_ki < 0){
    ia_ki = 0;
    }

    if(ia_ki < 50){
            this_thread::sleep_for(1s);
            cout << "["<< ia_nom << "] Ki recharge ! (+5)" << endl;
            ia_ki += 5;
    }
}

void IA::recevoirDegats(int nbDegats)
{
    m_level.m_vie -= nbDegats;
    if (m_level.m_vie <= 0){
        m_level.m_vie = 0;
    };
}

void IA::attaque(Player &cible)
{
     if (ia_type == "Feu" && ia_ki > 20)
        {
        attack.bouleDeFeu();
        ia_ki -= 20;
        }
     else if ( ia_type == "Neutral" && ia_ki > 10){
        attack.ecraseCorps();
        ia_ki -=10;
    }
    else {
        attack.poing();
    }
    cible.recevoirDegats(attack.degats);
    if (cible.isDead()){
        m_level.m_exp += 10;
        m_level.levelUp();
    }
    else {
            rechargeKi();
         };

}
void IA::potion(int nbVie)
{
    m_level.m_vie += nbVie;
}





bool IA::isDead() const
{
    return m_level.m_vie == 0;
}




void IA::afficheEtat() const{
    cout << "["<< ia_nom << "] Type : " << ia_type << " || Vie: " << m_level.m_vie << " || Ki: " << ia_ki;
    m_level.afficher();
}




IA::~IA()
{
    //dtor
}

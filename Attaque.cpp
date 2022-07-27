#include "Attaque.hpp"
#include "Player.hpp"
#include "Level.hpp"
using namespace std;

Attaque::Attaque()
{
    //ctor
}

Attaque::Attaque(std::string nom_atk, int atk_ki, std::string atk_type, int degats)
{
    //ctor
}

Attaque::~Attaque()
{
    //dtor
}




void Attaque::afficher()
{
    cout <<  "Attaque : " << nom_atk << " (Degats : " << degats << ") || Ki : " << atk_ki << " (Type: " << atk_type << ")" << endl;

}

void Attaque::poing()
{
    atk_ki = 0;
    nom_atk = "Coup de poing";
    atk_type = "Neutral";
    degats = 5 ;
    afficher();
}

void Attaque::bouleDeFeu()
{
    atk_ki = 20;
    nom_atk = "Boule de Feu";
    atk_type = "Feu";
    degats = 20 ;
    afficher();
}
void Attaque::ecraseCorps()
{
    atk_ki = 10;
    nom_atk = "Ecrase-Corps";
    atk_type = "Neutral";
    degats = 10 ;
    afficher();
}



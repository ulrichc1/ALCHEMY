#include "Level.hpp"


Level::Level() : m_level(0),m_exp(0),m_vie(100)
{
    //ctor
}


Level::Level(int level,int exp) : m_level(level),m_exp(exp),m_vie((10 * level)+100)
{
    //ctor
}

void Level::leveledUp(){

    cout << "Montee de niveau ! Niveau : " << m_level << endl;
}

void Level::exp_reinit(){
    m_exp = 0;
    m_vie = 100 + (10*m_level);
}

void Level::levelUp()
{
    if (m_level == 0 && m_exp >= 10){
        m_level += 1;
        exp_reinit();
        leveledUp();
    }

    else if (m_level == 1 && m_exp >= 20){
        m_level += 1;
        exp_reinit();
        leveledUp();
    }

    else if (m_level == 2 && m_exp >= 50){
        m_level += 1;
        exp_reinit();
        leveledUp();
    }

    else if (m_level == 3 && m_exp >= 75){
        m_level += 1;
        exp_reinit();
        leveledUp();
    }
    else if (m_level == 4 && m_exp >= 100){
        m_level += 1;
        exp_reinit();
        leveledUp();
    }
    else {
        cout << endl;
    }
}

void Level::afficher() const
    {

    cout << " || Niveau : " << m_level << " (" << m_exp << " exp.)" <<endl;

    }
Level::~Level()
{
    //dtor
}

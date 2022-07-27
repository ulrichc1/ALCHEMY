#ifndef LEVEL_H
#define LEVEL_H
#include "Player.hpp"


class Level
{
    public:
        int m_vie;
        Level();
        Level(int level, int exp);
        void levelUp();
        void afficher() const;
        void exp_reinit();
        void leveledUp();
        virtual ~Level();
        int m_exp;

    protected:

    private:
        int m_level;


};

#endif // LEVEL_H

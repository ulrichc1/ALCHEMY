#ifndef ATTAQUE_H
#define ATTAQUE_H


class Attaque
{
    public:
        int degats;
        Attaque();
        Attaque(std::string nom_atk, int atk_ki, std::string atk_type, int degats);
        void afficher();
        void poing();
        void bouleDeFeu();
        void ecraseCorps();
        virtual ~Attaque();

    protected:

    private:
        std::string nom_atk;
        int atk_ki;
        std::string atk_type;
};

#endif // ATTAQUE_H

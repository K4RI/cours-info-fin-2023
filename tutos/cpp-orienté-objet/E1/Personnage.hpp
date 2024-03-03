#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include "Arme.hpp"

class Personnage
{
    public:

        Personnage(std::string nom); // constructeur
        Personnage(std::string nom, std::string nomArme, int degatsArme); // constructeur surcharge 2 : arme et dégâts explicités
        Personnage(std::string nom, Personnage const& autre); // constructeur surcharge 3 : copie
        ~Personnage(); // destructeur
        void recevoirDegats(int nbDegats);
        void attaquer(Personnage &cible);
        void boirePotionDeVie(int quantitePotion);
        void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
        bool estVivant() const;
        void afficherEtat() const;
        std::string getNom() const;

    private:

        std::string m_nom;
        int m_vie;
        int m_mana;
        Arme m_arme;
};

#endif
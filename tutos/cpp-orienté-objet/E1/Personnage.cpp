#include "Personnage.hpp"

using namespace std;

Personnage::Personnage(string nom) // constructeur par défaut
{
    m_nom = nom;
    m_vie = 100;
    m_mana = 100;
}

/*
Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("Epee rouillee"), m_degatsArme(10)
{
    // rien à mettre dans le corps, tout a déjà été fait !
}
*/

Personnage::Personnage(string nom, string nomArme, int degatsArme) : m_nom(nom), m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{
    // constructeur surcharge 2 (précise l'arme et les dégâts)
}

Personnage::Personnage(string nom, Personnage const& autre): m_nom(nom), m_vie(100), m_mana(100), m_arme(autre.m_arme)
{
    // constructeur surcharge 3 (copie)
}

Personnage::~Personnage()
{
    /* Destructeur. Rien à mettre ici car on ne fait pas d'allocation dynamique
    dans la classe Personnage. Le destructeur est donc inutile mais
    je le mets pour montrer à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques
    autres vérifications si nécessaire avant la destruction de l'objet. */
}

void Personnage::recevoirDegats(int nbDegats)
{
    cout << m_nom << " reçoit " << nbDegats << " points de dégâts. ";
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        cout << m_nom << " est mort (rip bozo)" << endl;
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
    cout << "Il lui reste " << m_vie << " points de vie." << endl;
}

void Personnage::attaquer(Personnage &cible)
{
    cout << m_nom << " attaque " << cible.getNom() << " !" << endl;
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige à la cible les dégâts que cause notre arme
}



void Personnage::boirePotionDeVie(int quantitePotion)
{
    cout << m_nom << " boit une potion qui lui rend " << quantitePotion << " points de vie !" << endl;
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    cout << m_nom << " change d'arme : " << nomNouvelleArme << ", infligeant " << degatsNouvelleArme << " points de dégâts." << endl;
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    return m_vie > 0;
}

void Personnage::afficherEtat() const
{
    cout << "--- PERSONNAGE " << m_nom << " ---" << endl;
    cout << "vie : " << m_vie << endl;
    cout << "mana : " << m_mana << endl;
    m_arme.afficher();
}

std::string Personnage::getNom() const
{
    return m_nom;
}
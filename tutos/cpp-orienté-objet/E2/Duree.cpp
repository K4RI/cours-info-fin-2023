#include "Duree.hpp"

using namespace std;
 
Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
}

bool Duree::estEgal(Duree const& b) const
{
    return (m_heures == b.m_heures) and (m_minutes == b.m_minutes) and (m_secondes == b.m_secondes);
}

bool Duree::estPlusPetitQue(Duree const& b) const
{
    if (m_heures < b.m_heures)
    {
        return true;
    }
    else if (m_heures > b.m_heures)
    {
        return false;
    }
    else
    {
        if (m_minutes < b.m_minutes)
        {
            return true;
        }
        else if (m_minutes > b.m_minutes)
        {
            return false;
        }
        else
        {
            return (m_secondes < b.m_secondes);
        }
    }
}

// opérateurs de comparaison
bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return not(a == b);
}

bool operator<(Duree const& a, Duree const& b)
{
    return a.estPlusPetitQue(b);
}

bool operator>(Duree const& a, Duree const& b)
{
    return not(a<b) and not(a==b);
}

bool operator<=(Duree const& a, Duree const& b)
{
    return (a<b) or (a==b);
}

bool operator>=(Duree const& a, Duree const& b)
{
    return not(a<b);
}


// l'addition, opérateur binaire
Duree& Duree::operator+=(Duree const& a)
{
    m_secondes += a.m_secondes;
    m_minutes += m_secondes/60;
    m_secondes %= 60;

    m_minutes += a.m_minutes;
    m_heures += m_minutes/60;
    m_minutes %= 60;

    m_heures += a.m_heures;

    return *this;
}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree duree(a);
    duree += b;
    return duree;
}

Duree& Duree::operator+=(int secondes)
{
    m_secondes += secondes;
    m_minutes += m_secondes/60;
    m_secondes %= 60;

    m_heures += m_minutes/60;
    m_minutes %= 60;  

    return *this;
}

Duree operator+(Duree const& a, int secondes)
{
    Duree duree(a);
    duree += secondes;
    return duree;
}

void Duree::afficher(ostream &flux) const
{
    flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s" << endl;
}

// Affichage en flux
ostream& operator<<( ostream &flux, Duree const& duree )
{
    //Affichage des attributs
    duree.afficher(flux);
    return flux;
}
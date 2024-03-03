#ifndef DEF_DUREE
#define DEF_DUREE

#include <iostream>

class Duree
{
    public:
 
        Duree(int heures = 0, int minutes = 0, int secondes = 0);
        bool estEgal(Duree const& b) const;
        bool estPlusPetitQue(Duree const& b) const;
        Duree& operator+=(Duree const& a);
        Duree& operator+=(int secondes);

    private:
    
        void afficher(std::ostream &flux) const;
 
        int m_heures;
        int m_minutes;
        int m_secondes;

    friend std::ostream& operator<<( std::ostream &flux, Duree const& duree );
    // peut accéder aux attributs privés
};

bool operator==(Duree const& a, Duree const& b);
bool operator!=(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
bool operator>(Duree const& a, Duree const& b);
bool operator<=(Duree const& a, Duree const& b);
bool operator>=(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, int secondes);

#endif
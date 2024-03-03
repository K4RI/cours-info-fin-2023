#ifndef DEF_GUERRIER
#define DEF_GUERRIER
 
#include <iostream>
#include <string>
#include "Personnage.hpp"
//Ne pas oublier d'inclure Personnage.hpp pour pouvoir en hériter !
 
class Guerrier : public Personnage
//Signifie : créer une classe Guerrier qui hérite de la classe Personnage
{
    public:
        Guerrier(std::string nom);
        void frapperAvecUnMarteau(Personnage &cible) const;
        void sePresenter() const;
};

#endif
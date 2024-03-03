#include "Vehicule.hpp"
#include <iostream>
#include <vector>

using namespace std;

void presenter(Vehicule & v)  //Présente le véhicule passé en argument
{
    v.affiche();
}

int main()
{
    // Vehicule v(5000, 2002);
    // presenter(v);
    Moto m(2000, 1967, 230);
    presenter(m);

    Vehicule *vp(0);
    vp = new Voiture(50000, 2011, 4);
    //On crée une Voiture et on met son adresse dans un pointeur de Vehicule

    vp->affiche();  //On affiche "Ceci est une voiture."

    delete vp;      //Et on détruit la voiture

    vector<Vehicule*> listeVehicules;

    listeVehicules.push_back(new Voiture(15000, 2016, 5));
    //J'ajoute à ma collection de véhicules une voiture valant 15000 euros et ayant 5 portes
    listeVehicules.push_back(new Voiture(12000, 2007, 3));  //…
    listeVehicules.push_back(new Moto(2000, 1995, 212.5));
    //Une moto à 2000 euros allant à 212.5 km/h
    listeVehicules.push_back(new Camion(35000, 2010, 35));
    
    //On utilise les voitures et les motos
    cout << "--- LE GARAGE :" << endl;
    for (int i(0); i < listeVehicules.size(); i++)
    {
        presenter(*listeVehicules[i]);
    }

    //On utilise les voitures et les motos
    for (int i(0); i < listeVehicules.size(); i++)
    {
        delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    
    cout << "--- LE NOUVEAU GARAGE :" << endl;
    Garage garage;
    garage.ajouterVehicule(m);
    Camion c(42000, 2008, 18);
    garage.ajouterVehicule(c);
    garage.afficherTous();
    
    return 0;
}
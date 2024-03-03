#include <iostream>
#include <vector>
#include "Vehicule.hpp"

using namespace std;

Vehicule::Vehicule(int prix, int annee): m_prix(prix), m_anneeFabrication(annee)
{}

void Vehicule::affiche() const
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros, fabriqué en " << m_anneeFabrication << "." << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}

Voiture::Voiture(int prix, int annee, int portes): Vehicule(prix, annee), m_portes(portes)   
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes, coutant " << m_prix << " euros, et fabriquée en " << m_anneeFabrication << "." << endl;
}

int Voiture::nbrRoues() const
{
    return 4;
}

Voiture::~Voiture()
{}


Moto::Moto(int prix, int annee, double vitesseMax): Vehicule(prix, annee), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h, coutant " << m_prix << " euros, et fabriquée en " << m_anneeFabrication << "." << endl;
}

int Moto::nbrRoues() const
{
    return 2;
}

Moto::~Moto()
{}


Camion::Camion(int prix, int annee, int chargeMax): Vehicule(prix, annee), m_charge(chargeMax)
{}

void Camion::affiche() const
{
    cout << "Ceci est un camion pouvant transporter " << m_charge << " tonnes, coutant " << m_prix << " euros, et fabriqué en " << m_anneeFabrication << "." << endl;
}

int Camion::nbrRoues() const
{
    return 6;
}

Camion::~Camion()
{}

Garage::Garage()
{
    // vector<Vehicule*> m_vehicules;
}

void Garage::ajouterVehicule(Vehicule & v)
{
    m_vehicules.push_back(&v);
}

void Garage::supprimerVehicule()
{
    m_vehicules.pop_back();
}

void Garage::afficherTous() const
{
    for (int i(0); i < m_vehicules.size(); i++)
    {
        m_vehicules[i]->affiche();
    }
}
#include "Figure.hpp"
#include <iostream>
#include <cmath>

#define PI atan(1)*4

using namespace std;

void Figure::afficher() const
{
    cout << "Je suis une figure." << endl;
}

Triangle::Triangle(double base, double hauteur): m_base(base), m_hauteur(hauteur)
{}

void Triangle::afficher() const
{
    cout << "Je suis un triangle de base " << m_base << " et de hauteur " << m_hauteur << "." << endl;
}

double Triangle::perimetre() const
{
    return 3 * m_base;
}

double Triangle::aire() const
{
    return m_base*m_hauteur/2;
}

Carre::Carre(double longueur): m_longueur(longueur)
{}

void Carre::afficher() const
{
    cout << "Je suis un carré de côté " << m_longueur << "." << endl;
}

double Carre::perimetre() const
{
    return 4 * m_longueur;
}

double Carre::aire() const
{
    return pow(2, m_longueur);
}

Rectangle::Rectangle(double longueur, double largeur): m_longueur(longueur), m_largeur(largeur)
{}

void Rectangle::afficher() const
{
    cout << "Je suis un rectangle de longueur " << m_longueur << " et de largeur " << m_largeur << "." << endl;
}

double Rectangle::perimetre() const
{
    return 2 * (m_longueur + m_largeur);
}

double Rectangle::aire() const
{
    return m_longueur * m_largeur;
}

Cercle::Cercle(double rayon): m_rayon(rayon)
{}

void Cercle::afficher() const
{
    cout << "Je suis un cercle de rayon " << m_rayon << "." << endl;
}

double Cercle::perimetre() const
{
    return 2* PI * m_rayon;
}

double Cercle::aire() const
{
    return PI * pow(2, m_rayon);
}
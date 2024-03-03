#include "Rectangle.hpp"
// #include "Rectangle.cpp"
#include <iostream>

using namespace std;

int main()
{
    Rectangle<double> rect(1.0, 4.5, 3.1, 5.2);
    cout << "Hauteur : " << rect.hauteur() << endl;
    cout << "Longueur : " << rect.longueur() << endl;
    cout << "Surface : " << rect.surface() << endl;
    cout << "Périmètre : " << rect.perimetre() << endl;
}
#include <iostream>

using namespace std;

int main()
{
    double nombre(23.77);
    double *pointeur(nullptr);
    pointeur = &nombre;
    cout << "Adresse : " << pointeur << endl;
    cout << "Valeur : " << *pointeur << endl;
    
    pointeur = new double; // on alloue une nouvelle adresse
    cout << "Adresse : " << pointeur << endl;
    *pointeur = 34.88;
    cout << "Valeur : " << *pointeur << endl;
    
    delete pointeur;
    pointeur = 0;
    
    return 0;

}
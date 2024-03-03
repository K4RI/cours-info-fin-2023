#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string prenom("Sans nom");
    int age(0);
    cout << "Âge ? ";
    cin >> age; // taper "18" comme "    18azertyuiop" marche pareil
    cin.ignore();

    cout << "Prénom ? ";
    // cin >> prenom;
    getline(cin, prenom); // récupère même les espaces

    cout << "Le prénom est " << prenom << " et l'âge est " << age << endl;

    string const motDePasse("wAsTZsaswQ"); // constantes
    double const pi(3.14);
    unsigned int const pointsDeVieMaximum(100);

    double nombre1(0), nombre2(0);
    cout << "Nombre 1 ? ";
    cin >> nombre1;
    cout << "Nombre 2 ? ";
    cin >> nombre2;
    cout << nombre1 << " + " << nombre2 << " = " << nombre1 + nombre2 << endl;

    ++age; // incrémentation
    cout << age << "^" << age << " = " << pow(age, age) << endl;

    return 0;
}
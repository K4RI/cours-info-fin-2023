#include <iostream>
#include "E6math.hpp"
using namespace std;

// Pour compiler tous les fichiers :
// g++ -o E6headers.exe E6*.cpp ; .\E6headers.exe

int main()
{
    int a(2),b(2);
    cout << "Valeur de a : " << a << endl;
    cout << "Valeur de b : " << b << endl;
    b = ajouteDeux(a); // Appel de la fonction
    cout << "Valeur de a : " << a << endl;
    cout << "Valeur de b : " << b << endl;

    cout << nombreDeSecondes(1, 10, 25) << endl;
    cout << nombreDeSecondes(1) << endl;

    return 0;
}
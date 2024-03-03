#include <complex>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <valarray>
#include <cmath>
using namespace std;

class Convertir
{
public:
    char operator()(char c) const
    {
        return toupper(c);
    }
};

int main()
{
    string chaine("Salut les developpeurs !");
    // on peut aussi employer des itérateurs sur des chaînes
    transform(chaine.begin(), chaine.end(), chaine.begin(), Convertir());
    cout << chaine << endl;

    // les itérateurs n'existant pas pour les tableaux statiques...
    int const taille = 10;
    int tab[taille] = {52, 24, 18, 71, 37, 63, 19, 96, 45};
    // ...on emploie des pointeurs.
    int *it(tab); // un sur le début
    int *fin(tab + taille); // et un sur la fin
    sort(it, fin);
    cout << "Tableau trié :" << endl;
    for (int i = 0; i < taille; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    // nombres complexes
    complex<double> a(1., 2.), b(-2, 4), c;
    // opérations mathématiques...
    c = sqrt(a+b);
    a = cos(c/b) + sin(b/c);
    cout << a << " " << b << " " << c << endl;
    // norme, conjugué
    cout << norm(conj(b)) << endl;

    // les valarray, permettant des opérations sur tout le tableau
    valarray<double> ta = {10, 20, 30, 40, 50};
    valarray<double> tb = {1, 2, 3, 4, 5};
    valarray<double> tc = exp(tb); // on somme les tableaux terme à terme
    // marche aussi avec - * / % ...
    // ...ou appliquer des fonctions de cmath ou des foncteurs !
    for (int i = 0; i < tc.size(); i++)
    {
        cout << tc[i] << " ";
    } // 11, 22, 33, 44, 55
    cout << endl;

    

    return 0;
}
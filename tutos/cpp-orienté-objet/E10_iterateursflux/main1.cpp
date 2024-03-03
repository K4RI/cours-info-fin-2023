#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

int main()
{
    // itérateur sur le flux sortant cout
    // spécifier le type (double) et le délimiteur (", ")
    ostream_iterator<double> ito(cout, ", ");
    *ito = 3.14;
    *ito = 2.71;
    cout << endl;

    // itérateur sur le flux entrant
    ifstream fichier("nombres.txt");
    istream_iterator<double> iti(fichier); // L'itérateur sur le fichier
    istream_iterator<double> end; // Le signal de fin, initialisé à null
    
    while(iti != end) // Tant qu'on n'a pas atteint la fin
    {
        *ito = *iti; // On lit et on affiche
        ++iti; // Puis on avance
    }
    cout << endl;  

    return 0;
}
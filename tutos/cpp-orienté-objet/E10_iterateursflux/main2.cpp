#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    ostream_iterator<double> ito(cout, ", ");
    ifstream fichier("nombres.txt");
    istream_iterator<double> iti(fichier); // L'itérateur sur le fichier
    istream_iterator<double> end; // Le signal de fin, initialisé à null

    vector<double> tab(10,0);
    copy(iti, end, tab.begin());
    for (int i = 0; i < tab.size(); i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
    sort(tab.begin(), tab.end());
    cout << "Vecteur trié et copié dans l'itérateur cout : " << endl;
    copy(tab.begin(), tab.end(), ito);
}
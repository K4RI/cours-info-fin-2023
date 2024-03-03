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

    vector<double> tab; // tableau VIDE
    
    back_insert_iterator<vector<double> > it2(tab);
    // L'algorithme ajoute les cases nécessaires au tableau
    copy(iti, end, it2);
    copy(tab.begin(), tab.end(), ito);

    // cout << *min_element(istream_iterator<double>(fichier), istream_iterator<double>())<< endl;
    // affiche le plus petit élément
};
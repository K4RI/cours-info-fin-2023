#include "Duree.hpp"

using namespace std;

int main()
{
    Duree duree1(0, 10, 28), duree2(0, 15, 2);
    cout << duree1;
    cout << duree2;

    if (duree1 == duree2)
    {
        cout << "Valeurs égales." << endl;
    }
    else
    {
        cout << "Valeurs non-égales." << endl;
    }

    if (duree1 != duree2)
    {
        cout << "Valeurs différentes." << endl;
    }
    else
    {
        cout << "Valeurs non-différentes." << endl;
    }

    if (duree1 < duree2)
    {
        cout << "duree1 plus petite que duree2." << endl;
    }
    else
    {
        cout << "duree1 pas plus petite que duree2." << endl;
    }
    
    cout << duree1 + duree2;
    duree1+=duree2;
    cout << duree1;
    cout << (duree1 + 3600);
 
    return 0;
}
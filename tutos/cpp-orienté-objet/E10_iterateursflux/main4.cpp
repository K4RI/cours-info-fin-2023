#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int main()
{
    // flux SORTANT
    ostringstream fluxo;   //Un flux permettant d'écrire dans une chaîne
    fluxo << "Salut les";  //On écrit dans le flux grâce à l'opérateur <<
    fluxo << " developpeurs";
    fluxo << " !";
    string const chaine = fluxo.str(); //On récupère la chaîne
    cout << chaine << endl;  //Affiche 'Salut les developpeurs !'

    double const pi(3.1415);
    ostringstream fluxxo;
    fluxxo << "Le nombre pi vaut: ";
    fluxxo << pi;
    cout << fluxxo.str() << endl;


    // flux ENTRANT
    istringstream fluxi;
    fluxi.str("34.2 64 1.33");
    double val;
    while (fluxi >> val)
    {
        cout << "Valeur lue : " << val << endl;
    }

    return 0;
}
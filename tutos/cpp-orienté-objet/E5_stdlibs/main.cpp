#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include "main.hpp"

#define PI atan(1) * 4

using namespace std;

int main()
{
    // la bibliothèque cmath
    double a = pow(5, 3);
    cout << "Cinq puissance trois égal " << a << endl;
    double b = sqrt(a);
    cout << "et sa racine vaut " << b << endl;
    cout << "Le cosinus de pi vaut " << cos(PI) << endl;
    cout << "Et pi vaut " << (((((PI - 3.14159) * pow(10, 6) - 2.65358) * pow(10, 6) - 9.79323) * pow(10, 6) - 3.3797) * pow(10, 5) - 9.56522) * pow(10, 6) - 3.63391 << endl;
    // précision à la 30ème décimale

    // la bibliothèque cctype
    TypeSymbole('u');
    TypeSymbole('A');
    TypeSymbole('7');
    TypeSymbole(' ');

    string phrase = "Bonjour c'est la phrase hihi";
    phrase = SpacesToSharps(phrase);    
    cout << phrase << endl;
    // TODO : modifier la chaîne dans la void fonction

    // la bibliothèque ctime    
    int secondes = time(0);
    cout << "Il s'est ecoule " << secondes << " secondes depuis le 01/01/1970." << endl;

    // la bibliothèque cstdlib    
    srand(time(0));    //On initialise la suite de nombres aléatoires
    for(int i(0); i<10; ++i) 
        cout << rand() % 10 << endl;  //On génère des nombres au hasard

    return 0;
}



void TypeSymbole(char symbole)
{
    cout << "Le symbole est " << symbole << " ; ";

    if(isdigit(symbole))
        cout << "c'est un chiffre." << endl;
    else
    {
        cout << "ce n'est pas un chiffre ";
        if (isalpha(symbole))
        {
            cout << "mais une lettre ";
            if (isupper(symbole))
            {
                cout << "majuscule,";
                cout << "dont la minuscule est " << char(tolower(symbole)) << "." << endl;
            }
                
            else
            {
                cout << "minuscule,";
                cout << "dont la majuscule est " << char(toupper(symbole)) << "." << endl;
            }
        }
        else if (isspace(symbole))
            cout << "mais un espace." << endl;
    };
};

string SpacesToSharps(string phrase)
{   
    for (int i(0); i < phrase.size(); i++)
    {
        if (isspace(phrase[i]))
            phrase[i] = '#';
    }
    return phrase;
}
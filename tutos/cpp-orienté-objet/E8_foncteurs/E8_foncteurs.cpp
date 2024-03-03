#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Addition{
public:
    
    int operator()(int a, int b)   //La surcharge de l'opérateur ()
    {
        return a+b;
    }
};


class Ajout{
public:
    
    int operator()(int a)   //La surcharge de l'opérateur ()
    {
        if(a%2 == 0)
            return a+5;
        else
            return a;
    }
};


class Remplir{
public:
    Remplir(int i)
        :m_valeur(i)
    {}

    int operator()()
    {
        ++m_valeur;
        return m_valeur;
    }
private:
    int m_valeur;
};


class TestVoyelles
{
public:
    bool operator()(string const& chaine) const
    {
        for(int i(0); i<chaine.size(); ++i)
        {
            switch (chaine[i])   //On teste les lettres une à une
            {
                case 'a':        //Si c'est une voyelle
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    return true;  //On renvoie 'true'
                default:
                    break;        //Sinon, on continue
            }
        }
        return false;   //Si on arrive là, c'est qu'il n'y avait pas de  voyelle du tout
    }
};


class CompareLongueur
{
public:
    bool operator()(const string& a, const string& b)
    {
        return a.length() < b.length();
    }
};



int main()
{
    plus<int> foncteur;
    // il existe des prédéfinis, comme "plus<int> foncteur" ;
    int a(2), b(3);
    cout << a << " + " << b << " = " << foncteur(a,b) << endl; //On utilise le foncteur comme s'il s'agissait d'une fonction

    // +5 si pair, +0 sinon
    Ajout foncteur2;
    cout << a << " -> " << foncteur2(a) << endl;
    cout << b << " -> " << foncteur2(b) << endl;

    vector<int> tab(100, 0); //Un tableau de 100 cases valant toutes 0
    Remplir f(0);       
    for(vector<int>::iterator it=tab.begin(); it!=tab.end(); ++it)
    {
        *it = f(); //On appelle simplement le foncteur sur chacun des éléments du tableau
    } // ça remplit les cases de 1 à 100

    // par défaut, map<string, double> range les string par ordre lexicographique.
    // en entrant un foncteur en troisième paramètre (ici CompareLongueur)...
            // ...l'ordre se fera différemment (ici par longueur du string)
    map<string, double, CompareLongueur> poids;  //On utilise le foncteur comme critère de comparaison    
    poids["souris"] = 0.05;
    poids["tigre"] = 200;
    poids["chat"] = 3;
    poids["elephant"] = 10000;
    //Et on parcourt la table en affichant le nom et le poids
    for(map<string, double>::iterator it=poids.begin(); it!=poids.end(); ++it)
    {
        cout << it->first << " pese " << it->second << " kg." << endl;
    } // "chat, tigre, souris, éléphant" au lieu de "chat, éléphant, souris, tigre"

    return 0;
}
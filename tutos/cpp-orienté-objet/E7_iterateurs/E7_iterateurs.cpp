#include <iostream>
#include <deque>
#include <map>
#include <set>
using namespace std;

int main()
{
    deque<int> d(5,6); // deque de 5 éléments valant 6
    deque<int>::iterator it; // itérateur sur une deque d'entiers
    //Et on itère sur la deque
    for(it = d.begin(); it!=d.end(); ++it) // ou "it != d.begin()+2" si on veut que les 2ères cases
    {
        cout << *it << endl; // On accède à l'élément pointé via l'étoile
    }


    //Une table qui associe le nom d'un animal à son poids
    map<string, double> poids;
    poids["souris"] = 0.05;
    poids["tigre"] = 200;
    poids["chat"] = 3;
    poids["elephant"] = 10000;
    //Et on parcourt la table en affichant le nom et le poids
    for(map<string, double>::iterator it=poids.begin(); it!=poids.end(); ++it)
    {
        cout << it->first << " pese " << it->second << " kg." << endl;
    }    

    map<string, double>::iterator trouve = poids.find("chien");
    if(trouve == poids.end())
    {
        cout << "Le poids du chien n'est pas dans la table" << endl;
    }
    else
    {
        cout << "Le chien pese " << trouve->second << " kg." << endl;
    }
    
    // les ensembles set
    set<int> ensemble;
    ensemble.insert(33);
    ensemble.insert(44);
    ensemble.insert(55);
    cout << "Taille de l'ensemble : " << ensemble.size() << endl;
    ensemble.erase(44);
    cout << "Taille de l'ensemble : " << ensemble.size() << endl;
    for (set<int>::iterator it=ensemble.begin(); it != ensemble.end(); ++it)
    {
        cout << "Element : " << *it << endl;
    }
    
    // les multi-ensembles multiset
    multiset<int> mes;
    mes.insert(33);
    mes.insert(44);
    mes.insert(55);
    mes.insert(44);
    mes.insert(33);
    cout << "Taille du multiensemble : " << mes.size() << endl;
    mes.erase(33);
    cout << "Taille du multiensemble : " << mes.size() << endl;
    for (multiset<int>::iterator it=mes.begin(); it != mes.end(); ++it)
    {
        cout << "Element : " << *it << endl;
    }

    return 0;
}
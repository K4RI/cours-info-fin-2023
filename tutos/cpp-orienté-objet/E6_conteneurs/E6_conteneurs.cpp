#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <map>
#include "E6_conteneurs.hpp"

using namespace std;

int main()
{
    // vector
    vector<int> vec(5,4);
    vec.pop_back();
    vec.push_back(6);
    AfficheVecteur(vec);

    // méthode empty(), renvoie si le conteneur est vide ou non
    if(vec.empty())
        cout << "La liste est vide." << endl;
    else
        cout << "La liste n'est pas vide." << endl;

    // méthode clear(), vide le conteneur
    vec.clear();

    // méthode swap(), échange deux conteneurs
    vec = {2, 4, 5};
    vector<int> vec2 = {12, 27, 14};
    vec.swap(vec2);
    AfficheVecteur(vec);
    AfficheVecteur(vec2);

    // deque = double-ended queue
    deque<int> d(4,5); // quatre entiers valant 5    
    d.push_front(2);   // on ajoute le nombre 2 au début
    d.push_back(8);    // et le nombre 8 à la fin
    AfficheDeque(d); // 2 5 5 5 8

    // stack = pile LIFO
    stack<int> pile;
    pile.push(3); // On ajoute le nombre 3 à la pile
    pile.push(4);
    pile.push(5);
    cout << pile.top() << endl; // On consulte le sommet de la pile (le nombre 5)
    pile.pop(); // On supprime le dernier élément ajouté (le nombre 5)
    cout << pile.top() << endl; //On consulte le sommet de la pile (le nombre 4)

    // queue = file FIFO
    queue<int> file;
    file.push(6);
    file.push(7);
    file.push(8);
    cout << file.front() << endl; // le premier élément (6)
    file.pop(); // que l'on retire
    cout << file.front() << endl; // le nouveau premier élément (7)

    // priority queue = file prioritaire
    priority_queue<int> pfile;
    pfile.push(5);
    pfile.push(8);
    pfile.push(3);
    cout << pfile.top() << endl;  // Affiche le plus grand des éléments insérés (le nombre 8)


    // map = table associative ou dictionnaire
    map<string, int> table;
    table["salut"] = 3; // La case "salut" de la map vaut maintenant 3

    ifstream fichier("texte.txt");
    string mot;
    map<string, int> occurrences;
    while(fichier >> mot)   // On lit le fichier mot par mot
    {
         ++occurrences[mot]; // On incrémente le compteur pour le mot lu
    }
    cout << "Le mot 'banane' existe " << occurrences["banane"] << " fois dans le fichier" << endl; 
    
    return 0;
}


void AfficheVecteur(vector<int> vec)
{
    for(int i(0); i<vec.size(); ++i)
        cout << vec[i] << ", ";
    cout << endl;
}

void AfficheDeque(deque<int> deq)
{
    for(int i(0); i<deq.size(); ++i)
        cout << deq[i] << ", ";
    cout << endl;
}
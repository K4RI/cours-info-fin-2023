#include <iostream>
#include <fstream>
#include <cstdlib> //pour rand()                                                     
#include <ctime>   //pour time()                                                   
#include <deque>                                                  
#include <vector>
#include <algorithm>
using namespace std;

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

class Generer
{
public:
    int operator()() const
    {
        return rand() % 10;  //On renvoie un nombre entre 0 et 9
    }
};

class GenererChar
{
public:
    int operator()() const
    {
        return 'a' + rand()%26;
    }
};

class TestVoyelles
{
public:
    bool operator()(string const& chaine) const
    {
        for(int i(0); i<chaine.size(); ++i)
        {
            switch (chaine[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    return true;
                default:
                    break;
            }
        }
        return false;
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

class AfficherInt
{
public:
    void operator()(int a) const
    {
        cout << a << endl;
    }
};

class AfficherChar
{
public:
    void operator()(char a) const
    {
        cout << a << endl;
    }
};

class AfficherString
{
public:
    void operator()(string a) const
    {
        cout << a << " ";
    };
};

class Sommer
{
public:
    Sommer()
        :m_somme(0)
    {}
    void operator()(int n)
    {
        m_somme += n;
    }
    int resultat() const
    {
        return m_somme;
    }
private:
    int m_somme;
};

double moyenneVecteur(vector<int> const& tableau)
{
    Sommer s;
    s = for_each(tableau.begin(), tableau.end(), s);
    double moyenne = s.resultat();
    moyenne /= tableau.size();
    return moyenne;
}

int main()
{ 
    vector<int> tab(20,0); //Un tableau de 100 cases valant toutes 0
    Remplir f(0);       

    // generate
    //On applique f à tout ce qui se trouve entre begin() et end()
    generate(tab.begin(), tab.begin() + 10, f);
    generate(tab.end() - 5, tab.end(), f);
    // 1 2 3 4 5 6 7 8 9 10 ....... 1 2 3 4 5
    for_each(tab.begin(), tab.end(), AfficherInt());
    cout << endl;
    
    srand(time(0));
    vector<int> nombres(10, 0);
    Generer g;
    generate(nombres.begin(), nombres.end(), g);
    for_each(nombres.begin(), nombres.end(), AfficherInt());
    cout << endl;
    int nombre = count(nombres.begin(), nombres.end(), 2);
    cout << "Il y a " << nombre << " éléments valant 2." << endl;

    vector<string> tableau;
    ifstream monFlux("..\\E6_conteneurs\\texte.txt");
    string mot;
    if(monFlux)
    {
        while (monFlux >> mot)
            tableau.push_back(mot);        
        int const compteur = count_if(tableau.begin(), tableau.end(), TestVoyelles());
        cout << "Il y a " << compteur << " mots contenant des voyelles dans le fichier." << endl;
    }
    else
    {
        return -1;
    }
    
    srand(time(0));
    deque<char> lettres(10, 0);
    GenererChar h;
    generate(lettres.begin(), lettres.end(), h);
    for_each(lettres.begin(), lettres.end(), AfficherChar());
    cout << endl;
    deque<char>::iterator trouve = find(lettres.begin(), lettres.end(), 'a');
    if(trouve == lettres.end())
        cout << "La lettre 'a' n'a pas ete trouvee" << endl;
    else
        cout << "La lettre 'a' a ete trouvee" << endl;
    
    // les itérateurs min_element et max_element
    deque<char>::iterator mini = min_element(lettres.begin(), lettres.end());
    cout << "L'élément minimum est " << *mini << " d'indice [" << distance(lettres.begin(), mini) << "]" << endl;
    deque<char>::iterator maxi = max_element(lettres.begin(), lettres.end());
    cout << "L'élément maximum est " << *maxi << " d'indice [" << distance(lettres.begin(), maxi) << "]" << endl;

    // tri avec sort
    sort(lettres.begin(), lettres.end());
    for_each(lettres.begin(), lettres.end(), AfficherChar());
    cout << endl;

    // tri avec sort et un autre foncteur
    sort(tableau.begin(), tableau.end(), CompareLongueur());
    for_each(tableau.begin(), tableau.end(), AfficherString());
    cout << endl;

    Sommer j;
    j = for_each(nombres.begin(), nombres.end(), j);
    cout << "La somme vaut " << j.resultat() << endl;
    cout << "Sa moyenne vaut " << moyenneVecteur(nombres) << endl;

    // transform(tab1, tab1, tab2, tab3, foncteurf)
    // remplir dans tab3 les f(elt1, elt2)
    vector<int> a(10, 0);
    vector<int> b(10, 0);
    vector<int> c(10, 0);
    // on remplit
    generate(a.begin(), a.end(), g);
    generate(b.begin(), b.end(), g);
    generate(c.begin(), c.end(), g);
    transform(a.begin(), a.end(), b.begin(), c.begin(), plus<int>());
    // À partir d'ici les cases de 'c' contiennent la somme des cases de 'a' et 'b'
    for (int i(0); i < a.size(); i++)
    {
        cout << a[i] << " et " << b[i] << " donnent " << c[i] << endl;
    }

    return 0;
}
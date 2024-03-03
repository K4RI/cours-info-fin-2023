#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <cassert>
using namespace std;
 
class Erreur: public exception
{
public:
    Erreur(int numero=0, string const& phrase="", int niveau=0) throw()
         :m_numero(numero),m_phrase(phrase),m_niveau(niveau)
    {}
 
     virtual const char* what() const throw()
     {
         return m_phrase.c_str();
     }
     
     int getNiveau() const throw()
     {
          return m_niveau;
     }
    
    virtual ~Erreur() throw()
    {}
 
private:
    int m_numero;               //Numéro de l'erreur
    string m_phrase;            //Description de l'erreur
    int m_niveau;               //Niveau de l'erreur
};


int division(int a,int b) // Calcule a divisé par b.
{
   if(b==0)
      throw Erreur(1,"Division par zéro !",2);
      // throw domain_error("Division par zéro"); pour une déjà built-in
   else
      return a/b;
}
 
int main()
{
    try
    {
        vector<int> a(100000000000,1); //Un tableau bien trop grand
    }
    catch(exception const& e) //On rattrape les exceptions standard de tous types
    {
        cerr << "ERREUR : " << e.what() << endl; //On affiche la description de l'erreur
    } // std::bad_alloc

    
    vector<double> tab(5, 3.14);  //Un tableau de 5 nombres décimaux
    try
    {
        tab.at(8) = 4.;  //On essaye de modifier la 8ème case
    }
    catch(exception const& e)
    {
        cerr << "ERREUR : " << e.what() << endl;
    } // vector::_M_range_check: __n (which is 8) >= this->size() (which is 5)

    int a,b;
    cout << "Valeur pour a : ";
    cin >> a;
    cout << "Valeur pour b : ";
    cin >> b; 
    assert (b != 0); // stoppe le programme si faux
    cout << a << " / " << b << " = " << division(a,b) << endl;

    return 0;
}
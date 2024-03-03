#include <iostream>
using namespace std;

int division(int a,int b) // Calcule a divisé par b.
{
   if(b==0)
      throw string("ERREUR : Division par zéro !");
   else
      return a/b;
}
 
int main()
{
    int a,b;
    cout << "Valeur pour a : ";
    cin >> a;
    cout << "Valeur pour b : ";
    cin >> b;
 
    try
    {
        cout << a << " / " << b << " = " << division(a,b) << endl;
    }
    catch(string const& chaine)
    {
        cerr << chaine << endl;
    }
    return 0;
}
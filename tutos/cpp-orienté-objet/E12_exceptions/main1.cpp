#include <iostream>
using namespace std;

int division(int a,int b)
{
    try
    {
        if(b == 0)
           throw string("ERREUR : Division par zéro !");
        else
           return a/b;
   }
   catch(string const& chaine)
   {
       cerr << chaine << endl;
   }
}

int main()
{
   int a,b;
   cout << "Valeur pour a : ";
   cin >> a;
   cout << "Valeur pour b : ";
   cin >> b;
 
   cout << a << " / " << b << " = " << division(a,b) << endl;
   
   return 0;
}
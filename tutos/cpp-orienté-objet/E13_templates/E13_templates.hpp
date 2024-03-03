#ifndef E13_TEMPLATES
#define E13_TEMPLATES
#include <ctime>

template <typename T>
T maximum(const T& a,const T& b)
{
   if(a>b)
      return a;
   else
      return b;
}

template<typename T, typename S>
S moyenne(T tableau[], int taille)
{ 
   S somme(0); //La somme des éléments du tableau
   for(int i(0); i<taille; ++i)
      somme += tableau[i];

   return somme/taille;
}

template <typename T>
T minimum(const T& a,const T& b)
{
   if(a<b)
      return a;
   else
      return b;
}

template<typename T, typename S>
S moyenne(std::vector<T> v)
{ 
   S somme(0);
   for(int i(0); i < v.size(); ++i)
      somme += v[i];
   return somme/v.size();
};

template<typename T>
T aleat()
{ 
    srand(time(0)); // On initialise la suite de nombres aléatoires
    return rand() % 10;   
   // return 'a' + rand()%26;
};

template <>
std::string maximum<std::string>(const std::string& a, const std::string& b)
{
  if(a.size()>b.size())
    return a;
  else
    return b;
}

#endif
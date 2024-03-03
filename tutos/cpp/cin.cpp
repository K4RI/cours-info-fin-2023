#include <iostream>  
#include <limits> 
  
bool read_choice( int & N ) 
{ 
    std::cout << "Entrez un chiffre entre 1 et 6 : " ;  
    while ( ! ( std::cin >> N ) || N < 1 || N > 6 ) 
    {  
        if ( std::cin.eof() ) 
        {  
            // ^D  (^Z sous windows); Fin du flux d'entree ! 
            return false;  
        } 
        else if ( std::cin.fail() ) 
        {  
            std::cout << "Saisie incorrecte, recommencez : ";  
            std::cin.clear();  
            std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' ); 
        } 
        else 
        { 
            std::cout << "Le chiffre n'est pas entre 1 et 6, recommencez : "; 
        } 
    } 
    return true; // succès 
} 
  
int main ()  
{  
    int choix; 
    if ( read_choice( choix ) ) 
    { 
        std::cout << "Vous avez choisi : " << choix << '\n'; 
    } 
  
    return 0;  
}
#include <iostream>

using namespace std;

int main()
{
    int nbAnimaux(0);
    cout << "Combien avez-vous d'animaux de compagnie ? ";
    cin >> nbAnimaux;
    
    switch (nbAnimaux)
    {
        case 0:
            cout << "Vous n'avez pas d'animaux de compagnie" << endl;
            break;

        case 1:
            cout << "C'est super d'avoir un fidele compagnon !" << endl;
            break;

        default:
            cout << "Votre budget croquettes doit etre important" << endl;
            break;
    }

    int age(0);
    cout << "Quel âge ? ";
    cin >> age;
    if (age > 18 && (not false))
    {
        cout << "Oh le vieux" << endl;
    }
    else
    {
        cout << "Oh le bébé" << endl;
    }

    cout << "Fin du programme" << endl;

    return 0;
}
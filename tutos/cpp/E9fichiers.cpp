#include <iostream>
#include <fstream>

using namespace std;


int tailleFichier(string nomFichier)
{
    ifstream monFlux(nomFichier.c_str());  //Ouverture d'un fichier en lecture
    if(monFlux)
    {
        monFlux.seekg(0, ios::end);
        return monFlux.tellg();
    }
    else
    {
        return -1;
    }
}


int main()
{
    string const nomFichier("E9.txt");
    ofstream monFluxW(nomFichier.c_str()); // c_str change un string en char* ? obsolète ?
    //Déclaration d'un flux permettant d'écrire dans le fichier

    if(monFluxW)  //On teste si tout est OK
    {
        //Tout est OK, on peut utiliser le fichier
        int nombre(277);
        monFluxW << nombre << endl;

        monFluxW << "Bonjour, je suis une phrase écrite dans le fichier." << endl;
        monFluxW << "Une autre phrase." << endl;
        monFluxW << "Encore une autre phrase." << endl;      

        monFluxW.close();
        // On referme le fichier, on ne peut plus écrire dedans.
        // Facultatif. Il se ferme auto à la fin d'un bloc.
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }


    ifstream monFluxR(nomFichier.c_str());  //Ouverture d'un fichier en lecture
    if(monFluxR)
    {
        //Tout est prêt pour la lecture.
        double nombre;
        int position;
        monFluxR >> nombre; // on lit un mot
        cout << "Nombre lu : " << nombre << endl;

        monFluxR.ignore(); // on change de mode "<<" à "getline()"

        string ligne;
        getline(monFluxR, ligne); // on lit une ligne complète
        cout << "Ligne lue : \"" << ligne << "\"" << endl;

        while(getline(monFluxR, ligne)) // Tant qu'on n'est pas à la fin, on lit
            {
                int position = monFluxR.tellg(); //On récupère la position
                cout << "Nous arrivons au " << position << "eme caractere du fichier." << endl;
                cout << "Ligne lue : \"" << ligne << "\"" << endl;
                // ou on fait quelque chose avec cette ligne
            }
        }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    // monFlux.tell() : donne la position du curseur
    // monFlux.seek(n, pos) : déplace le curseur à n positions de
    //                  ios::beg, ios::end, ios::cur

    cout << "La taille du fichier est : " << tailleFichier(nomFichier) << " octets." << endl;

    return 0;
}
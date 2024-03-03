#include <iostream>

using namespace std;
#include <string>

int main()
{
    cout << "Hello world!" << endl;
    cout << "\"" << endl;
    cout << "\\" << endl;

    int ageUtilisateur(16);
    int nombreAmis(432);
    double pi(3.14159);
    bool estMonAmi(true);
    char lettre('a');
    string nomUtilisateur("Albert Einstein");

    int& ageAlias(ageUtilisateur);
    cout << "age = " << ageUtilisateur << endl;
    cout << "age = " << ageAlias << endl;


    return 0;
}
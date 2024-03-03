#include <iostream>

using namespace std;

int main()
{
    int age(-1);
    while(age <= 0){
        cout << "Âge ? ";
        cin >> age;
        cin.ignore();
    }
    cout << "L'âge est " << age << " ans." << endl;

    int n(0);
    for (n = 0; n < 10; n++)
    {
        cout << n << endl;
    }

    return 0;
}


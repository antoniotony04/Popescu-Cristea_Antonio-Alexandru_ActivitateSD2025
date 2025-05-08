/*
    Cerinta:
    Scrie un program C++ care defineste o structura Student cu urmatoarele campuri:
        nume (sir de caractere),
        varsta (int),
        medie (float).
        Programul trebuie sa:
        Citeasca datele a n studenti de la tastatura.
        Stocheze datele intr-un vector de structuri.
        Afiseze studentii care au media mai mare sau egala cu 8.00.
*/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string nume;
    int varsta;
    float medie;
};

int main() {
    int n;
    cout << "Introdu numarul de studenti: ";
    cin >> n;

    Student studenti[100];

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Nume: ";
        cin >> studenti[i].nume;
        cout << "Varsta: ";
        cin >> studenti[i].varsta;
        cout << "Medie: ";
        cin >> studenti[i].medie;
    }

    cout << "\nStudenti cu media >= 8.00:\n";
    for (int i = 0; i < n; i++) {
        if (studenti[i].medie >= 8.0) {
            cout << studenti[i].nume << ", " << studenti[i].varsta << " ani, Media: " << studenti[i].medie << endl;
        }
    }

    return 0;
}

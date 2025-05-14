/*
Se cere sa se implementeze o lista simplu inlantuita care pastreaza numere intregi. Programul trebuie sa permita urmatoarele operatii:
1. Adaugarea unui element la sfarsitul listei.
2. Afisarea tuturor elementelor din lista.
3. Stergerea unui element dat din lista (prima aparitie).
4. Eliberarea memoriei alocate dinamic.
*/


#include <iostream>
using namespace std;

// Structura nodului listei
struct Nod {
    int valoare;
    Nod* urmator;
};

// Functie pentru adaugarea unui nod la finalul listei
void adaugaLaFinal(Nod*& cap, int valoare) {
    Nod* nou = new Nod{valoare, nullptr};
    if (!cap) {
        cap = nou;
    } else {
        Nod* temp = cap;
        while (temp->urmator) {
            temp = temp->urmator;
        }
        temp->urmator = nou;
    }
}

// Functie pentru afisarea listei
void afiseazaLista(Nod* cap) {
    if (!cap) {
        cout << "Lista este goala.\n";
        return;
    }
    cout << "Elementele listei: ";
    while (cap) {
        cout << cap->valoare << " ";
        cap = cap->urmator;
    }
    cout << endl;
}

// Functie pentru stergerea primei aparitii a unui element
void stergeElement(Nod*& cap, int valoare) {
    if (!cap) return;
    if (cap->valoare == valoare) {
        Nod* deSters = cap;
        cap = cap->urmator;
        delete deSters;
        return;
    }
    Nod* curent = cap;
    while (curent->urmator && curent->urmator->valoare != valoare) {
        curent = curent->urmator;
    }
    if (curent->urmator) {
        Nod* deSters = curent->urmator;
        curent->urmator = curent->urmator->urmator;
        delete deSters;
    }
}

// Functie pentru eliberarea memoriei
void elibereazaLista(Nod*& cap) {
    while (cap) {
        Nod* temp = cap;
        cap = cap->urmator;
        delete temp;
    }
}

int main() {
    Nod* lista = nullptr;
    int optiune, valoare;

    do {
        cout << "\n1. Adauga element\n2. Afiseaza lista\n3. Sterge element\n4. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                cout << "Valoare de adaugat: ";
                cin >> valoare;
                adaugaLaFinal(lista, valoare);
                break;
            case 2:
                afiseazaLista(lista);
                break;
            case 3:
                cout << "Valoare de sters: ";
                cin >> valoare;
                stergeElement(lista, valoare);
                break;
            case 4:
                elibereazaLista(lista);
                cout << "Program terminat.\n";
                break;
            default:
                cout << "Optiune invalida.\n";
        }
    } while (optiune != 4);

    return 0;
}

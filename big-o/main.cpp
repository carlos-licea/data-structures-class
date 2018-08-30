#include <iostream>
#include <stdio.h>

using namespace std;

bool contains(int arreglo[], int tamano, int elemento) {
    for(int i = 0; i < tamano; ++i) {
        if(arreglo[i] == elemento) {
            return true;
        }
    }
    return false;
}

void pairUp(int a1[], int tamano, int a2[], int tamano2) {
    for(int i = 0; i < tamano; ++i) {
        for(int j = 0; j < tamano2; ++j) {
            printf("{%i,%i}", a1[i], a2[j]);
        }
    }
}

int intersectCount(int a1[], int tamano, int a2[], int tamano2) {
    int interesect = 0;

    for(int i = 0; i < tamano; ++i) {
        for(int j = 0; j < tamano2; ++j) {
            if(a1[i] == a2[j]) {
                interesect++;
            }
        }
    }

    return interesect;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    int b[] = {1, 2};

    cout << "Resultado:" << intersectCount(a, 4, b, 2) << endl;

    return 0;
}

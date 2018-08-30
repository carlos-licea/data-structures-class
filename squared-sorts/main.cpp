#include <iostream>

#include <stdio.h>

using namespace std;

void swap(int& a, int& b) {
    int temporal = a;
    a = b;
    b = temporal;
}

void bubblesort(int arreglo[], int tamano) {
    bool huboCambio = false;
    do {
        huboCambio = false;

        for(int i = 0; i < tamano-1; ++i) {
            if(arreglo[i] > arreglo[i+1]) {
                swap(arreglo[i], arreglo[i+1]);
                huboCambio = true;
            }
        }
    } while(huboCambio);
}

void coctailsort(int arreglo[], int tamano) {
    bool huboCambio = false;
    int inicio = 0;
    int fin = tamano;
    do {
        huboCambio = false;

        for(int i = inicio; i < fin-1; ++i) {
            if(arreglo[i] > arreglo[i+1]) {
                swap(arreglo[i], arreglo[i+1]);
                huboCambio = true;
            }
        }
        for(int i = fin-1; i > inicio; --i) {
            if(arreglo[i] > arreglo[i-1]) {
                swap(arreglo[i], arreglo[i-1]);
                huboCambio = true;
            }
        }
        inicio++;
        fin--;
    } while(huboCambio);
}

void bubblesort_mejorado(int arreglo[], int tamano) {
    bool huboCambio = false;
    int fin = tamano;
    do {
        huboCambio = false;

        for(int i = 0; i < fin-1; ++i) {
            if(arreglo[i] > arreglo[i+1]) {
                swap(arreglo[i], arreglo[i+1]);
                huboCambio = true;
            }
        }
        fin -= 1;
    } while(huboCambio);
}

void imprime(int arreglo[], int tamano) {
    for(int i = 0; i < tamano; ++i) {
        printf("%d,", arreglo[i]);
        // cout << arreglo[i] << ",";
    }
    printf("\n");
}

void selectionsort(int arreglo[], int tamano) {

    for(int i = 0; i < tamano; ++i) {
        int minimo = i;
        for(int j = i+1; j < tamano; ++j) {
            if(arreglo[j] < arreglo[minimo]) {
                minimo = j;
            }
        }
        swap(arreglo[i], arreglo[minimo]);
    }
}

void insertionshort(int arreglo[], int tamano) {
    for(int i = 1; i < tamano; ++i) {
        int actual = i;
        while(actual >= 1 && arreglo[actual] < arreglo[actual-1]) {
            swap(arreglo[actual], arreglo[actual-1]);
            --actual;
        }
    }
}

int main()
{
    int arreglo[] = {10, 8, 11, 3, 5, 2};
    int tamano = 6;
    imprime(arreglo, tamano);
    insertionshort(arreglo, tamano);
    imprime(arreglo, tamano);
    return 0;
}

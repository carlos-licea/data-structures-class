#include <iostream>
#include <stdio.h>

using namespace std;

void merge(int a[], int inicio, int division, int fin) {
    int n1 = division - inicio + 1;
    int n2 = fin - division;

    //arreglos temporales
    int t1[n1];
    for (int i = 0; i < n1; ++i) {
        t1[i] = a[inicio+i];
    }
    int t2[n2];
    for (int i = 0; i < n2; ++i) {
        t2[i] = a[division+1 + i];
    }

    int indiceT1 = 0;
    int indiceT2 = 0;
    int indiceSalida = inicio;

    while(indiceT1 < n1 && indiceT2 < n2) {
        if(t1[indiceT1] <= t2[indiceT2]) {
            a[indiceSalida] = t1[indiceT1];
            indiceT1++;
            indiceSalida++;
        } else {
            a[indiceSalida] = t2[indiceT2];
            indiceT2++;
            indiceSalida++;
        }
    }

    while(indiceT1 < n1) {
        a[indiceSalida] = t1[indiceT1];
        indiceT1++;
        indiceSalida++;
    }

    while(indiceT2 < n2) {
        a[indiceSalida] = t2[indiceT2];
        indiceT2++;
        indiceSalida++;
    }
}

void mergesort(int* a, int inicio, int fin) {
    if((fin - inicio+1) <= 1) {
        return;
    }

    int pivote = inicio + (fin - inicio) / 2;
    mergesort(a, inicio, pivote);
    mergesort(a, pivote+1, fin);
    merge(a, inicio, pivote, fin);
}

void imprime(int arreglo[], int tamano) {
    for(int i = 0; i < tamano; ++i) {
        printf("%d,", arreglo[i]);
        // cout << arreglo[i] << ",";
    }
    printf("\n");
}

int main()
{
    int arreglo[] = {10, 8, 11, 3, 5, 2};
    int tamano = 6;
    imprime(arreglo, tamano);
    mergesort(arreglo, 0, tamano-1);
    mergesort(arreglo, 0, tamano-1);
    imprime(arreglo, tamano);

    return 0;
}

#include <iostream>
#include <stdio.h>

using namespace std;

int busquedaDesordenada(int arreglo[], int tamano, int buscado, int desde = 0) {
    printf("busquedaDesordenada");
    for(int i = desde; i < tamano; ++i) {
        printf("comparando %i %i\n", i, arreglo[i]);
        if(arreglo[i] == buscado) {
            return i;
        }
    }
    return -1;
}

int busquedaOrdenada(int arreglo[], int tamano, int buscado, int desde = 0) {
    printf("busquedaOrdenada");
    for(int i = desde; i < tamano; ++i) {
        printf("comparando %i %i\n", i, arreglo[i]);
        if(arreglo[i] == buscado) {
            return i;
        } else if(arreglo[i] > buscado) {
            return -1;
        }

    }
    return -1;
}

int busquedaBinaria(int arreglo[], int principio, int fin, int buscado) {
    printf("busquedaBinaria inicio %i fin %i\n", principio, fin);
    if(principio > fin) {
        return -1;
    }

    int pivote = (principio + fin) / 2;
    if(arreglo[pivote] == buscado) {
        return pivote;
    }

    if(arreglo[pivote] > buscado) {
        return busquedaBinaria(arreglo, principio, pivote-1, buscado);
    }

    return busquedaBinaria(arreglo, pivote+1, fin, buscado);
}

int main()
{

    int desordenado[] = {9,2,1,4,4,8,15};
    int ordenado[] = {1,2,4,4,8,9,15};

    int tamano = 7;
    int posicion = busquedaOrdenada(ordenado, tamano, 1);
    int posicion2 = busquedaDesordenada(desordenado, tamano, 1);
    int posicion3 = busquedaBinaria(ordenado, 0, tamano-1, 8);


    cout << "La posicion es:" << posicion  << " " << posicion2 << " " << posicion3; // 3

    return 0;
}

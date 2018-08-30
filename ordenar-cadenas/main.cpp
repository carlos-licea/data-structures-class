#include <iostream>

#include<string.h>

using namespace std;

void swap(char* a, char* b) {
    char temporal[100];
    strcpy(temporal, a);
    strcpy(a, b);
    strcpy(b, temporal);
}

void bubblesort(char arreglo[5][100], int tamano) {
    bool huboCambio = false;
    int fin = tamano;
    do {
        huboCambio = false;

        for(int i = 0; i < fin-1; ++i) {
            if(strcmp(arreglo[i+1], arreglo[i]) < 0 ) {
                swap(arreglo[i], arreglo[i+1]);
                huboCambio = true;
            }
        }
        fin -= 1;
    } while(huboCambio);
}

void imprime(char arreglo[5][100]) {
    int size = 5;
    for(int i = 0; i < size; ++i ) {
        cout << arreglo[i] << endl;
    }
}

int main()
{
    char nombres[5][100] = { "carlos", "ana", "memo", "alex", "alejandro" };
    imprime(nombres);
    bubblesort(nombres, 5);
    cout << "ordenado\n";
    imprime(nombres);
    return 0;
}

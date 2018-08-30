#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

bool esPalindriomo(char* cadena, int inicio, int fin) {
    if(inicio > fin) {
        return true;
    }
    if(inicio == fin) {
        return true;
    }
    return cadena[inicio] == cadena[fin] && esPalindriomo(cadena, inicio+1, fin-1);
}

// NO recursiva
bool esPalindriomo(char* cadena, int tamano) {
    return esPalindriomo(cadena, 0, tamano-1);
}

int main()
{
    cout << "Escribe una cadena" << endl;
    char c[100];
    gets(c);
    cout << "Es palindriomo:" << (esPalindriomo(c, strlen(c))? "si" : "no");
    return 0;
}

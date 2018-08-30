#include <iostream>
#include <stdio.h>

using namespace std;

void hanoi(int n, char inicio, char aux, char destino) {

    if(n == 1) {
        printf("mover disco %i %c->%c\n", n, inicio,destino);
        return;
    }
    hanoi(n-1, inicio, destino, aux);
    printf("mover disco %i %c->%c\n", n, inicio,destino);
    hanoi(n-1, aux, inicio, destino);
}

int main()
{
    char inicio = 'a';
    char aux = 'b';
    char destino = 'c';

    hanoi(4, inicio, aux, destino);

    return 0;
}

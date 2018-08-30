#include <iostream>
#include <math.h>

using namespace std;

class Punto {
    friend float distancia(Punto p1, Punto p2);
public:
    void capturar(/*Punto* p*/) {
        // Punto* this
        cout << "Escriba x e y";
        cin >> this->x >> (*this).y >> this->z;
    }

private:
    int x = 0;
    int y = 0;
    int z = 0;
};

// p1.distancia(p2);

float distancia(Punto p1, Punto p2) {
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2) + pow(p1.z - p2.z,2));
}


int main()
{
    // capturar punto 1
    Punto p1;
    p1.capturar();
    // capturar punto 2
    Punto p2;
    p2.capturar();
    // calcular distancia
    float resultado = distancia(p1, p2);
    // imprimir resultado
    cout << "Distancia" << resultado;
    return 0;
}

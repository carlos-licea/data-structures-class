#include <iostream>

using namespace std;

struct NodoEntero {
    NodoEntero()
        : valor(0)
        , siguiente(nullptr)
    {
    }

    int valor{};
    NodoEntero* siguiente = nullptr;
};

struct PilaEntero {
    PilaEntero()
        : cabeza(nullptr)
    {
    }

    NodoEntero* cabeza = nullptr;

    void agregarNodo(NodoEntero* nodo) {
        nodo->siguiente = cabeza;
        cabeza = nodo;
    }

    void agregarEntero(int entero) {
        NodoEntero* nuevoNodo = new NodoEntero;
        (*nuevoNodo).valor = entero;
        agregarNodo(nuevoNodo);
    }

    NodoEntero* sacarNodo() {
        if(!cabeza) {
            return nullptr;
        }
        NodoEntero* viejaCabeza = cabeza;
        cabeza = cabeza->siguiente;
        return viejaCabeza;
    }

    int sacarEntero() {
        auto nodo = sacarNodo();
        if(nodo) {
            int valor = nodo->valor;
            delete nodo;
            return valor;
        }
        return 0;
    }

    void imprimir() {
        NodoEntero* actual = cabeza;
        while(actual) {
            cout << actual->valor << ",";
            actual = actual->siguiente;
        }
    }

    int tamano() {
        int resultado = 0;
        NodoEntero* actual = cabeza;
        while(actual) {
            ++resultado;
            actual = actual->siguiente;
        }
        return resultado;
    }
};

template <typename T>
struct Nodo {
    T valor{};
    Nodo<T>* siguiente = nullptr;
};

template <typename T>
struct Pila {
    Pila()
        : cabeza(nullptr)
    {
    }

    Nodo<T>* cabeza = nullptr;

    void agregarNodo(Nodo<T>* nodo) {
        nodo->siguiente = cabeza;
        cabeza = nodo;
    }

    void agregar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        (*nuevoNodo).valor = valor;
        agregarNodo(nuevoNodo);
    }

    Nodo<T>* sacarNodo() {
        if(!cabeza) {
            return nullptr;
        }
        Nodo<T>* viejaCabeza = cabeza;
        cabeza = cabeza->siguiente;
        return viejaCabeza;
    }

    T sacar() {
        auto nodo = sacarNodo();
        if(nodo) {
            int valor = nodo->valor;
            delete nodo;
            return valor;
        }
        return T();
    }

    void imprimir() {
        Nodo<T>* actual = cabeza;
        while(actual) {
            cout << actual->valor << ",";
            actual = actual->siguiente;
        }
    }

    int tamano() {
        int resultado = 0;
        Nodo<T>* actual = cabeza;
        while(actual) {
            ++resultado;
            actual = actual->siguiente;
        }
        return resultado;
    }
};


int main()
{
    PilaEntero pe;
    pe.agregarEntero(1);
    pe.agregarEntero(2);
    pe.agregarEntero(3);
    pe.imprimir();

    cout << "\n";

    Pila<float> pf;
    pf.agregar(10.0);
    pf.agregar(20.0);
    pf.agregar(30.0);
    pf.imprimir();

    cout << "\n" << pf.sacar() << "\n";
    pf.imprimir();
    return 0;
}

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

template <typename T>
struct Fila {
    Nodo<T>* cabeza = nullptr;
    Nodo<T>* fin = nullptr;

    bool esVacia() {
        return cabeza == nullptr;
    }

    void agregarNodo(Nodo<T>* nodo) {
        if(esVacia()) {
            cabeza = nodo;
            fin = nodo;
        } else {
            fin->siguiente = nodo;
            fin = nodo;
        }
    }

    void agregar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        (*nuevoNodo).valor = valor;
        agregarNodo(nuevoNodo);
    }

    Nodo<T>* sacarNodo() {
        if(esVacia()) {
            return nullptr;
        } else {
            auto viejaCabeza = cabeza; // Nodo<T>* viejaCabeza
            cabeza = viejaCabeza->siguiente;
            return viejaCabeza;
        }
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
};

template <typename T>
struct Deque {
    Nodo<T>* cabeza = nullptr;
    Nodo<T>* fin = nullptr;

    bool esVacia() {
        return cabeza == nullptr;
    }

    void agregarFinalNodo(Nodo<T>* nodo) {
        if(esVacia()) {
            cabeza = nodo;
            fin = nodo;
        } else {
            fin->siguiente = nodo;
            fin = nodo;
        }
    }

    void agregarFinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        (*nuevoNodo).valor = valor;
        agregarFinalNodo(nuevoNodo);
    }

    void agregarCabezaNodo(Nodo<T>* nodo) {
        if(esVacia()) {
            cabeza = nodo;
            fin = nodo;
        } else {
            nodo->siguiente = cabeza;
            cabeza = nodo;
        }
    }

    void agregarCabeza(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>;
        (*nuevoNodo).valor = valor;
        agregarCabezaNodo(nuevoNodo);
    }

    Nodo<T>* sacarNodoCabeza() {
        if(esVacia()) {
            return nullptr;
        } else {
            auto viejaCabeza = cabeza; // Nodo<T>* viejaCabeza
            cabeza = viejaCabeza->siguiente;
            return viejaCabeza;
        }
    }

    T sacarCabeza() {
        auto nodo = sacarNodoCabeza();
        if(nodo) {
            int valor = nodo->valor;
            delete nodo;
            return valor;
        }
        return T();
    }

    Nodo<T>* sacarNodoFin() {
        if(esVacia()) {
            return nullptr;
        } else {
            auto viejoFin = fin; // Nodo<T>* viejaCabeza

            // buscar penultimo
            auto penultimo = cabeza;
            // NOTA: el caso donde hay un solo elemento es mas complicado de lo que parece
            while(penultimo && penultimo->siguiente != fin) {
                penultimo = penultimo->siguiente;
            }

            if(penultimo) {
                fin = penultimo;
                penultimo->siguiente = nullptr;
            } else { // un solo elemento
                cabeza = nullptr;
                fin = nullptr;
            }

            return viejoFin;
        }
    }

    T sacarFin() {
        auto nodo = sacarNodoFin();
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

   Fila<int> fe;
   fe.agregar(11);
   fe.agregar(27);
   fe.agregar(31);
   fe.imprimir();

   cout << "\n" << fe.sacar() << "\n";
   fe.imprimir();

    Deque<int> de;
    de.agregarFinal(11);
    de.agregarCabeza(27);
    de.agregarFinal(31);
    de.imprimir();
    cout << "\n" << de.sacarFin() << "\n";
    de.imprimir();
    cout << "\n" << de.sacarCabeza() << "\n";
    de.imprimir();
    cout << "\n" << de.sacarFin() << "\n" << "ultimo:";
    de.imprimir();

    return 0;
}

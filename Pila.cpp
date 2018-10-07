#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    struct Nodo *siguiente;
};

void agregarPila(Nodo*&, int);
void sacarPila (Nodo *&, int &);

int main(){
    Nodo *pila = NULL;
    int dato;
    cout << "Digita  un numero: ";
    cin >> dato;
    agregarPila(pila,dato);
    cout << endl;
    cout << "Digita  un numero: ";
    cin >> dato;
    agregarPila(pila,dato);
    cout << endl;
    cout << "Elementos introducidos" << endl;
    while (pila != NULL){
        sacarPila(pila,dato);
        if(pila != NULL){
            cout << dato << ",";
        }else{
            cout << dato << ".";
        }
    }

    return 0;
}

void agregarPila(Nodo *&pila, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Dato: " << n << "\nagregado correctamente" << endl;
}

void sacarPila (Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}

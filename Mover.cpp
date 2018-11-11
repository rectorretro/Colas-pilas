#include <iostream>
using namespace std;
///funciones de la cola-------------
struct Cola{
    string dato;
    Cola *siguiente;
};
void insertarCola(Cola *&, Cola *&, string);
bool cola_vacia (Cola *);
void EliminarCola(Cola *&, Cola *&, string &);
///---------------------------------

///Funciones de la pila-------------
struct Pila{
    string dato;
    struct Pila *siguiente;
};
void agregarPila(Pila*&, string);
void sacarPila (Pila *&, string &);
///----------------------------------

///Tabla de valores-----------------------------
void numeros(string,Cola *&, Cola *&,Pila*&);
///----------------------------------------------
int main(){
    Pila *pila = NULL;
    Cola *frente = NULL;
    Cola *fin = NULL;
    string expresion,ayuda;
    cout << "Incerte la expreción: ";
    getline(cin,expresion);
    for(int i=0; i<expresion.size(); i++){
        ayuda = expresion[i];
        numeros(ayuda,frente,fin,pila);

    }
    insertarCola(frente,fin,pila->dato);

    while(frente != NULL){
            EliminarCola(frente,fin,ayuda);
            cout << ayuda;
    }



 return 0;
}
///Pila-----------------------------------
void agregarPila(Pila *&pila, string n){
    Pila *nuevo_nodo = new Pila();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Dato: " << n << " 5agregado correctamente a pila" << endl;
}

void sacarPila (Pila *&pila, string &n){
    Pila *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}
///------------------------------------------------

///Cola-------------------------------------------------------
void insertarCola(Cola *&frente, Cola *&fin, string n){
    Cola *nuevo_nodo = new Cola();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)){
      frente = nuevo_nodo;
    }else{
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;
    cout << endl;
    cout << "Elemento incertado en cola "<< n <<endl;
}

bool cola_vacia(Cola *frente){
    return(frente == NULL)? true : false;
}

void EliminarCola(Cola *&frente, Cola *&fin, string &n){
    n = frente->dato;
    Cola *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}
///-----------------------------------------------------------


void numeros(string ayuda,Cola *&frente, Cola *&fin,Pila *&pila){
    int valor,valor2;
    ///**------------------------------
    if(ayuda=="0"||ayuda == "1"||ayuda == "2"){
    insertarCola(frente,fin,ayuda);
    }else if(ayuda=="3"||ayuda == "4"||ayuda == "5"){
    insertarCola(frente,fin,ayuda);
    }else if(ayuda=="6"||ayuda == "7"||ayuda == "8"||ayuda == "9"){
    insertarCola(frente,fin,ayuda);
    }else if(pila == NULL){
        agregarPila(pila,ayuda);
    }else{
        ///*/////

    if(ayuda == "^"){
        valor = 4;
    }else if(ayuda == "*"||ayuda =="/"){
        valor = 2;
    }else if(ayuda == "+"||ayuda =="-"){
        valor = 1;
    }else if(ayuda == "("){
        valor = 5;
    }else if(ayuda == ")"){
        valor = -1;
    }

    if(pila->dato == "^"){
        valor2 = 3;
    }else if(pila->dato == "*"||pila->dato =="/"){
        valor2 = 2;
    }else if(pila->dato == "+"||pila->dato =="-"){
        valor2 = 1;
    }else if(pila->dato == "("){
        valor2 = 0;
    }else if(pila->dato == ")"){
        valor2 = -1;
    }
    if(valor<valor2){
            insertarCola(frente,fin,ayuda);
    }else if(valor == valor2){
        insertarCola(frente,fin,pila->dato);
        sacarPila(pila,pila->dato);
        agregarPila(pila,ayuda);
    }else if(valor > valor2){
        agregarPila(pila,ayuda);
    }


}
}

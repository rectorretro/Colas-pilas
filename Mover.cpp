#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
struct PilaE{
    string dato;
    struct PilaE *siguiente;
};
///funciones de la cola-------------
struct Cola{
    string dato;
    Cola *siguiente;
};
void insertarCola(Cola *&, Cola *&, string);
bool cola_vacia (Cola *);
void EliminarCola(Cola *&, Cola *&, string &);
///---------------------------------
void agregarPilaE(PilaE*&, string);
void sacarPilaE(PilaE *&, string &);
void evaluador(PilaE *&, string);
bool num(string);
///Funciones de la pila-------------
struct Pila{
    string dato;
    struct Pila *siguiente;
};
void agregarPila(Pila*&, string);
void sacarPila (Pila *&, string &);
///----------------------------------


void agregarPila(Pila*&, string);
void sacarPila(Pila *&, string &);
void evaluador(Pila *&, string);
bool num(string);
///Tabla de valores-----------------------------
void numeros(string,Cola *&, Cola *&,Pila*&);
///----------------------------------------------
int main(){
    Pila *pila = NULL;
    Cola *frente = NULL;
    Cola *fin = NULL;
    PilaE *pilaE = NULL;
    string expresion,ayuda,core;
    cout << "Incerte la expreción: ";
    getline(cin,expresion);
    for(int i=0; i<expresion.size(); i++){
        ayuda = expresion[i];
        numeros(ayuda,frente,fin,pila);

    }
    insertarCola(frente,fin,pila->dato);


    while(frente != NULL){
            EliminarCola(frente,fin,ayuda);
        core = ayuda;
        evaluador(pilaE,core);

    }



 return 0;
}
///Pila-----------------------------------
void agregarPila(Pila *&pila, string n){
    Pila *nuevo_nodo = new Pila();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

    cout << "Dato: " << n << " agregado correctamente a pila" << endl;
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
    if(n=="("||n==")"){
        return;
    }
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

    if(ayuda=="("||ayuda==")"){
           Pila *aux= pila;

    if(valor2 = -1){
            while(aux->dato!="("){

        insertarCola(frente,fin,pila->dato);
        sacarPila(pila,pila->dato);
        agregarPila(pila,ayuda);
        aux=aux->siguiente;

            }
    }
    }else{
        if(valor<=valor2){
        insertarCola(frente,fin,pila->dato);
        sacarPila(pila,pila->dato);
        agregarPila(pila,ayuda);
    }else if(valor >= valor2){
        agregarPila(pila,ayuda);
    }
    }




}
}



void agregarPilaE(PilaE *&pilaE, string n){
    PilaE *nuevo_nodo = new PilaE();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pilaE;
    pilaE = nuevo_nodo;

    cout << "Dato: " << n << " agregado correctamente a pila" << endl;
}

void sacarPilaE (PilaE *&pilaE, string &n){
    PilaE *aux = pilaE;
    n = aux->dato;
    pilaE = aux->siguiente;
    delete aux;
}

void evaluador(PilaE *&pilaE, string dato){
    int caso;
    if(dato=="+"){
        caso = 1;
    }else if(dato=="-"){
        caso = 2;
    }else if(dato=="*"){
        caso = 3;
    }else if(dato=="/"){
        caso = 4;
    }else if(dato=="^"){
        caso = 5;
    }
    bool ninfa = num(dato);
    double coro,base,n;
    if(pilaE==NULL||ninfa != false){
        agregarPilaE(pilaE,dato);
    }else{
        switch (caso){
        case 1:
            coro = stoi(pilaE->siguiente->dato)+stoi(pilaE->dato);
            sacarPilaE(pilaE,pilaE->dato);
            //sacarPila(pila,pila->siguiente->dato);
            agregarPilaE(pilaE,to_string(coro));
            break;
        case 2:
            coro = stoi(pilaE->siguiente->dato)-stoi(pilaE->dato);
            sacarPilaE(pilaE,pilaE->dato);
            //sacarPila(pila,pila->siguiente->dato);
            agregarPilaE(pilaE,to_string(coro));
            break;
        case 3:
            coro = stoi(pilaE->siguiente->dato)*stoi(pilaE->dato);
            sacarPilaE(pilaE,pilaE->dato);
            //sacarPila(pila,pila->siguiente->dato);
            agregarPilaE(pilaE,to_string(coro));
            break;
        case 4:
            coro = stoi(pilaE->siguiente->dato)/stoi(pilaE->dato);
            sacarPilaE(pilaE,pilaE->dato);
            //sacarPila(pila,pila->siguiente->dato);
            agregarPilaE(pilaE,to_string(coro));
            break;
        case 5:
            base = stoi(pilaE->siguiente->dato);
            n = stoi(pilaE->dato);
            double(base);
            double(n);
            coro = pow(base,n);
            sacarPilaE(pilaE,pilaE->dato);
            //sacarPila(pila,pila->siguiente->dato);
            agregarPilaE(pilaE,to_string(coro));
            break;
        default:
            break;
        }


    }

}

bool num(string ayuda){
    bool eco;
     if(ayuda=="0"||ayuda == "1"||ayuda == "2"){
    eco=true;
    }else if(ayuda=="3"||ayuda == "4"||ayuda == "5"){
    eco=true;
    }else if(ayuda=="6"||ayuda == "7"||ayuda == "8"||ayuda == "9"){
    eco=true;
    }else{
        eco=false;
    }
    return eco;
}


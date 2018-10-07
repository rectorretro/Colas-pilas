#include <iostream>
using namespace std;
int factorial(int);
int main(){
    int fact,resultado;
    cout << "Introdusca el numero del factorial que desea: ";
    cin >> fact;
    resultado = factorial(fact);
    cout << endl;
    cout << "Factorial: ";
    cout << resultado;
    return 0;
}

int factorial(int n){
    if (n == 0){
        n = 1;
    }else{
        n = n*factorial(n-1);
    }
    return n;
}

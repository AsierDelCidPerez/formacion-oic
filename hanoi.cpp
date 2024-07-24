#include <iostream>
#include <set>

using namespace std;

void hanoi(int n, char origen, char destino){
    set<char> palabras = {'A','B','C'};
    palabras.erase(origen);
    palabras.erase(destino);
    char aux = *palabras.begin();
    if(n == 1){
        cout << "Mueve el disco de " << origen << " a " << destino << ".\n";
    }else{
        hanoi(n-1,origen,aux);
        cout << "Mueve el disco de " << origen << " a " << destino << ".\n";
        hanoi(n-1,aux,destino);
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        int n;
        char S, D; 
        cin >> n >> S >> D;
        hanoi(n,S,D);
        cout << "Listo!\n";
    }
}
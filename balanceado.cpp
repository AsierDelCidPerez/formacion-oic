#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    int positivo = 0, negativo = 0;
    for(int i=0;i<N;i++){
        int c; cin >> c;
        if(c < 0) negativo += abs(c);
        else positivo += abs(c);
    }
    int resultado = positivo - negativo;
    if(resultado > 0){
        cout << "POSITIVO\n";
    }else if(resultado == 0){
        cout << "BALANCEADO\n";
    }else{
        cout << "NEGATIVO\n";
    }
}
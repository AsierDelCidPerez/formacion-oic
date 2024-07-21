#include <iostream>
#include <set>
#include <math.h>

using namespace std;

bool isCubinfinito(string N, set<string> & ciclos){
    int suma = 0;
    if(N == "1") return true;
    for(char i : N) suma += pow(i - '0', 3);
    cout << " - " << suma;
    
    if(suma == 1) return true;
    if(ciclos.count(to_string(suma))){
        return false;
    }
    else{
        ciclos.insert(to_string(suma));
        return isCubinfinito(to_string(suma), ciclos);
    }
}

int main(){
    string N;
    while(cin >> N){
        if(N == "0") break;
        set<string> ciclos;
        ciclos.insert(N);
        cout << N;
        if(isCubinfinito(N, ciclos)){
            cout << " -> cubifinitum.\n";
        }else{
            cout << " -> no cubifinitum.\n";
        }

    }

}
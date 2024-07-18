#include <iostream>
#include <list>

using namespace std;



int main(){
    list<int> numeros = {4, 5, 6, 7};
    numeros.push_back(9);
    numeros.push_front(1);

    while(!numeros.empty()){
        cout << numeros.front() << "\n";
        cout << numeros.back() << "\n";
        numeros.pop_front();
        numeros.pop_back();
    }

    for(int i : numeros){
        cout << i << "\n";
    }

}
#include <iostream>

using namespace std;

int fibo(int n){
    if(n < 1 ) return -1;
    if(n == 1 || n == 2) return 1;
    return fibo(n-1) + fibo(n-2);
}

int main(){
    cout << fibo(1) << "\n";
    cout << fibo(2) << "\n";
    cout << fibo(3) << "\n";
    cout << fibo(4) << "\n";
    cout << fibo(5) << "\n";
}
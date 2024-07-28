#include <iostream>

using namespace std;

using ll = long long int;

int main(){
    ll N; cin >> N;
    for(int i=0;i<=10;i++){
        cout << N << " x " << i << " = " << N*i << "\n";
    }
}
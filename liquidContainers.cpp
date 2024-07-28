#include <iostream>
#include <vector>

using namespace std;

using ll = long long int;

vector<ll> alturas;
int N;

ll calcularVolumen(ll a, ll b){
    return (min(alturas[a], alturas[b]) * abs(a-b));
}


void resolver(){
    int l = 0;
    int r = N-1;

    ll area = -1;

    while(l < r){
        ll volumen = calcularVolumen(l, r);
        // cout << volumen << "\n";
        area = max(area, volumen);
        if(alturas[l] < alturas[r]) l++;
        else r--;
    }

    cout << area << "\n";
}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> N;
        if(N == 0) continue;
        alturas.resize(N);
        for(auto & i : alturas) cin >> i; 
        resolver();
    }
}
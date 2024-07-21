#include <iostream>
#include <vector>

using namespace std;

vector<int> dims;
using ll = long long int;

vector<vector<int>> dp;

ll minProduct(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return 0;
    vector<ll> resultados;
    int menor = -1;
    for(int k=l;k<r;k++){
        int resultado = minProduct(l, k) + minProduct(k+1, r) + dims[l-1] * dims[k] * dims[r];
        if(menor == -1 || resultado < menor) menor = resultado;
    }
    return dp[l][r] = menor;
}

int main(){
    int N; cin >> N;
    dims.assign(N+1, -1);
    dp.assign(N+1, vector<int>(N+1, -1));
    for(int & i : dims){
        int c; cin >> c;
        i = c;
    }
    cout << minProduct(1, N) << "\n";
}
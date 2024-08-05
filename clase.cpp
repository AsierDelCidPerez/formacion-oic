#include <iostream>
#include <vector>

using namespace std;


const int MAX = 10;

vector<int> dp;

int comb(int n, int r){
    dp[0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=r;j>=1;--j){
            dp[j] = dp[j-1] + dp[j];
        }
    }
    return dp[r];
}


int main(){
    int n, r; cin >> n >> r;
    dp.assign(MAX+1, 0);
    cout << comb(n, r) << "\n";
}
#include <bits/stdc++.h>
using namespace std;

//AC

constexpr int MAX_K = 20;
constexpr int MAX_S = 100;

int k, s;
int dp[MAX_S+1][MAX_K+1];

int recur(int i, int j) {
    if(i < 0 || j <= 0) return 0;
    if(i == 0) return 1;

    if(dp[i][j] != -1) 
        return dp[i][j];

    return dp[i][j] = recur(i-j, j) + recur(i, j-1);
}

void solve() {
    cin >> k >> s;

    cout << recur(s, k) << '\n';
}

int main(int argc, char const *argv[]) {
    for(int i=0; i<=MAX_S; ++i) {
        for(int j=0; j<=MAX_K; ++j) {
            dp[i][j] = -1;
        }
    }

    int t; cin >> t;
    while(t--) solve();
    return 0;
}
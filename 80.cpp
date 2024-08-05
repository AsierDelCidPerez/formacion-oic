#include <bits/stdc++.h>
using namespace std;

//AC

bool closed[50][50];
int dp[50][50][2500];
int n, m, d;

int recur(int i, int j, int k) {
    if(i == 0 && j == 0 && k == d)
        return 1;
    
    if(i < 0 || j < 0 || k > d || closed[i][j])
        return 0;
    
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    return dp[i][j][k] = (recur(i-1, j, k+1) + recur(i, j-1, k+1)) % (int(1e9)+7);
}

bool solve() {
    cin >> n >> m;
    d = (n-1) + (m-1);
    if(!cin)
        return false;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            closed[i][j] = false;
            
            for(int k=0; k<d; ++k)
                dp[i][j][k] = -1;
        }
    }

    for(int i=0; i<n; ++i) {
        string s; cin >> s;
        for(int j=0; j<m; ++j) {
            if(s[j] == 'X') 
                closed[i][j] = true;
        }
    }

    int t = recur(n-1, m-1, 0);
    cout << t << '\n';

    return true;
}

signed main(signed argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(solve());
    return 0;
}
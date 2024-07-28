#include <bits/stdc++.h>
using namespace std;

//AC

constexpr int INF = 1e9;

bool solve() {
    int p, r;
    cin >> p >> r;
    if(!cin)
        return false;    
    
    vector<vector<int>> dp(p, vector<int>(p, INF));
    for(int i=0; i<p; ++i)
        dp[i][i] = 0;
    
    map<string,int> m;
    int curr=0;
    for(int i=0; i<r; ++i) {
        string s1, s2;
        cin >> s1 >> s2;
        if(!m.count(s1)) 
            m[s1] = curr++;
        if(!m.count(s2)) 
            m[s2] = curr++;

        dp[m[s1]][m[s2]] = 1;
        dp[m[s2]][m[s1]] = 1;
    }

    // Floyd-Warshall
    for(int k=0; k<p; ++k) {
        for(int i=0; i<p; ++i) {
            for(int j=0; j<p; ++j) {
                int tmp = dp[i][k] + dp[k][j];
                if(tmp < dp[i][j]) {
                    dp[i][j] = tmp;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < p; ++j)
            ans = max(ans, dp[i][j]);
    if(ans == INF)
        cout << "DESCONECTADA\n";
    else
        cout << ans << '\n';

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}
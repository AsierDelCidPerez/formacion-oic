#include <bits/stdc++.h>
using namespace std;

//AC

#define int long long

constexpr int INF = 1e18;

bool solve() {
    int c, n;
    cin >> c >> n;
    if(!cin)
        return false;

    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    vector<int> dp(c+1, INF);
    vector<int> f(c+1, 1);
    for(int i=1; i<=n; ++i) {
        dp[0] = 0;
        for(int j=1; j<=c; ++j) {
            if(v[i-1] > j) continue;
                
            int a = dp[j];
            int b = dp[j - v[i-1]] + 1;
                    
            if(a == b)
                f[j] += f[j - v[i-1]];
            else if(b < a)
                f[j] = f[j - v[i-1]];
                
            dp[j] = min(a, b);
        }
    }

    if(dp[c] == INF || dp[c] == 0) cout << "0\n";
    else cout << f[c] << '\n';

    return true;
}

signed main() {
    while(solve());
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//AC

bool solve() {
    int n; cin >> n;
    if(n == 0)
        return false;

    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    vector<int> dp(n, 1);
    for(int i=1; i<n; ++i) {
        for(int j=0; j<i; ++j) {
            if(v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int ans = -1;
    for(int i=0; i<n; ++i)
        ans = max(ans, dp[i]);

    cout << ans << '\n';

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}
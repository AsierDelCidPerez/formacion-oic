#include <bits/stdc++.h>
using namespace std;

//AC

constexpr int MAX = 24*60 +10;

bool solve() {
    int n; cin >> n;
    if(n == 0)
        return false;
    
    vector<pair<int,int>> mv(n);
    for(int i=0; i<n; ++i) {
        int h, m, d;
        cin >> h; cin.ignore(); cin >> m >> d;
        mv[i] = make_pair(h*60 + m, d);
    }

    sort(mv.begin(), mv.end());

    vector<int> dp(MAX+1, 0);
    for(int i=0; i<n; ++i) {
        for(int j=MAX; j>=0; --j) {
            auto [b, d] = mv[i];
            int e = b + d + 10;
            if(e <= j) 
                dp[j] = max(dp[j], dp[b] + d);
            else
                break;
        }
    }

    cout << dp[MAX] << '\n';

    return true;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(solve());
    return 0;
}
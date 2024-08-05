#include <bits/stdc++.h>
using namespace std;

//AC

vector<vector<int>> dp;
vector<int> v, p;

void print(int i, int j, int d) {
    if(i == 0) {
        cout << d << '\n';
        return;
    }

    if(dp[i][j] != dp[i-1][j]) {
        print(i-1, j-p[i-1], d+1);
        cout << p[i-1] << ' ' << v[i-1] << '\n';
    } else {
        print(i-1, j, d);
    }
}

bool solve() {
    int T, N;
    cin >> T >> N;
    if(!cin)
        return false;

    T = T/3;

    v.assign(N, 0);
    p.assign(N, 0);
    for(int i=0; i<N; ++i) {
        int pi;
        cin >> pi >> v[i];
        p[i] = pi;
    }

    dp.assign(N+1, vector<int>(T+1, 0));
    for(int i=1; i<=N; ++i) {
        for(int j=1; j<=T; ++j) {
            if(p[i-1] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-p[i-1]] + v[i-1]);
        }
    }

    cout << dp[N][T] << '\n';

    print(N, T, 0);

    cout << "---\n";

    return true;
}

int main(int argc, char const *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(solve());
    return 0;
}
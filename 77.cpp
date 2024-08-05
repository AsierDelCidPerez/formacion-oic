#include <bits/stdc++.h>
using namespace std;

//AC

constexpr int MAX_K = 1000;
int dp[MAX_K+1][MAX_K+1];
int k;
string s;

void print(int l, int r) {
    if(l > r) return;
    else if(s[l] == s[r]) {
        cout << s[r];
        print(l+1, r-1);
        if(l != r) cout << s[l];
    } else if(dp[l][r-1] < dp[l+1][r]) {
        cout << s[r];
        print(l, r-1);
        cout << s[r];
    } else {
        cout << s[l];
        print(l+1, r);
        cout << s[l];
    }
}

bool solve() {
    cin >> s;
    k = s.size();
    if(!cin)
        return false;

    for(int i=k-1; i>=0; --i) {
        for(int j=0; j<k; ++j) {
            if(i >= j) 
                dp[i][j] = 0;
            else if(s[i] == s[j]) 
                dp[i][j] = dp[i+1][j-1];
            else
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
        }
    }

    cout << dp[0][k-1];
    print(0, k-1);
    cout << '\n';

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}
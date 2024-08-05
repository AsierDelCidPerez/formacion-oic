#include <iostream>
#include <vector>

using namespace std;

string s;

vector<vector<int>> dp;

int patitos(int l, int r){ // [l, r]
    if(l > r) return 0;
    int & res = dp[l][r];
    if(res == -1){
        if(s[l] == s[r]){
            return dp[l][r] = patitos(l+1, r-1) + 2;
        }else{
            return dp[l][r] = max(patitos(l, r-1), patitos(l+1, r));
        }
    }
    if(dp[l][r] != -1) return dp[l][r];

}

int main(){
    int T; cin >> T;
    while(T--){
        cin >> s;
        dp.assign(s.length()+1, vector<int>(s.length()+1, -1));
        cout << (s.length() - patitos(0, s.length()-1)+1) << "\n"; 
    }
}
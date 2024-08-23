#include <iostream>
#include <vector>
using namespace std;

// AC

bool solve() {
    int N, P; cin >> N >> P;
    if(!cin)
        return false;
    
    vector<int> v(N);
    for(int i=0; i<N; ++i) {
        int h,m,s; char ch;
        cin >> h >> ch >> m >> ch >> s;
        v[i] = 3600*h + 60*m + s;
    }

    for(int i=0; i<P; ++i) {
        int h,m,s; char ch;
        cin >> h >> ch >> m >> ch >> s;
        int t = 3600*h + 60*m + s;

        int l = -1, r = N;
        while(l+1 < r) {
            int m = (l+r)/2;
            if(v[m] < t)
                l = m;
            else 
                r = m;
        }

        if(r < N) {
            int c = v[r];
            int h = c/3600; c = c%3600;
            int m = c/60; c = c%60;
            printf("%02d:%02d:%02d\n", h,m,c);
        } else
            cout << "NO\n";
    }

    cout << "---\n";

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}

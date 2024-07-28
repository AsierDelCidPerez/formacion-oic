#include <iostream>
using namespace std;


//AC

int zeroesFact(int n) { //as there is always more factors of 2 than 5, the zeroes are determined by the number of fives
    int five=0;
    int d=5;
    while(n/d != 0) {
        five += n/d;
        d *= 5;
    }

    return five;
}

bool solve() {
    int D,N;
    cin >> D >> N;
    if(D == 0 && N == 0)
        return false;

    int l=0, r=10e12;
    //[0..l] < zeroes, [r..] >= zeroes
    while(l+1 < r) {
        int m = (l+r)/2;
        if(zeroesFact(m) < N)
            l = m;
        else
            r = m;
    }

    int lower = r;

    l=0, r=10e12;
    //[0..l] <= zeroes, [r..] > zeroes
    while(l+1 < r) {
        int m = (l+r)/2;
        if(zeroesFact(m) <= N)
            l = m;
        else
            r = m;
    }

    int upper = l;

    for(int i=lower; i<=upper; ++i) {
        if(i%D == 0) {
            cout << i << '\n';
            return true;
        }
    }

    cout << "NINGUNO\n";

    return true;
}

signed main(signed argc, char const *argv[]) {
    while(solve());
    return 0;
}

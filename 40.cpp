#include <iostream>
#include <vector>
using namespace std;

//AC

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int n): numSets(n), p(n, -1) {}

    int find(int i) {
        return (p[i] < 0)? i : p[i] = find(p[i]);
    }

    bool related(int i, int j) {
        return find(i) == find(j);
    }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        if(x == y) return;
        if(p[x] < p[y]) swap(x, y);
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    int size(int i) {
        return -p[find(i)];
    }
};

bool solve() {
    int W,H,N;
    cin >> W >> H >> N;
    if(W == 0)
        return false;

    const int LEFT = N, RIGHT = N+1;

    vector<pair<int,int>> guards(N);

    ufds uf(N+2);
    for(int i=0; i<N; ++i) {
        int x,y;
        cin >> x >> y;

        guards[i] = make_pair(x, y);
        if(x <= 10) uf.join(LEFT, i);
        else if(x >= W-10) uf.join(RIGHT, i);
        
        //Probably not efficient
        for(int j=0; j<i; ++j) {
            auto z = guards[j].first;
            auto a = guards[j].second;
            if((x-z)*(x-z) + (y-a)*(y-a) <= 400) {
                uf.join(i, j);
            }
        }
    }

    if(uf.related(LEFT, RIGHT)) cout << "NO\n";
    else                        cout << "SI\n";

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}
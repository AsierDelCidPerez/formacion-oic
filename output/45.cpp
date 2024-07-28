#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

//AC

int N,M;

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int n): numSets(n), p(n, -1) {}

    int find(int i) {
        return (p[i] < 0)? i : p[i] = find(p[i]); 
    }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        if(x == y) return;
        if(p[x] < p[y]) swap(x, y);
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    bool related(int i, int j) {
        return find(i) == find(j);
    }

    int size(int i) {
        return -p[find(i)];
    }
};

bool solve() {
    cin >> N >> M;
    if(!cin)
        return false;

    vector<tuple<int,int,int>> edges(M);
    for(int i=0; i<M; ++i) {
        int u,v,c;
        cin >> u >> v >> c;
        --u; --v;

        edges[i] = make_tuple(c, u, v);
    }

    sort(edges.begin(), edges.end());

    ufds uf(N);
    int ans = 0;
    for(auto [c, u, v]: edges) {
        if(!uf.related(u, v)) {
            uf.join(u, v);
            ans = max(ans, c);
        }

        if(uf.numSets == 1) break;
    }

    if(uf.numSets == 1) cout << ans << '\n';
    else cout << "Imposible\n";

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}

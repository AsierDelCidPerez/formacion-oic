#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ufds {
    int numSets;
    vector<int> p;
    ufds(int N) : numSets(N), p(N, -1) {}
    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }
    void join(int i, int j){
        int x = find(i), y = find(j); 
        if(p[x] > p[y]) {
            swap(x, y);
        } // [INVARIANTE] x siempre contiene al arbol mayor
        p[x] += p[y];
        p[y] = x;
        --numSets;
    }
    bool related(int i, int j){
        return find(i) == find(j);
    }
    int getSize(int i){
        return -p[find(i)];
    }
};


vector<tuple<int, int, int>> aristas; // coste y extremos

int kruskal(int V){
    sort(aristas.begin(), aristas.end());
    int minCoste = 0;
    ufds uf(V);
    for(auto [c, a, b] : aristas){
        if(!uf.related(a, b)){
            minCoste += c;
            uf.join(a, b);
        }
        if(uf.numSets == 1) break;
    }
    return minCoste;
}

int main(){
    int V, E; cin >> V >> E;
    aristas.assign(0, {-1, -1, -1});
    for(int i=0;i<E;i++){
        int a, b, c; cin >> a >> b >> c;
        aristas.push_back({c, a, b});
    }
    cout << kruskal(V);
    aristas.clear();
    
}


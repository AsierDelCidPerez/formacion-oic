#include <iostream>
#include <vector>

using namespace std;

struct ufds {
    int numSets;
    vector<int> p;
    ufds(int N) : numSets(N), p(N, -1) {}
    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }
    void join(int i, int j){
        if(related(i, j)) return;
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

int main(){
    int V, E; 
    while(cin >> V >> E){
        ufds uf(V);

        while(E--){ 
            int a, b; cin >> a >> b; a--;b--;
            uf.join(a,b);
        }

        int Q; cin >> Q;
        while(Q--){
            int a, b; cin >> a >> b; a--;b--;
            if(uf.related(a, b)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }

}
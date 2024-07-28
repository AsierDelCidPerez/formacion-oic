#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int I, P;
vector<tuple<int, int, int>> puentes;

struct ufds {
    int trees;
    vector<int> p;

    ufds(int N) : trees(N), p(N, -1) {}

    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    void join(int i, int j){
        int x = find(i);
        int y = find(j);
        // Se establece que x es siempre un árbol mayor

        if(related(i, j)) return;

        if(p[x] > p[y]) swap(x, y);
        
        p[x] += p[y];
        p[y] = x;
        --trees;
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

    int size(int i){
        return -p[find(i)];
    }

};

int kruskalMinimo(){
    int coste = 0;
    sort(puentes.begin(), puentes.end());
    ufds u(I);

    for(auto [c, x, y] : puentes){
        if(!u.related(x, y)){
            coste+=c;
            u.join(x, y);
        }

        if(u.trees == 1) break;
    }

    if(u.trees != 1) return -1;
    

    return coste;
}

int main(){
    while(cin >> I >> P){
        puentes.clear();
        for(int i=0;i<P;i++){
            int x, y, c; cin >> x >> y >> c; --x; --y;
            puentes.push_back({c, x, y});
        }
        int v = kruskalMinimo();
        if(v < 0){
            cout << "No hay puentes suficientes\n";
        }else{
            cout << v << "\n";
        }
    }
}
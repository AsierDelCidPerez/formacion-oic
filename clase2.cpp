#include <iostream>
#include <queue>

using namespace std;

vector<int> dist;

vector<vector<int>> g;

int destino;

int bfs(int node){
    queue<int> nodos;
    nodos.push(node);
    dist[node] = 0;
    while(!nodos.empty()){
        int n = nodos.front(); 
        nodos.pop();
        for(int i : g[n]){
            if(dist[i] == -1){
                nodos.push(i);
                dist[i] = dist[n]+1;
            }
        }
    }
    return dist[destino];
}

int main(){
    int N, V; cin >> N >> V;
    g.assign(N, vector<int>(0, {}));
    dist.assign(N, -1);
    for(int i=0;i<V;i++){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    int origin; cin >> origin >> destino;
    --origin;--destino;
    cout << bfs(origin) << "\n";
}
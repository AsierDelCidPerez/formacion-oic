#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int destino;
vector<vector<int>> g;
vector<int> dist;

int main(){
    int N, A; cin >> N >> A;
    g.assign(N, vector<int>(0, {}));
    dist.assign(N, -1);
    for(int i=0;i<N;i++){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    int or; cin >> or >> destino;
    cout << bfs(or);
}


int bfs(int node){
    queue<int> nodos;
    nodos.push(node);
    dist[node] = 0;

    while(!nodos.empty()){
        for(int i : g[node]){
            if(dist[i] == -1){
                nodos.push(i);
                dist[i] = dist[node]+1;
            }
        }
    }

    return dist[destino];
}


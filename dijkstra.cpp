#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> g;
vector<int> dist;
vector<int> antecesores;

void dijkstra(int node){
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>
    > pq;
    pq.push({0, node});
    dist[node] = 0;
    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(dist[v] != -1 && dist[v] < c) continue;
        for(auto [i, c] : g[v]){
            if(dist[i] == -1 || dist[v]+c < dist[i]){
                dist[i] = dist[v]+c;
                pq.push({dist[i],i});
            }
        }
    }
}

int main(){
    int V, origin, destino;
    cin >> V >> origin >> destino;

    g.assign(V, vector<pair<int, int>>(0, {-1, -1}));
    antecesores.assign(V, -1);
    dist.assign(V, -1);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            int c; cin >> c;
            if(c != 0 && i != j){
                g[i].push_back({j, c});
                g[j].push_back({i, c});
            }
        }
    }

    dijkstra(origin);
    cout << dist[destino] << "\n";
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using state = pair<int, int>; // node, mult
using PQGreater = priority_queue< pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>> >;

int destino, mult;
vector<vector<int>> dist;
vector<vector<state>> anteriores;
vector<vector<pair<int, int>>> g;

void getCamino(state estado){
    auto parent = anteriores[estado.first][estado.second];
    if(parent.first == -1 && parent.second == -1){
        cout << "<" << estado.first << ", " << estado.second << ">";
    }else{
        getCamino(parent);
        cout << " -> <" << estado.first << ", " << estado.second << ">";
    }
}

void dijkstra(int node){
    PQGreater pq;
    dist[node][0] = 0;
    pq.push({0, {node, 0}});
    while(!pq.empty()){
        auto [c, estado] = pq.top(); pq.pop();
        if(c > dist[estado.first][estado.second]) continue;
        int nuevaMult = (estado.second + 1) % mult;
        for(auto [n, C] : g[estado.first]){
            if(dist[n][nuevaMult] == -1 || dist[n][nuevaMult] > C + c){
                dist[n][nuevaMult] = C + c;
                anteriores[n][nuevaMult] = {estado.first, estado.second};
                pq.push({dist[n][nuevaMult], {n, nuevaMult}});
            }
        }
    }
    cout << dist[destino][0] << "\n";
    // getCamino({destino, 0});
}

int main(){
    int T; cin >> T;
    while(T--){
        int V, E;
        cin >> V >> E;
        g.assign(V, vector<pair<int, int>>(0, {-1, -1}));
        anteriores.assign(V, vector<pair<int, int>>(V, {-1, -1}));
        for(int i=0;i<E;i++){
            int a, b, c; cin >> a >> b >> c;
            g[--a].push_back({--b, c});
            g[b].push_back({a, c});
        }
        int origin;
        cin >> origin >> destino >> mult;
        --origin;--destino;
        dist.assign(V, vector<int>(mult, -1));
        dijkstra(origin);
    }
}
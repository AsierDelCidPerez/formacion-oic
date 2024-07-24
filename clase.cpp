#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> g;

int dijkstra(int node){
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    pq.push({0, node});
    while(!pq.empty()){
        auto [c, v] = pq.top();
        
    }
}

int main(){
    int V, E;
    cin >> V >> E;
    g.assign(V, vector<pair<int, int>>(0, {}));
    for(int i=0;i<E;i++){
        int o, d, c; cin >> o >> d >> c;
        g[--o].push_back({--d, c});
        g[d].push_back({o, c});
    }
    
    dijkstra(0);
}
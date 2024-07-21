#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> visited;
int destino = -1;

bool canAccess(int nodo){
    visited[nodo] = true;
    bool variable = false;
    for(int i : g[nodo]){
        if(i == destino) return true;
        if(!visited[i]) variable = variable || canAccess(i);
        if(variable) return true;
    }
    return variable;
}

int main(){
    int N, A; cin >> N >> A;
    g.assign(N, vector<int>(0, {}));
    visited.assign(N, false);
    for(int i=0;i<A;++i){
        int a, b; cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    int origin;
    cin >> origin >> destino; destino--;
    if(canAccess(--origin)) cout << "SI\n";
    else cout << "NO\n";
}
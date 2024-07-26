#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

using state = pair<int, int>;
using PQGreater = priority_queue<pair<int, state>, vector<pair<int, state>>, greater<pair<int, state>>>;
vector<vector<int>> dist;
vector<int> capacidades;
int deseado;

bool isCapacidad(vector<int> const & capacidad, int deseado){
    for(int i : capacidad) if(i == deseado) return true;
    return false;
}

vector<vector<state>> anteriores;
set<state> permutaciones;

void getCamino(state estado){
    permutaciones.erase(estado);
    state parent = anteriores[estado.first][estado.second];
    if(parent.first == -1 && parent.second == -1){
        cout << "<" << estado.first << ", " << estado.second << ">";
    }
    else{
        getCamino(parent);
        cout << " -> <" << estado.first << ", " << estado.second << ">";
    }
}

set<state> getPermutations(int max_1,int max_2, int cap_inicial){
    set<state> permutaciones;
    for(int i=0;i<=max_1;i++){
        for(int j=0;j<=max_2;j++){
            if(i+j > cap_inicial) continue;
            permutaciones.insert({i, j});
        }
    }
    return permutaciones;
}

void encontrarAdyacentes(vector<int> const & misCapacidades, int c, PQGreater & pq){
    state estado = {misCapacidades[0], misCapacidades[1]};
    for(int i=0;i<3;i++){ // Dador
        for(int j=0;j<3;j++){ // Recibidor
            if(i == j) continue;
            vector<int> nuevo(3, -1);
            int trasvase = min(misCapacidades[i], capacidades[j]-misCapacidades[j]);
            nuevo = {misCapacidades[0], misCapacidades[1], misCapacidades[2]};
            nuevo[i] = misCapacidades[i]-trasvase;
            nuevo[j] = misCapacidades[j]+trasvase;

            if(dist[nuevo[0]][nuevo[1]] == -1 || c+trasvase < dist[nuevo[0]][nuevo[1]]){
                pq.push({c+trasvase,{nuevo[0], nuevo[1]}});
                anteriores[nuevo[0]][nuevo[1]] = estado;
                dist[nuevo[0]][nuevo[1]] = c+trasvase;
            }
        }
    }
}

void dijkstra(){
    PQGreater pq;
    pq.push({0, {capacidades[0], 0}});
    dist[capacidades[0]][0] = 0;
    while(!pq.empty()){
        auto [c, estado] = pq.top(); pq.pop();
        if(c > dist[estado.first][estado.second]) continue;
        int A = estado.first,B=estado.second; 
        int C=capacidades[0]-(A+B);
        vector<int> misCapacidades = {A, B, C};
        encontrarAdyacentes(misCapacidades, c, pq);
        if(isCapacidad(misCapacidades, deseado)){
            cout << c << "\n"; 
            // getCamino(estado);
            // cout << "\n";
            return;
        }
    }
    cout << "BOOM\n";
}

int main(){
    int T; cin >> T;
    capacidades.assign(3, -1);
    while(T--) {
        for(int i=0;i<3;i++) cin >> capacidades[i];
        cin >> deseado;
        dist.assign(capacidades[0]+1, vector<int>(capacidades[1]+1,-1));
        anteriores.assign(capacidades[0]+1,vector<state>(capacidades[1]+1, {-1,-1}));
        dijkstra();
    }
}
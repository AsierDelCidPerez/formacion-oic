#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


using ll = long long int;

struct Point {
    private:
        ll x1, x2;
    public:
        Point(ll x, ll y) : x1(x), x2(y){}
        pair<int, int> getPoint(){
            return {x1, x2};
        }
        ll distTaxi(Point p2){
            ll x = abs(x1 - p2.x1);
            ll y = abs(x2 - p2.x2);
            return x+y;
        }
};

struct ufds {
    int numSets;
    vector<int> p;
    ufds(int N) : p(N, -1), numSets(N) {}
    
    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    bool related(int x, int y){
        return find(x) == find(y);
    }

    void join(int x, int y){
        if(related(x, y)) return;
        int a = find(x);
        int b = find(y);
        if(p[a] > p[b]) swap(a, b);
        p[a] += p[b];
        p[b] = a;
        --numSets;
    }
};

vector<tuple<ll, int, int>> edges;

void kruskal(int V){
    sort(edges.begin(), edges.end());
    ufds uf(V);
    ll minCoste = 0;
    vector<pair<int, int>> conexiones;
    for(auto [c, a, b] : edges){
        if(!uf.related(a-1, b-1)){
            uf.join(a-1, b-1);
            minCoste += c;
            conexiones.push_back({a, b});
        }
        if(uf.numSets == 1) break;
    }
    
    cout << conexiones.size() << "\n";
    sort(conexiones.begin(), conexiones.end());
    for(auto [a, b] : conexiones){
        cout << a << " " << b << "\n";
    }
    
}


int main(){
    int N; cin >> N;  
    vector<Point> puntos;
    edges.clear();
    puntos.clear();
    for(int i=0;i<N;i++){
        ll a, b; cin >> a >> b;
        puntos.push_back({a, b});
    }
    for(int i=0;i<puntos.size();++i){
        for(int j=0;j<puntos.size();++j){
            if(i==j) continue;
            edges.push_back({puntos[i].distTaxi(puntos[j]), i+1, j+1});
        }
    }
    kruskal(N);
    return 0;
}
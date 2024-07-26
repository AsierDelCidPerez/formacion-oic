#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

//AC

constexpr int INF = 1e9;

using info = array<int, 3>; //{cost, litres, v}
vector<vector<pair<int,int>>> adj; //{dist, v}

bool solve() {
    int N,M;
    cin >> N >> M;
    if(!cin)
        return false;

    vector<int> p(N);
    for(int i=0; i<N; ++i) {
        int a; cin >> a;
        p[i] = a;
    }

    adj.assign(N, {});
    for(int i=0; i<M; ++i) {
        int u, v, d;
        cin >> u >> v >> d;
        --u; --v;

        adj[u].push_back({d, v});
        adj[v].push_back({d, u});
    }

    int Q; cin >> Q;
    for(int i=0; i<Q; ++i) {
        int s, t, C;
        cin >> C >> s >> t;
        --s; --t;

        vector<vector<int>> cost(N, vector<int>(C+1, INF));
        priority_queue<info, vector<info>, greater<info>> pq;
        cost[s][0] = 0;
        pq.push({0, 0, s});

        while(!pq.empty()) {
            auto [c, l, v] = pq.top();
            pq.pop();

            if(c > cost[v][l])
                continue;

            if(l < C && c+p[v] < cost[v][l+1]) {
                cost[v][l+1] = c + p[v];
                pq.push({c+p[v], l+1, v});
            }

            for(auto [d, w]: adj[v]) {
                if(d <= l) {
                    if(c < cost[w][l-d]) {
                        cost[w][l-d] = c;
                        pq.push({c, l-d, w});
                    }
                }
                
                /*int minL = max(0,d-l);
                int maxL = p[v]<p[w]? C-l : minL; //The next gas station is cheaper

                for(int j=minL; j<=maxL; ++j) {
                    int price = j*p[v];

                    if(c + price < cost[w][j+l-d]) {
                        cost[w][j+l-d] = c + price;
                        pq.push({c+price, j+l-d, w});
                    }
                }*/
            }
        }
        
        
        int ans = cost[t][0]; //Waste litres is bad
        if(ans == INF)
            cout << "IMPOSIBLE\n";
        else 
            cout << ans << '\n';
    }

    cout << "---\n";
    return true;
}

int main(int argc, char const *argv[]){
    while(solve());
    return 0;
}

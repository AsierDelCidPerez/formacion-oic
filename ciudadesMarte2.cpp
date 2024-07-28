#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for (auto i = (l) - ((l) > (r)); i != (r) - ((l) > (r)); i += 1 - 2 * ((l) > (r)))
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

#include <vector>

using ld = long double;
using lli = long long;
using ii = pair<int, int>;

struct Dsu {
  vector<int> par;

  Dsu(int n = 1) : par(n + 1) {
    iota(all(par), 0);
  }

  int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) {
      par[v] = u;
      return 1;
    }
    return 0;
  }
};

struct Edge {
  int u, v;
  lli dist;
};

struct Point {
  lli x, y;
};

const int N = 1005;
Point p[N];
int n;

lli dist(int i, int j) {
  return abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
}

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);

  cin >> n;
  fore (i, 1, n + 1) {
    cin >> p[i].x >> p[i].y;
  }

  vector<Edge> edges;
  fore (i, 1, n + 1)
    fore (j, i + 1, n + 1) {
      edges.pb({i, j, dist(i, j)});
    }
  debug(edges);

  sort(all(edges), [&](Edge a, Edge b) {
    return a.dist < b.dist;
  });

  vector<ii> mst;
  Dsu dsu(n + 1);
  lli sum = 0;
  vector<pair<int, int>> conexiones;
  for (auto& e : edges) {
    if (dsu.unite(e.u, e.v)) {
      sum += e.dist;
      conexiones.push_back({e.u, e.v});
    }
  }

    cout << conexiones.size() << "\n";

    for(auto [a, b] : conexiones){
        cout << a << " " << b << "\n";
    }

  // cout << sum << '\n';

  return 0;
}

/* Please, check the following:
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * write down your ideas
 * DON'T get stuck on ONE APPROACH!
 * ASK for HELP from your TEAMMATES
 */
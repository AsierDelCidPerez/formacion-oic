#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//AC

struct ufds {
    vector<int> p;

    ufds(int N): p(N, -1) {}

    int find(int i) {
        return (p[i] < 0)? i : p[i] = find(p[i]);
    }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        if(x == y) return;
        if(p[x] < p[y]) swap(x, y);
        p[y] += p[x];
        p[x] = y;
    }
};


int N, M, K, n;
vector<vector<int>> board;

bool solve() {
    cin >> N >> M >> K >> n;
    if(!cin)
        return false;
    
    board.assign(N+1, vector<int>(M+1, -1));
    board[0][0] = n; 
    board[N][M] = n+1;

    vector<pair<int,int>> trees(n);
    ufds uf(n+2);
    for(int i=0; i<n; ++i) {
        int x,y;
        cin >> x >> y;
        trees[i] = make_pair(x, y);
    }

    for(int t=trees.size()-1; t>=0; --t) {
        auto [x, y] = trees[t];
        board[x][y] = t;

        for(int i=x-K; i<=x+K; ++i) {
            for(int j=y-K; j<=y+K; ++j) {
                if(i >= 0 && i <= N
                && j >= 0 && j <= M
                && board[i][j] != -1
                && (x-i)*(x-i) + (y-j)*(y-j) <= K*K) {
                    uf.join(t, board[i][j]);
                }
            }
        }

        if(uf.find(n) == uf.find(n+1)) {
            cout << x << ' ' << y << '\n';
            return true;
        }
    }

    cout << "NUNCA SE PUDO\n";

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}

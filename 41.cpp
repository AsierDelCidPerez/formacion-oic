#include <iostream>
#include <vector>
#include <string>
using namespace std;

//AC

struct ufds {
    int maxSize;
    int numSets;
    vector<int> p;

    ufds(int n): maxSize(0), numSets(n), p(n, -1) {}

    int find(int i) {
        if(p[i] < 0) {
            maxSize = max(maxSize, -p[i]);
            return i;
        }
        return p[i] = find(p[i]);
    }

    bool related(int i, int j) {
        return find(i) == find(j);
    }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        if(x == y) return;
        if(p[x] < p[y]) swap(x, y);
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    int size(int i) {
        return -p[find(i)];
    }
};

int incF[] = {-1,-1,-1,1,1,1,0,0};
int incC[] = {-1,1,0,-1,1,0,-1,1};
int F,C;
vector<string> board;

int toIndex(int f, int c) {
    return f*C + c;
}

void transverse(ufds& uf, int f, int c) {
    int u = toIndex(f, c);

    if(uf.maxSize <= 0) 
        uf.maxSize = 1;

    for(int i=0; i<8; ++i) {
        int nf = f+incF[i];
        int nc = c+incC[i];
        int v = toIndex(nf, nc);
        if(0 <= nf && nf < F
        && 0 <= nc && nc < C
        && board[nf][nc] == '#' 
        && !uf.related(u, v)) {
            uf.join(u, v);
            transverse(uf, nf, nc);
        } 
    }
}

bool solve() {
    cin >> F >> C;
    if(!cin)
        return false;
    
    board.assign(F, ""); 
    cin.ignore();
    for(int i=0; i<F; ++i) {
        getline(cin, board[i]);
    }

    ufds uf(F*C);
    for(int i=0; i<F; ++i) {
        for(int j=0; j<C; ++j) {
            if(board[i][j] == '#')
                transverse(uf, i, j);
        }
    }

    vector<int> v;
    v.push_back(uf.maxSize);

    int N; cin >> N;
    for(int i=0; i<N; ++i) {
        int f,c; cin >> f >> c;
        --f; --c;
        board[f][c] = '#';

        transverse(uf, f, c);
        v.push_back(uf.maxSize);
    }

    for(int i=0; i<v.size(); ++i) {
        cout << v[i] << " \n"[i==v.size()-1];
    }

    return true;
}

int main(int argc, char const *argv[]){
    while(solve());
    return 0;
}

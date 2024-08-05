#include <bits/stdc++.h>
using namespace std;

//AC

struct segtree {
    int num;
    vector<int> st;

    segtree(const vector<int>& v): num(v.size()), st(4*v.size()) {
        init(1, 0, num-1, v);
    }

    void update(int pos, int val) {
        update(1, 0, num-1, pos, val);
    }

    int query(int a, int b) {
        return query(1, 0, num-1, a, b);
    }

private:
    void init(int node, int l, int r, const vector<int>& v) {
        if(l == r) {
            st[node] = v[l];
            return;
        }

        int m = (l+r)/2;
        init(node*2, l, m, v);
        init(node*2+1, m+1, r, v);

        st[node] = st[node*2] + st[node*2+1];
    }

    void update(int node, int l, int r, int pos, int val) {
        assert((l <= pos) && (pos <= r));

        if(l == r) {
            st[node] = val;
            return;
        }

        int m = (l+r)/2;
        if(pos <= m)
            update(node*2, l, m, pos, val);
        else
            update(node*2+1, m+1, r, pos, val);
        
        st[node] = st[node*2] + st[node*2+1];
    }

    int query(int node, int l, int r, int a, int b) {
        if(b < l || r < a)  
            return 0;

        if(a <= l && r <= b)
            return st[node];
        
        int m = (l+r)/2;        
        return query(node*2, l, m, a, b) + query(node*2+1, m+1, r, a, b);
    }

};

bool solve() {
    int n; cin >> n;
    if(!cin)
        return false;
    
    vector<int> v(n);
    for(int i=0; i<n; ++i) {
        cin >> v[i];
    }
    
    auto st = segtree(v);

    string s;
    while((cin >> s), s != "FIN") {
        if(s == "S") {
            int x, r;
            cin >> x >> r;
            st.update(x-1, r);
        } else {
            int x, y;
            cin >> x >> y;
            cout << st.query(x-1, y-1) << '\n';
        }
    }

    cout << "---\n";

    return true;
}

int main(int argc, char const *argv[]) {
    while(solve());
    return 0;
}
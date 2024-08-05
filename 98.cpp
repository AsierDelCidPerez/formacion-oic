#include <bits/stdc++.h>
using namespace std;

//AC

struct segtree {
    int num;
    vector<int> st;

    segtree(const vector<int>& v): num(v.size()), st(v.size()*4) {
        init(1, 0, num-1, v);
    }

    void update(int pos, int val) {
        update(1, 0, num-1, pos, val);
    }

    int query(int a, int b) {
        return query(1, 0, num-1, a, b);
    }

private:
    int query(int node, int l, int r, int a, int b) {
        if(b < l || r < a)
            return 1;
        
        if(a <= l && r <= b)
            return st[node];

        int m = (l+r)/2;
        return query(node*2, l, m, a, b) * query(node*2+1, m+1, r, a, b);
    }

    void update(int node, int l, int r, int pos, int val) {
        assert(l <= pos && pos <= r);

        if(l == r) {
            if(val > 0) val = 1;
            else if(val < 0) val = -1;
            
            st[node] = val;
            return;
        }

        int m = (l+r)/2;
        if(pos <= m)
            update(node*2, l, m, pos, val);
        else
            update(node*2+1, m+1, r, pos, val);

        st[node] = st[node*2] * st[node*2+1];
    }

    void init(int node, int l, int r, const vector<int>& v) {
        if(l == r) {
            int val = v[l];
            if(val > 0) val = 1;
            else if(val < 0) val = -1;

            st[node] = val;
            return;
        }

        int m = (l+r)/2;
        init(node*2, l, m, v);
        init(node*2+1, m+1, r, v);

        st[node] = st[node*2] * st[node*2+1];
    }
};


bool solve() {
    int n; cin >> n;
    if(!cin)
        return false;
    
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];
    
    segtree st(v);

    string s;
    while(cin >> s, s != "FIN") {
        if(s[0] == 'C') {
            int p, v;
            cin >> p >> v;

            st.update(p-1, v);
        } else if(s[0] == 'P') {
            int a, b;
            cin >> a >> b;
            int r = st.query(a-1, b-1);

            cout << "-0+"[(r>0) - (r<0) + 1];
        }
    }

    cout << "\n";

    return true;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(solve());
    return 0;
}
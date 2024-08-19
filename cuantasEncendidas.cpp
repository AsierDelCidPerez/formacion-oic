#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

inline int IZQD(int n){return 2*n;};
inline int DCHA(int n){return 2*n+1;};

struct sTree {
    private:
        vector<int> st;
        int numElems;
        vector<int> pending;
        
        int query(int node, int l, int r, int a, int b){
            assert(r >= a || l <= b);
            if(l == r){
                return st[node];
            }
            if(a <= l <= r <= b){
                return st[node];
            }
            int m = (l+r)/2;
            int izqd, dcha;
            if(a <= m){
                izqd = query(IZQD(node), l, m, a, b);
            }
            if(b >= m+1){
                dcha = query(DCHA(node), m+1, r, a, b);
            }

            if(b <= m) return izqd;
            if(a >= m+1) return dcha;

            return izqd + dcha; // OP
        }

        void init(int node, vector<int> const & arr, int l, int r){
            if(l == r){
                st[node] = arr[l];
            }
            int m = (l+r)/2;
            init(IZQD(node), arr, l, m);
            init(DCHA(node), arr, m+1, r);
            st[node] = st[IZQD(node)] + st[DCHA(node)]; // OP
        }

        void addPendingRequest(int node, int val){
            pending[node] += val;
        }

        void solvePendingRequests(int node, int l, int r){
            if(pending[node] == 0) return;
            st[node] += pending[node] * (r-l+1);
            int m = (l+r)/2;
            if(l != r){
                int m = (l+r)/2;
                addPendingRequest(IZQD(node), pending[node]);
                addPendingRequest(DCHA(node), pending[node]);
            }
            pending[node] = 0;
        }

        void update(int node, int l, int r, int a, int b, int newValue){
            
            if(l == r){
                st[node] = newValue;
            }
        }

    public:
        sTree(int n) : st(4*n, 0), numElems(n) {}
        
        sTree(vector<int> arr) : st(arr.size(), 0), numElems(arr.size()){
            init(1, arr, 0, numElems-1);
        };

        int query(int a, int b){
            return query(1, 0, numElems-1, a, b);
        }

        void update(int a, int b, int newValue){
            update(1, 0, numElems-1, a, b, newValue);
        }

};

int main(){

}
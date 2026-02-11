#include <bits/stdc++.h>
using namespace std;
 
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
 
template<class T = int> struct BIT{
    vector<T> tree;
    int n;
    void init(int n){
        this->n = n;
        tree.assign(n , 0);
    }
    void add(int pos , T val){
        for(pos++; pos <= n ; pos += (pos & (-pos)))
            tree[pos - 1] += val;
    }
    T pre(int pos){
        T ret = 0;
        for(pos++; pos ; pos -= (pos & (-pos)))
            ret += tree[pos - 1];
        return ret;
    }
    T sum(int l , int r){ return pre(r) - pre(l - 1); }
    T sum(int i){ return sum(i , i); }
};
 
void solve(){
    int n, q; cin >> n >> q;
    vector<int> a(n);
 
    BIT<long long> pre;
    pre.init(n + 1);
 
    for(int i = 0; i < n; i++) cin >> a[i];
 
    for (int i = 0; i < n; i++) {
        pre.add(i, a[i]);
        pre.add(i + 1, -a[i]);
    }
 
    while(q--){
        int op; cin >> op;
        
        if(op == 1){
            long long a, b, u; cin >> a >> b >> u;
            a--; b--;
            pre.add(a, u);
            pre.add(b+1, -u);
        }
 
        else{
            long long k; cin >> k;
            k--;
            long long val = pre.pre(k);
            cout << val << endl;
        }
    }
}
 
int32_t main(){
    FastIO();
    solve();
    return 0;
}
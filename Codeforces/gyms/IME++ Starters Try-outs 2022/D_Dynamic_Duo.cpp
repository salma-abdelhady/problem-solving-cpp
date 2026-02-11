#include <bits/stdc++.h>
using namespace std;

void FastIO(){ ios_base::sync_with_stdio(false); cin.tie(0);}
void UseFile(){freopen("divsnums.in", "r", stdin);}
const int MOD = 1000000007;
const int sz = 2e5+10;


// O(Log n)
// 1-based
template<class T = int> struct BIT{
    vector<T> tree;
    int n;
    void init(int n){
        this->n = n;
        tree.assign(n, 0);
    }
    void add(int pos , T val){
        while(pos <= n){
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
    T pre(int pos){
        T ret = 0;
        while(pos > 0){
            ret += tree[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
    T sum(int l , int r){ return pre(r) - pre(l - 1); }
    T sum(int i){ return sum(i , i); }
};

void solve(){
    int n, q; cin >> n >> q;

    BIT<long long> pre;
    pre.init(n + 2);

    while(q--){
        char c; cin >> c;

        if(c == '!'){
            long long l, r,x; cin >> l >> r >> x;
            pre.add(l,x);
            pre.add(r+1,-x);
        }

        else{
            long long p, x; cin >> p >> x;

            long long s = pre.pre(p);

            if(s >= x){
                cout << "yes sir\n";
                pre.add(p, -x);
                pre.add(p+1, x);
            }
            else{
                cout << "negative\n";
            }
        }
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
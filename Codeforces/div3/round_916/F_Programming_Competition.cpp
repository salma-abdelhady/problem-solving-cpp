#include <bits/stdc++.h>

using namespace std;

#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
#define dpp(arr,val) memset(arr,val,sizeof(arr))
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
void UseFile(){freopen("divsnums.in", "r", stdin);}
const int MOD = 1000000007;
const int sz = 2e5+10;
const double PI = 3.14159265358979323846;

int n, L[sz];
vi adj[sz];

void dfs(int n, int lvl){
    L[lvl]++;
    for(auto it:adj[n]) 
       dfs(it, lvl+1);
}

void solve(){
    int t; cin >> t;

    while(t--){
        cin >> n;
        for(int i = 2; i <= n; i++){
            int x; cin >> x;
            adj[x].push_back(i);
        }

        dfs(1,0);
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++){
            if(L[i] + sum > 1){
                ans ++;
                sum += L[i]-2;
            }
        }
        cout << ans + sum/2 << endl;
        for(int i = 0; i<=n; i++){
            adj[i].clear();
            L[i] = 0;
        }
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
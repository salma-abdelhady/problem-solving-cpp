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

void solve(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vi a(n), dp(n+1, 1e9);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            dp[a[i]] = 1;
        }

        sort(all(a));
        a.erase(unique(all(a)),a.end());

        for(int i = 1; i <=n; i++){
            if(dp[i] == 1e9) continue;

            for(int j = 0; j < a.size(); j++){
                if(1ll*i * a[j] > n) break;

                if(dp[i] + 1 < dp[1ll * i * a[j]]){
                    dp[i * a[j]] = dp[i] + 1;
                }
            }
        }

        for(int i = 1; i <= n; i++){
            if(dp[i] == 1e9) cout << -1 << " ";
            else cout << dp[i] << " ";
        }
        cout << endl;

    }

}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
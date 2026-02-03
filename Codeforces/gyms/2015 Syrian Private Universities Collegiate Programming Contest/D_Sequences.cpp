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

int dp[20006];

void solve(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        memset(dp, 0, sizeof dp);
        int ans = 0;

        while(n--){
            int x; cin >> x;

            dp[x] = max(dp[x-1]+1, dp[x]);
            ans = max(ans,dp[x]);
        }

        cout << ans << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
    int n; cin >> n;

    vi a(n); cin >> a;

    vector<vi> dp(n, vi(2,-1));

    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
        if(i-1 >= 0 && a[i] > a[i-1]){
            dp[i][0] = max(dp[i][0], dp[i-1][0] + 1);
            dp[i][1] = max(dp[i][1], dp[i-1][1] + 1);
        }

        if(i-2 >= 0 && a[i] > a[i-2]){
            dp[i][1] = max(dp[i][1], dp[i-2][0] + 1);
        }
    }

    int ans = INT_MIN;

    for(int i = 0; i < n; i++){
        ans = max({ans, dp[i][0], dp[i][1]});
    }

    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}

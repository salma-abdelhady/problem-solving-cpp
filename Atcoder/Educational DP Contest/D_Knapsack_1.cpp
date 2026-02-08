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
    int n, w; cin >> n >> w;

    vi weg(n), val(n);
    for(int i = 0; i < n; i++){
        cin >> weg[i] >> val[i];
    }

    // dp[i][j] -> max total value tell index i with total weight <= j
    vector<vi> dp(n, vi(w+1,0));
    if(w - weg[0] >= 0) dp[0][weg[0]] = val[0];

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= w; j++){
            // leave
            dp[i][j] = dp[i-1][j];

            // take
            if(j - weg[i]>= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j - weg[i]] + val[i]);
            }
        }
    }

    int ans = INT_MIN;
    for(int j = 0; j <= w; j++){
        ans = max(ans, dp[n-1][j]);
    }

    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
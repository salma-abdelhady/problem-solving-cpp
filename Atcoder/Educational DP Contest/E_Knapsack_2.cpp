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

    // dp[i] -> min weg with value v
    vi dp(1e6, 1e9+2);

    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 1e6; j >= val[i]; j--){
            dp[j] = min(dp[j] , dp[j - val[i]] + weg[i]);
        }
    }

    int ans = 0;
    for(int i = 1e6-1; i >=0; i--){
        if(dp[i] != 1e9+2 && dp[i] <= w){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
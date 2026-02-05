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

    vi h(n); cin >> h;

    vi dp(n, 1e9);

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(i+2 < n){
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
        }

        if(i+1 < n){
            dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        }

    }
    cout << dp[n-1] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
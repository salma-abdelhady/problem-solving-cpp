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

    vi c(n); cin >> c;

    string s[n], sr[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        sr[i] = s[i];
        reverse(all(sr[i]));
    }

    vector<vi> dp(n, vi(2, 1e18));

    dp[0][0] = 0;
    dp[0][1] = c[0];

    for(int i = 1; i < n; i++){

        if(s[i] >= s[i-1]){
            dp[i][0] = min(dp[i-1][0], dp[i][0]);
        }

        if(s[i] >= sr[i-1]){
            dp[i][0] = min(dp[i-1][1], dp[i][0]); 
        }

        if(sr[i] >= s[i-1]){
            dp[i][1] = min(dp[i][1], dp[i-1][0] + c[i]);
        }

        if(sr[i] >= sr[i-1]){
            dp[i][1] = min(dp[i][1], dp[i-1][1] + c[i]);
        }
    }

    int ans = *min_element(all(dp[n-1]));

    if(ans != 1e18) cout << ans << endl;
    else cout << -1 << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}

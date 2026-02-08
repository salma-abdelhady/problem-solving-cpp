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

/*
1- Determine the state: 
take/leave
2- Define the dp:
dp[i][j] = max pages till i books with total price <= j
3- Find the transition:
dp[i][j] = max(dp[i][j], dp[i][j - h[i]] + s[i])
4- base case:
dp[0][j] = 0
dp[i][0] = 0
5- stored in dp[n][x]
*/

void solve(){
    int n, x; cin >> n >> x;
    vi h(n), s(n); cin >> h >> s;

    vector<vi> dp(n+1, vi(x+1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            // leave
            dp[i][j] = dp[i-1][j];

            // take
            if(j - h[i-1] >= 0){
                dp[i][j] = max(dp[i][j], dp[i-1][j - h[i-1]] + s[i - 1]);
            }
        }
    }

    cout << dp[n][x] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
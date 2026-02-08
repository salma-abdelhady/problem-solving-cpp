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
i: current sum
2- Define the dp:
dp[i] -> min no. of coins to sum i
3- Find the transition:
dp[i] = loop dp[i] = min(dp[i - c[j] ]+ 1), j is the idx pf coins vector
4- base case:
dp[0] = 0;
5- stored in dp[x]
*/

void solve(){
    int n, x; cin >> n >> x;
    vi c(n); cin >> c;

    vi dp(x + 2, 1e18);
    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    if(dp[x] != 1e18) cout << dp[x] << endl;
    else cout << -1 << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
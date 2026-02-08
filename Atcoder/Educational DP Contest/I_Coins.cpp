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
(i, j) -> after i coins, j heads
2- Define the dp:
dp[i][j] -> prob of getting j(no. of heads) from i number of coins
3- Find the transition:
dp[i][j] = dp[i-1][j] * (1-p[i]) + dp[i-1][j-1] * p[i];
4- base case:
dp[0][0] = 1
5- answer is stored in sum of dp[n][h], for all h > n/2 since number of heads 
must be greater than tails 
*/

void solve(){
    int n; cin >> n;

    vector<double> p(n); cin >> p;

    vector<vector<double>>dp(n ,vector<double>(n,0.0));
    dp[0][0] = 1;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            dp[i][j] = dp[i-1][j] * (1-p[i]) + dp[i-1][j-1] * p[i];
        }
    }

    double sum = 0;

    for(int j = n/2; j < n; j++){
        sum += dp[n-1][j];
    }

    cout << sum << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
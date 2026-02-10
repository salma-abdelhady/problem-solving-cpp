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
sum till now
2- Define the dp:
dp[i] -> no. of ways for sum i
3- Find the transition:
dp[i] = dp[i-1] + dp[i-2] + .. + dp[i-6]
4- base case:
dp[0] = 1
5- answer stored in dp[n]
*/

void solve(){
    int n; cin >> n;

    vi dp(n+1, 0);
    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i-j >= 0) dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
i -> where the frog stand now
2- Define the dp:
dp[i] = loop(min(dp[i+j] + pow((h[i]-h[j]), 2) + c)
min cost to reach n from i
3- Find the transition:
i+1, i+2, ..
4- base case:
dp[0] = 0
5- answer in dp[n-1]
*/

void solve(){
    int n, c; cin >> n >> c;

    vi h(n); cin >> h;

    vi dp(n, 1e18);
    dp[0] = 0;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            dp[i] = min(dp[i], dp[j] + ((h[i] - h[j]) * (h[i] - h[j]) + c));
        }
    }

    cout << dp[n-1] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
(i, j) -> either is '.' or '#'
2- Define the dp:
dp[i][j] -> no. of ways to (i,j) where a[i][j] == '.'
3- Find the transition:
dp[i][j] = dp[i-1][j]+ 1, dp[i][j-1]+1
4- base case:
dp[0][0] = 1
5- answer is stored in dp[n-1][m-1]
*/

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> a(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    vector<vi> dp(n,vi(m,0));
    dp[0][0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '#') continue;
            if(i >= 1 && a[i-1][j] == '.'){
                dp[i][j] += dp[i-1][j];
            }

            if(j >= 1 && a[i][j-1] == '.'){
                dp[i][j] += dp[i][j-1];
            }

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n-1][m-1] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
(i, j) -> i: s index, j: t index
2- Define the dp:
dp[i][j] : max length of subsequence tell index i in s and index j in t
3- Find the transition:
s[i] == t[j]: dp[i][j] = 1 + dp[i+1][j+1]
dp[i][j] = max(dp[i][j+1], dp[i+1][j])
4- base case:
reaching the end of string
dp[s.size()-1][0..t.size()-1] = 0
dp[0..s.size()-1][t.size()-1] = 0
5- answer is retrived by backtracing
*/

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();

    vector<vi> dp(n+1, vi(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i - 1] == t[j - 1]){
                dp[i][j] = 1 + (dp[i-1][j-1]);
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // Backtrack:
    string ans = "";
    while(n && m){
        if(s[n-1] == t[m-1]){
            ans += s[n-1];
            n--; m--;
        }
        else if(dp[n-1][m] > dp[n][m-1]) n--;
        else m--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
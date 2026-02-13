#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}

/*
1- Determine the state: 
pos in the strings
2- Define the dp:
dp[i][j] = n of operations till (i,j) for the two strings to be equal
3- Find the transition:
+1 char : dp[i][j] = d[i][j-1] + 1
-1 char: dp[i][j] = dp[i-1][j] + 1
replace: dp[i][j] = dp[i-1][j-1] + 1(if not equal)
4- base case:
dp[0][0] = 0
5- answer stored in dp[n][m]
*/

void solve(){
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 1e9));

    dp[0][0] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i > 0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);

            if(j > 0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);

            if (i > 0 && j > 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s[i-1] != t[j-1]));
        }
    }

    cout << dp[n][m] << endl;

}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
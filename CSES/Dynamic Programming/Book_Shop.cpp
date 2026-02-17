#include <bits/stdc++.h>

using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}


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
    vector<int> h(n), s(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

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

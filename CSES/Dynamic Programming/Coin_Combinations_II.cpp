#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int MOD = 1000000007;

/*
1- Determine the state: 

2- Define the dp:
dp[i][j] = number of ways for sum j for i first coins
3- Find the transition:
// leave
dp[i][j] = dp[i-1][j]
// take
dp[i][j] += dp[i][j-coins[i-1]]
4- base case:
dp[0][0] = 0
5- answer stored in dp[n][x]
*/
void solve(){
    int n, x; cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<vector<int>> dp(n+1, vector<int> (x+1,0));
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];

            if(j - coins[i-1] >= 0) dp[i][j] += dp[i][j- coins[i-1]];

            dp[i][j] %= MOD;
        }
    }

    cout << dp[n][x] << endl;

}

int32_t main(){
    FastIO();
    solve();
    return 0;  
}
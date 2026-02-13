#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int MOD = 1000000007;

/*
1- Determine the state: 
pos i, val j
2- Define the dp:
dp[i][j] = n.of ways till i element with val j
3- Find the transition:
dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]
4- base case:
if a[0] == 0 dp[0][a[0]] = 1
else dp[0][j] = 1
5- answer stored sum all d[n-1][j] 
*/
void solve(){
    int n, m; cin >> n >> m;

    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(m+1,0));

    if(a[0] == 0){
        for(int i = 1; i <= m; i++){
            dp[0][i] = 1;
        }
    }
    else{
        dp[0][a[0]] = 1;
    }

    for(int i = 1; i < n; i++){
        if(a[i] == 0){
            for(int j = 1; j <= m; j++){            
                dp[i][j] = dp[i-1][j];
                dp[i][j] %= MOD;

                if(j > 1) dp[i][j] += dp[i-1][j-1];
                dp[i][j] %= MOD;

                if(j < m) dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        }
        else{
            dp[i][a[i]] = dp[i-1][a[i]];

            if(a[i] > 1) dp[i][a[i]] += dp[i-1][a[i]-1];
            dp[i][a[i]] %= MOD;

            if(a[i] < m) dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]] %= MOD;
        }
    }

    long long ans = 0;
    for(int i = 1; i <= m; i++){
        ans += (dp[n-1][i]);
        ans %= MOD;
    }

    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;  
}
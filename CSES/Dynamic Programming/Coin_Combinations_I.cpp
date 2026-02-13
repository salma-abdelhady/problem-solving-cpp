#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int MOD = 1000000007;

/*
1- Determine the state: 
sum till now
2- Define the dp:
dp[i] = number of ways for sum of i
3- Find the transition:
dp[i] += dp[i- coins[j]]
4- base case:
d[0] = 1 as the empty set is the only way to sum = 0
5- answer stored in dp[x]
*/
void solve(){
    int n, x; cin >> n >> x;

    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x+1, 0);
    
    dp[0] = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - coins[j] >= 0) dp[i] += dp[i - coins[j]];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << endl;

}

int32_t main(){
    FastIO();
    solve();
    return 0;  
}
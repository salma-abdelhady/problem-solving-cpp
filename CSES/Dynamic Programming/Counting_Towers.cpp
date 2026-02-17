#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
const int mod = 1000000007;
/*
1- Determine the state: 
state horizontal/vertical move
2- Define the dp:
dp[i][j] = number of ways to fill from idx 0 to idx i
j = 0 or 1
0: width of block is 1
1: width of block is 2
3- Find the transition:
dp[i][0] = 4 * dp[i-1][0] + dp[i-1][1]
dp[i][1] = 2 * dp[i-1][1] + dp[i-1][0]
4- base case:
dp[1][0] = 1
dp[1][1] = 1
5- answer stored dp[n][0] + dp[n][1]
*/

void solve(){
    int t; cin >> t;

    vector<vector<long long>>dp(1e6+1,vector<long long>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= 1e6; i++){
        dp[i][0] = (4LL * ( dp[i-1][0] % mod) % mod)+ dp[i-1][1] % mod;
        dp[i][1] = (2LL * ( dp[i-1][1] % mod) ) + dp[i-1][0] % mod;
    }

    while(t--){
        long long n; cin >> n;
        cout << (dp[n][0] % mod + dp[n][1] % mod) % mod << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
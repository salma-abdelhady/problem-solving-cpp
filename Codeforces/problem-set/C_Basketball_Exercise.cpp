#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void solve(){
    long long n; cin >> n;
    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<long long>> dp(n+1, vector<long long>(2,0));
    //dp[0][0] = 0;
    //dp[0][1] = 0;

    for(int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + b[i-1]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + a[i-1]);
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}

/*
1- Determine the state: 
sum of numbers 
2- Define the dp:
dp[i][j] = true/false -> possible or not to make x using first i coins
3- Find the transition:
dp[i][j] = dp[i-1][j]

if(j - a[i-1] >= 0 && dp[i-1][j-a[i-1]]) dp[i][j] = true
4- base case:
all false;
5- answer stored in sum and values of true dp
*/
void solve(){
    int n; cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<vector<bool>> dp(n+1, vector<bool>(n * 1000 + 1, false));
    dp[0][0] = true;

    for(int i = 1; i <= n ; i++){
        for(int j = 0; j <= n * 1000 + 1; j++){
            dp[i][j] = dp[i-1][j];
            
            if(j - a[i-1] >= 0 && dp[i-1][j-a[i-1]]) dp[i][j] = true;
            
        }
    }

    vector<int> sums;
    for(int i = 1; i <= n * 1000 + 1; i++){
        if(dp[n][i]){
            sums.push_back(i);
        }
    }

    cout << sums.size() << endl;

    for(int i = 0; i < sums.size(); i++){
        cout << sums[i] << ' ';
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
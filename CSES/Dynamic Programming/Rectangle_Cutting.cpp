#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}

/*
1- Determine the state: 
(i,j)
2- Define the dp:
dp[i][j] = min moves to cut i*j rectangles into squares
3- Find the transition:
Horizontal cut: 1 to i
dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1)
vertical cut: 1 to j
dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1)
4- base case:
i == j dp[i][j] = 0
5- answer stored in dp[a][b];
*/

void solve(){
    int a,b ; cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(i == j){
                dp[i][j] = 0;
            }
        }
    }

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){
            if(dp[i][j] == 0) continue;

            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }

            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
        }
    }

    cout << dp[a][b] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}



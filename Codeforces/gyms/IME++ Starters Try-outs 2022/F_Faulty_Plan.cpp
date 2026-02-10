#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}

/*
1- Determine the state: 
rem f points, d points
2- Define the dp:
dp[i][j][k] = max skipped days
i -> day no.
j -> french points
k -> dutch points
3- Find the transition:
// leave = attend:
dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j][k])
// take = skip the day
tf  = j + 3 * Pf[i-1]
tdu = k + 3 * Pd[i-1]
dp[i][tf][tdu] = max(dp[i][tf][tdu] , dp[i-1][j][k] + 1)
only if tf < 50, tdu < 50, tf+tdu < 90
4- base case:
dp[0][0][0] = 0;
5- stored in max(dp[n][j][k])
*/

void solve(){
    int n; cin >> n;

    int mx = 80 - n;

    vector<int> days(n), pf(n), pd(n);

    for(int i = 0; i < n; i++){
        cin >> days[i] >> pf[i] >> pd[i];
    }

    int dp[n+1][50][50];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 50; j++){
            for(int k = 0; k < 50; k++){
                dp[i][j][k] = -1e9;
            }
        }
    }

    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++){
        int tf = 3 * pf[i-1];
        int td = 3 * pd[i-1];

        int tp = tf + td;

        for(int j = 0; j < 50; j++){
            for(int k = 0; k < 50; k++){
                dp[i][j][k] = max(dp[i][j][k] , dp[i-1][j][k]);

                if(tf + j < 50 && td + k < 50 && tf + j + td + k < 90){
                    dp[i][tf + j][td + k] = max(dp[i][tf + j][td + k], dp[i-1][j][k] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < 50; j ++){
        for(int k = 0; k < 50; k++){
            ans = max(ans, dp[n][j][k]);
        }
    }

    cout << ans + mx << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
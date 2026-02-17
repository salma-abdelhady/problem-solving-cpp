#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

/*
1- Determine the state: 
idx i in a and idx j in b
2- Define the dp:
dp[i][j] -> from i in a and j in b the longest sub
3- Find the transition:
a[i] == b[j]: dp[i][j] = 1 + dp[i+1][j+1]
dp[i][j] = max(dp[i][j+1], dp[i+1][j])
4- base case:
dp[n-1][0..m-1] = 0
dp[0..n-1][m-1] = 0
5- answer is retrieved by backtracking
*/

void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = 1 + (dp[i-1][j-1]);
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // Backtrack:
    vector<int> ans;
    int i = n, j = m;
    while(i && j){
        if(a[i-1] == b[j-1]){
            ans.push_back(a[i-1]);
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";

}
int32_t main(){
    FastIO();
    solve();
    return 0;
}

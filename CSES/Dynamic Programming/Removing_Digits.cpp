#include <bits/stdc++.h>

using namespace std;

#define int    long long
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v) v.begin(), v.end()
#define dpp(arr,val) memset(arr,val,sizeof(arr))
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}
void UseFile(){freopen("divsnums.in", "r", stdin);}
const int MOD = 1000000007;
const int sz = 2e5+10;
const double PI = 3.14159265358979323846;
/*
1- Determine the state: 
current number
2- Define the dp:
dp[i] -> min moves to make i = 0
3- Find the transition:
dp[i] = min(dp[i], dp[i - d] + 1) for all digits in num
4- base case:
dp[0] = 0
5- answer stored in dp[n];
*/

void solve(){
    int n; cin >> n;

    vi dp(n+1, INT_MAX);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int num = i;
        while(num > 0){
            int d = num % 10;
            num /= 10;

            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n] << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
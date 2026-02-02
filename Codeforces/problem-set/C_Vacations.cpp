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

int n;
// vector<pii> days= {{0,0}, {0,1}, {1,0}, {1,1}};
vi a;

int dp[101][3];

int rec(int i, int pos){
    if(i >= n) return 0;
    
    int &ret = dp[i][pos];

    if(ret != -1) return ret;
    
    ret = 1 + rec(i+1, 0);

    if(a[i] == 1 && pos != 2){
        ret = min(ret, rec(i+1, 2));
    }

    else if(a[i] == 2 && pos != 1){
        ret = min(ret, rec(i+1, 1));
    }

    else if(a[i] == 3){
        if(pos != 1) ret = min(ret, rec(i+1, 1));
        if(pos != 2) ret = min(ret, rec(i+1, 2));
    }

    return ret;
}
void solve(){
    cin >> n;
    a.resize(n); cin >> a;

    memset(dp, -1, sizeof(dp));

    int ans = rec(0,0);

    cout << ans << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}

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

void solve(){
    int t; cin >> t;

    while(t--){
        int n, k; cin >> n >> k;

        vi a(n), b(n); cin >> a >> b;

        int ans = 0, sum = 0, mx = 0;
        for(int i = 0; i < min(n,k); i++){
            sum += a[i];
            mx = max(mx, b[i]);
            ans = max(ans, sum + max(0LL, (k-i-1) * mx));
        }

        cout << ans << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
    int n; cin >> n;

    int ta = 0, tb = 0, tc = 0, td = 0;

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(i % 4 == 1) ta += x;
        else if(i % 4 == 2) tb += x;
        else if(i % 4 == 3) tc += x;
        else if(i % 4 == 0) td += x;
    }

    if(ta >= tb && ta >= tc && ta >= td) cout << "A\n"; 
    else if(tb >= tc && tb >= td) cout << "B\n";
    else if(tc >= td) cout << "C\n";
    else cout << "D\n";   
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
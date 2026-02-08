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
    
    int xr, yr, xw, yw; cin >> xr >> yr >> xw >> yw;

    double x_diff_r = pow((xr - 0),2.0);
    double y_diff_r = pow((yr - 0),2.0);
    
    double x_diff_w = pow((xw - 0),2.0);
    double y_diff_w = pow((yw - 0),2.0);

    double dist1 = x_diff_r + y_diff_r;
    double dist2 = x_diff_w + y_diff_w;

    if(dist1 < dist2){
        cout << "Russo\n";
    }

    else if(dist1 > dist2){
        cout << "Wil\n";
    }

    else{
        cout << "Empate\n";
    }

}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
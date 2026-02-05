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
    int n; cin >>n;

    while(t--){
        int xc, yc, xt, yt; cin >> xc >> yc >> xt >> yt;
        
        if(xc == xt && yc == yt) cout << 0 << endl;
        
        else if((xc + yc) % 2 != (xt + yt) % 2) cout << "can't reach!\n";


        else if(abs(xc - xt) == abs(yc - yt)) cout << abs(xc - xt) << endl;

        else{
            int mi = INT_MAX;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(abs(xc-i) == abs(yc-j) && abs(xt-i) == abs(yt-j)){
                        mi = min(mi, abs(xc-i) + abs(xt-i));
                    }
                }
            }
            cout << mi << endl;  
        }
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
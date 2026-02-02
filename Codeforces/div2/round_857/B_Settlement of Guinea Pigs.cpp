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
        int n; cin >> n;

        vi a(n); cin >> a;

        if(count(all(a), 1) == n){
            cout << n << endl;
        }

        else if(count(all(a), 1) == 0){
            cout << 0 << endl;
        }

        else{
            int cnt = 0, ans = 0, n_empty = 0;
            int m = 0, f = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == 1){
                    cnt ++;
                    if(n_empty) n_empty --;
                    else ans ++;
                }
                else{
                    while(cnt > 0){
                        if(m && f){
                            m --;
                            n_empty ++;
                        }
                        else if(m){
                            f++;
                        }
                        else if(f){
                            m++;
                        }
                        else{
                            m++;
                        }
                        cnt --;
                    }
                }
            }
            cout << ans << endl;
        }
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
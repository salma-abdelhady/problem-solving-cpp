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

        sort(a.rbegin(), a.rend());

        int ans = 0;
        int count_neg = 0;

        for(int i = 0; i < n; i++){
            if(a[i] > 0){
                ans += 1;
                cout << ans << " ";
            }
            else{
                ans -= 1;
                cout << ans<< " ";
                count_neg ++;
            }
        }
        cout << endl;

        ans = 0;

        int c = n;
        int st = 0;
        for(int i = 0; i < count_neg; i++){
            cout << 1 << " " << 0 << " ";
            c -= 2;
        }

        for(int i = n - c ; i < n; i++){
            ans += 1;
            cout << ans << " ";
        }

        cout << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
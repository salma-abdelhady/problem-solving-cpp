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

        vector<pair<int,int>> s(n);

        multiset<int> ms;

        for(int i = 0; i < n; i++){
            cin >> s[i].first >> s[i].second;
            ms.insert(s[i].second);
        }

        sort(all(s));

        int ans = INT_MAX, mx = INT_MIN;

        for(int i = n-1; i >= 0; i--){
            ms.erase(ms.find(s[i].second));

            auto it = ms.lower_bound(s[i].first);

            if(it != ms.end()){
                ans = min(ans, abs(max(mx, *it) - s[i].first));
            }

            if(it != ms.begin()){
                --it;
                ans = min(ans, abs(max(mx, *it) - s[i].first));
            }

            mx = max(mx, s[i].second);
            ms.insert(s[i].second);
        }
        cout << ans << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
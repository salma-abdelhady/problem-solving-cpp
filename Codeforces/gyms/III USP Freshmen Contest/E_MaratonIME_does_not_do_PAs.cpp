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
    int n, s; cin >> n >> s;

    vector<pair<int,int>> t(n);

    for(int i = 0; i < n; i++){
        cin >> t[i].first >> t[i].second;
    }

    sort(all(t));

    int prev = s + t[0].first;
    int sum = prev - (t[0].second);

    for(int i = 1; i < n; i++){
        sum += (prev + t[i].first) - (t[i].second);
        prev += t[i].first;
    }

    cout << sum << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
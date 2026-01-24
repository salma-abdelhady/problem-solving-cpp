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

        vi a(n), b(n), c(n); cin >> a >> b >> c;

        vector<pair<int,int>> maxA, maxB, maxC;

        for(int i = 0; i < n; i++){
            maxA.push_back({a[i], i});
            maxB.push_back({b[i], i});
            maxC.push_back({c[i], i});
        }

        sort(maxA.rbegin(), maxA.rend());
        sort(maxB.rbegin(), maxB.rend());
        sort(maxC.rbegin(), maxC.rend());

        int mx = INT_MIN;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    set<int> idx;
                    int idxA = maxA[i].second;
                    int idxB = maxB[j].second;
                    int idxC = maxC[k].second;
                    idx.insert(idxA);
                    idx.insert(idxB);
                    idx.insert(idxC);

                    if(idx.size() == 3)
                       mx = max(mx, maxA[i].first + maxB[j].first + maxC[k].first);
                }   
            }
        }
        cout << mx << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
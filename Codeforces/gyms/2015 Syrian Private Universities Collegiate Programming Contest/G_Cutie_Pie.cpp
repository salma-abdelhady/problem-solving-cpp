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
void UseFile(){freopen("window.in", "r", stdin);}
const int MOD = 1000000007;
const int sz = 2e5+10;
const double PI = 3.14159265358979323846;

int n, m;
vector<vector<char>> arr;

string dest = "pie";

bool rec(int i, int j, int idx){
    if(i < 0 || i >= n || j < 0 || j >= m) return false;

    if(arr[i][j] != dest[idx]){
        return false;
    }

    if(idx == 2) return true;

    return rec(i+1, j, idx+1) || rec(i-1, j, idx+1) || rec(i, j+1, idx+1) || rec(i, j-1, idx+1) ||rec(i+1, j+1, idx+1) || rec(i-1, j-1, idx+1) || rec(i+1, j-1, idx+1) || rec(i-1, j+1, idx+1);
}

void solve(){
    int t; cin >> t;

    while(t--){
        cin >> n >> m;

        arr.assign(n, vector<char>(m));

        int st,en;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> arr[i][j];
            }
        }

        bool ans = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 'p' && !ans){
                    ans = rec(i,j,0);
                }
            }
        }

        if(ans) cout << "Cutie Pie!\n";
        else cout << "Sorry Man\n";
    }
}

int32_t main(){
    FastIO();
    //UseFile();
    solve();
    return 0;
}
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

vector<vector<char>> grid;
int n, m;

bool rec(int i, int j){
    if(j == n - 1 && grid[i][j] == '.') return true;
    if(i < 0 || i >= 3 || j < 0 || j >= n) return false;
    if(grid[i][j] == '#') return false;

    grid[i][j] = '#';

    return rec(i+1,j) || rec(i - 1, j) || rec(i, j + 1) || rec(i, j - 1)
    || rec(i-1,j-1) || rec(i+1, j+1) || rec(i-1,j+1) || rec(i+1,j-1);
}

void solve(){
    cin >> n >> m;
    
    grid.assign(3, vector<char>(n,'.'));

    while(m--){
        int idx; char s; cin >> idx >> s;
        idx--;
        if(s == 'S'){
            grid[2][idx] = '#';
            grid[1][idx] = '#';
            if(idx - 1 >= 0){
                grid[2][idx-1] = '#';
                grid[1][idx-1] = '#';
            }
            if(idx + 1 < n){
                grid[2][idx+1] = '#';
                grid[1][idx+1] = '#';
            }
        }

        if(s == 'M'){
            grid[1][idx] = '#';
            grid[2][idx] = '#';
            grid[0][idx] = '#';
            if(idx - 1 >= 0){
                grid[1][idx-1] = '#';
                grid[0][idx-1] = '#';
                grid[2][idx-1] = '#';
            }
            if(idx + 1 < n){
                grid[1][idx+1] = '#';
                grid[2][idx+1] = '#';
                grid[0][idx+1] = '#';
            }
        }

        if(s == 'H'){
            grid[0][idx] = '#';
            grid[1][idx] = '#';
            if(idx - 1 >= 0){
                grid[0][idx-1] = '#';
                grid[1][idx-1] = '#';
            }
            if(idx + 1 < n){
                grid[0][idx+1] = '#';
                grid[1][idx+1] = '#';
            }
        }
    }

    bool can = false;
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == '.'){
            can = rec(i,0);
            if(can){
                break;
            }
        }
    }
    if(can) cout << "Yes\n";
    else cout << "No\n";
}


int32_t main(){
    FastIO();
    solve();
    return 0;
}
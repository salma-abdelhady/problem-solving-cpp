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
    int q; cin >> q;
    
    vector<tuple<int,int,int>> cord;

    while(q--){
        char op; cin >> op;

        int x, y, r; cin >> x >> y >> r;
        int x_prev = 0, y_prev = 0, r_prev = 0;

        if(op == 'A'){
            bool ok = true;

            for(int i = 0; i < cord.size(); i++){
                int px = get<0>(cord[i]);
                int py = get<1>(cord[i]);
                int pr = get<2>(cord[i]);

                int dist = pow((x - px),2) + pow((y - py),2);
                int rad = pow(pr + r, 2);
                
                if(dist < rad){
                    ok = false;
                    break;
                }
            }

            if(ok){
                cord.push_back({x,y,r});
                cout << "Ok\n";
            }
            else{
                cout << "No\n";
            }
        }
        
        else if(op == 'R'){
            bool ok = false;

            for(int i = 0; i < cord.size(); i++){
                int px = get<0>(cord[i]);
                int py = get<1>(cord[i]);
                int pr = get<2>(cord[i]);
                
                if(px == x && py == y && pr == r){
                    cord.erase(cord.begin()+i);
                    ok = true;
                    break;
                }
            }

            if(ok){
                cout << "Ok\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
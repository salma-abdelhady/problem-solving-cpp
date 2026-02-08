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
    string s;
    getline(cin,s);

    string su = "Sussu";
    int idx = 0;

    bool q = (s.back() == '?');
    bool w = false;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == su[idx]){
            idx++;
        }
        else idx = 0;

        if(idx == 5 && (i+1 == s.size() || !isalpha(s[i+1])) && (i - 4 == 0 || !isalpha(s[i-5]))){
            w = true;
        }
    }

    if(!q && !w) cout << "O cara é bom!\n";
    else if(q) cout << 7 << endl;
    else if(w) cout << "AI SUSSU!\n";

}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
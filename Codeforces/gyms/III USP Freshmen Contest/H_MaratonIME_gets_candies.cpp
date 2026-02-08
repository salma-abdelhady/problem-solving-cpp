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
   int l = 1, r = 1e9;

   int q = 50;
   char ans;

   while(q--){
    int mid = l + (r - l) / 2;

    cout << "Q " << mid << endl;

    cout.flush();
    
    cin >> ans;
    
    if(ans == '>'){
        l = mid + 1;
    }
    else if(ans == '<'){
        r = mid - 1;
    }

    else break;
   }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
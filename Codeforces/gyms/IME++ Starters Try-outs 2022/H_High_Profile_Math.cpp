#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}
const int mod = 1e9+7;

long long extended_gcd(long long a, long long b, long long& x, long long& y){
   if(a == 0){
    x = 0; y = 1; return b;
   }
   long long x1, y1;
   long long gcd = extended_gcd(b % a, a , x1, y1);
   x = y1 - (b / a) * x1;
   y = x1;
   return gcd;
}

long long inverse(long long a, long long b){
    long long x, y;
    long long g = extended_gcd(a, b, x , y);
    if(g != 1) return -1;
    x = x % b + b;
    return x % b;
}

void solve(){
    int n, m; cin >> n >> m;

    vector<long long> sum(n+1, 0), cnt(n+1, 0);

    for(int i = 0; i < m; i++){
        int a; double b; cin >> a >> b;
        sum[a] += b;
        cnt[a] ++;
    }

    long long ans = 0;
    for(int i = 1; i <= n; i++){
        long long inv = inverse(cnt[i], mod);
        ans = (ans + sum[i] % mod * inv) % mod; 
    }

    cout << ans << endl;

}

int32_t main(){
    FastIO();
    solve();
    return 0;
}

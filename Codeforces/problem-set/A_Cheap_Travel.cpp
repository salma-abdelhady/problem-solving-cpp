#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void solve(){
    int n, m, a, b; cin >> n >> m >> a >> b;
    
    if(b > a * m){
        cout << n * a << endl;
    }

    else{
        int op = (n / m) * b;
        int rem = n % m;

        cout << op + min(rem * a, b);
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void solve(){
    string n; cin >> n;

    int i = n.size()-1;

    while(i >= 0){

        int d = n[i] - '0';
        int invert = 9 - d;

        if(invert == 0 && i == 0){
            i--;
            continue;
        }

        if(invert < d) n[i] = invert + '0';

        i--;
    }

    cout << n << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
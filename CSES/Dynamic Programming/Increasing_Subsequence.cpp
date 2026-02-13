#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false); cin.tie(nullptr);}

void solve(){
    int n; cin >> n;

    vector<int>dp;

    for(int i = 0; i < n; i++){
        int x; cin >> x;

        auto it = lower_bound(dp.begin(), dp.end(), x);

        if(it == dp.end()){
            dp.push_back(x);
        }
        else{
            // replace to maintain the sequence increasing with largest size as possible 
            *it = x;
        }
    }

    cout << dp.size() << endl;
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void solve(){
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> a(n);

        map<int, int> mp;
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ans += mp[a[i] - i];
            mp[a[i] - i]++;
        }

        cout << ans << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
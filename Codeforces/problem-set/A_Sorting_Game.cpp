#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void solve(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());

        if(s == sorted_s){
            cout << "Bob\n";
            continue;
        }

        vector<int> indx;
        for(int i = 0; i < n; i++){
            if(s[i] != sorted_s[i]){
                indx.push_back(i+1);
            }
        }

        cout << "Alice\n";
        cout << indx.size() << endl;
        for(int i = 0; i < indx.size(); i++){
            cout << indx[i] << " ";
        }
        cout << endl;
    }
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
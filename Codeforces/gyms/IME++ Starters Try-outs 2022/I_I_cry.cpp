#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define vi     vector<int>
#define pii    pair<int, int>
#define all(v)    v.begin(),v.end()
#define rall(v)    v.rbegin(),v.rend()
#define endl "\n"
template<typename T> ostream& operator<<(ostream& os, vector<T>& v){for (auto& i : v) os << i << ' ';return os;}
template<typename T> istream& operator>>(istream& is, vector<T>& v){for (auto& i : v) is >> i;return is;}
void fastIO(){
    ios_base::sync_with_stdio(false);

    cin.tie(0);
}
int32_t main(){
    fastIO();
    string s;cin>>s;
    int n=s.size()-1;
    int counte=0,countf=0;
    if(s[0]=='E'){
        cout<<"I cry\n";
        return 0;
    }
    for(int i=n;i>=0;i--){
        if(s[i]=='E'){
            counte++;
            countf=0;
        }
        else{
            if(counte>0) counte--;
            else{
                countf++;
            }
        }
    }
    if(counte>0) cout<<"I cry\n";
    else cout<<countf<<endl;
    return 0;
}
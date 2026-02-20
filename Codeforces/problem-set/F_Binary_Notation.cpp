#include <bits/stdc++.h>
using namespace std;

void FastIO(){ios_base::sync_with_stdio(false);cin.tie(nullptr);}

void printInBase(int x, int y)
{
   if ( x < y )
   {
      cout << x;
      return;
   }
 
   int rem = x%y;
   printInBase(x/y, y);
   cout << rem;
}

void solve(){
    int n; cin >> n;
    printInBase(n,2);
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
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
    int n; cin >> n;

    string s; cin >> s;

    vector<vi> seats(n, vi(4,1));

    int w = 2 * n;
    int ans = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'I')
        {
            if (w > 0)
            {
                for (int j = 0; j < n; j++)
                {
                    if (seats[j][0])
                    {
                        ans += (2 * (n - j - 1)) + 10;
                        seats[j][0] = 0;
                        w--;
                        break;
                    }
                    else if (seats[j][3])
                    {
                        ans += (2 * (n - j - 1)) + 10;
                        seats[j][3] = 0;
                        w--;
                        break;
                    }
                }
            }
            else{
                for (int j = 0; j < n; j++)
                {
                    if (seats[j][1])
                    {
                        ans += (2 * (n - j - 1)) + 5;
                        seats[j][1] = 0;
                        break;
                    }
                    else if (seats[j][2])
                    {
                        ans += (2 * (n - j - 1)) + 5;
                        seats[j][2] = 0;
                        break;
                    }
                }
            }
        }

        else{
            for(int i = 0; i < n; i++){
                if(seats[i][0]){
                    ans += (2 * (n - i - 1)) + 10;
                    seats[i][0] = 0;
                    w--;
                    break;
                }
                else if(seats[i][3]){
                    ans += (2 *  (n - i - 1)) + 10;
                    seats[i][3] = 0;
                    w--;
                    break;
                }

                else if(seats[i][1]){
                    ans += (2 * (n - i - 1)) + 5;
                    seats[i][1] = 0;
                    break;
                }

                else if(seats[i][2]){
                    ans += (2 *(n - i - 1)) + 5;
                    seats[i][2] = 0;
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}
int32_t main(){
    FastIO();
    solve();
    return 0;
}
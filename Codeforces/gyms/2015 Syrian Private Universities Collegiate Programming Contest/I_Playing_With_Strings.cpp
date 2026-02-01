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
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vi freq(26);
        int n = s.size();
        if (s.size() == 1)
        {
            cout << s << endl;
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }
        int count1 = 0;
        for (int i = 0; i < 25; i++)
        {
            if (freq[i] > 0)
            {
                if (freq[i] % 2)
                    count1++;
            }
        }

        if ((count1 > 0 && n % 2 == 0))
        {
            cout << "impossible\n";
            continue;
        }
        if (count1 > 1)
        {
            cout << "impossible\n";
            continue;
        }

        int my1 = 0;
        bool m=false;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                if (freq[i] != 1)
                {
                    if(freq[i]%2){
                        my1=i;
                        freq[i]-1;
                        m=true;
                    }
                    freq[i] /= 2;
                    int k = freq[i];
                    while (k--)
                    {
                        cout << char(i + 'a');
                    }
                }
                else
                {
                    my1 = i;
                }
            }
        }
        if (n % 2)
        {
            cout << char(my1 + 'a');
            if(!m){
                freq[my1]=0;
        }
    }

        for (int i = 25; i >= 0; i--)
        {
            if (freq[i] > 0)
            {
                int k=freq[i];
                while (k--)
                {
                    cout << char(i + 'a');
                }
            }
        }
        cout << endl;
    }
    return 0;
}
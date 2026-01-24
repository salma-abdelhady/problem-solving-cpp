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

int n, s[sz];
vi adj[sz];

int a, b;
int powerOf2(int x)
{
  if(x == 0)return 0;
	return (x & (x - 1)) == 0;
}

string convertToBase(int x, int base)
{
    if (x == 0) return "0";

    string res = "";
    while (x > 0) {
        res += char((x % base) + '0');
        x /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

/*int fac(int n){
    int res = 1;
    for(int i = 2; i <= n; i++){
        res = (res * i) % mod;
    }
    return res;
}

void solve(){
    int t; cin >> t;
    while(t--){
        int n , r; cin >> n >> r;
        int res = fac(n) / (fac(n-r) * fac(r));
        cout << res << endl;
    }

}*/

/*void solve(){
    int n, r; cin >> n >> r;

    int ans = 1;
    for(int i = r + 1; i <= n; i++){
        ans = ((ans % mod) * (i % mod)) % mod;
        ans = ((ans % mod) / (i - r) % mod) % mod;
    }
    cout << ans << endl;
}*/

//return nCk mod p using naive recursion
//O(2^n)

int binomial(int n, int k, int p) {
	if (k == 0 || k == n) { return 1; }
	return (binomial(n - 1, k - 1, p) + binomial(n - 1, k, p)) % p;
}

// return nCk mod p using dynamic programming
//O(n^2)

int binomial_DP(int n, int k, int p) {
	// dp[i][j] stores iCj
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

	// base cases described above
	for (int i = 0; i <= n; i++) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		if (i <= k) { dp[i][i] = 1; }
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % p;
			}
		}
	}

	return dp[n][k];  // returns nCk modulo p
}

void suffix()
{
    string s; cin >> s;

    s += "$";

    int n = s.size();

    vector<int> p(n), c(n);

    vector<pair<char, int>> a(n);
    for(int i = 0; i < n; i++) a[i] = {s[i], i};

    sort(a.begin(),a.end());

    for(int i = 0; i < n; i++) p[i] = a[i].second;

    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(a[i].first == a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }
        else{
            c[p[i]] = c[p[i-1]]+1;
        }
    }

    int k = 0;
    while((1 << k) < n){
        vector<pair<pair<int,int>, int>> a(n);

        for(int i = 0; i < n; i++){
            a[i] = {{c[i], c[(i + (1 << k))%n]}, i};
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++) p[i] = a[i].second;

        c[p[0]] = 0;
        for(int i = 1; i < n; i++){
            if(a[i].first == a[i-1].first){
                c[p[i]] = c[p[i-1]];
            }
            else{
                c[p[i]] = c[p[i-1]]+1;
            }
        }
        k++;
    }

    for(int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
}

bool good(int num){
    while(num > 0){
        int digit= num % 10;
        if(digit != a && digit != b) return false;
        num /= 10;
    }
    return true;
}

// Combinatorics
int fastPow(int b, int p, int m){
  if(p == 0) return 1;
  int ans = fastPow(b, p/2, m);
  ans = ans * ans % m;
  if((p&1) == 1) ans = ans * b % m;
  return ans;
}

int modinv(int b, int p){
  return fastPow(b, p-2, p);
}

int nCr(vi &fact, vi &invFact, int n, int r){
  return ((fact[n] * invFact[n-r]) % MOD) * invFact[r] % MOD;
}

void dfs(int a, int b){
    for(auto it: adj[a]){
        if(it != b){
            dfs(it, a);
            s[a] += s[it];
        }
    }
}

void solve(){
    
}

int32_t main(){
    FastIO();
    solve();
    return 0;
}
class Solution {
public:
    vector<int> dp;

    Solution() : dp(38,-1) {}
    
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        int &ret = dp[n];
        if(ret != -1) return ret;

        return ret = tribonacci(n-1)+ tribonacci(n-2) + tribonacci(n-3);
    }
};
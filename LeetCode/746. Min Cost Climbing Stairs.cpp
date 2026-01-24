class Solution {
public:
    int n;
    vector<int> dp, c;

    int solve(int i){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int op1 = solve(i+1) + c[i];
        int op2 = solve(i+2) + c[i];

        return dp[i] = min(op1, op2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        c = cost;

        dp.assign(n+1, -1);

        return min(solve(0), solve(1));
    }
};
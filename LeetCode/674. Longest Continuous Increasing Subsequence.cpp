class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);  

        dp[0] = 1;

        for(int i = 1; i < n; i++){
            dp[i] = 1;
            if(nums[i] > nums[i-1]) dp[i] = max(dp[i], dp[i-1] + 1);
        }

        return *max_element(dp.begin(), dp.end());   
    }
};
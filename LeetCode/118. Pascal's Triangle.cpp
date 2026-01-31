class Solution {
public:
    vector<vector<int>>dp;

    int solve(int i, int j){
        if(i == j || j == 0) return 1;

        int &ret = dp[i][j];

        if(ret != -1) return ret;

        return ret =  solve(i-1,j-1) + solve(i-1, j);
    }
    
    vector<vector<int>> generate(int numRows) {
        dp.assign(numRows, vector<int>(numRows,-1));
        vector<vector<int>> ans;
        
        for(int i = 0; i < numRows; i++){
            vector<int> rows;
            for(int j = 0; j <= i; j++){
                rows.push_back(solve(i,j));
            }
            ans.push_back(rows);
        }
        return ans;
    }
};
// Dp solution:

class Solution {
public:
    vector<int> dp;

    bool solve(int n){
        if(n <= 1) return false;

        int &ret = dp[n];

        if(ret != -1) return ret;

        for(int i = 1; i < n; i++){
            if(n % i == 0 && !solve(n-i)){
                return ret = true;
            }
        }
        return ret = false;
    }

    bool divisorGame(int n) {
        dp.assign(n+1,-1);
        return solve(n);    
    }

};


// Math Trick solution:

class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }
};
class Solution {
public:
    int memo[46];
    int bottomUp(int n, vector<int>&dp){
        if(n == 1 || n == 2){
            return n;
        }  
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    int solveByMemoization(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int oneStep = solveByMemoization(n - 1);
        int twoStep = solveByMemoization(n - 2);
        return memo[n] = oneStep + twoStep;
    }
    int solveByRecursion(int n){
        if(n < 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        int oneStep = solveByRecursion(n - 1);
        int twoStep = solveByRecursion(n - 2);
        return oneStep + twoStep;
    }
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        memset(memo, -1, sizeof(memo));
        vector<int>dp(n + 1);
        return bottomUp(n, dp);
        //return solveByMemoization(n);
        // return solveByRecursion(n);
    }
};

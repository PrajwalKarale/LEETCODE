class Solution {
public:
    // int memo[13][10001];
    // int solve(vector<int>&coins, int amount, int index){
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(index < 0){
    //         return 1e9;
    //     }
    //     if(amount < coins[index]){
    //         return solve(coins, amount, index - 1);
    //     }
    //     if(memo[index][amount] != -1){
    //         return memo[index][amount];
    //     }
    //     int take  = 1 + solve(coins, amount - coins[index], index);
    //     int skip = solve(coins, amount, index - 1);
    //     return memo[index][amount] = min(take, skip);
    // }
    int solveByDP(vector<int>&coins, int amount){
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, 0));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }else{
                dp[0][i] = 1e9;
            }
        }
        for(int i = 1; i < coins.size(); i++){
            for(int am = 0; am <= amount; am++){
                int skip = dp[i - 1][am];
                int take = 1e9;
                if(coins[i] <= am){
                    take = 1 + dp[i][am - coins[i]];
                }
                dp[i][am] = min(take, skip);
            }
        }
        return dp[coins.size() - 1][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = coins.size();
        // memset(memo, -1, sizeof(memo));
        // int result = solve(coins, amount, n - 1);
        int result = solveByDP(coins, amount);
        return result >= 1e9 ? -1 : result;
    }
};

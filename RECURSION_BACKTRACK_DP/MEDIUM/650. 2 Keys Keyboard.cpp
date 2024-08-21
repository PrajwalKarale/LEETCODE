auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    // int memo[1001][1001];
    // int solve(int currentA, int clipA, int n){
    //     if(currentA == n){
    //         return 0;
    //     }
    //     if(currentA > n){
    //         return 1e9;
    //     }
    //     if(memo[currentA][clipA] != -1){
    //         return memo[currentA][clipA];
    //     }
    //     int copyAllAndPaste = 1 + 1 + solve(currentA + currentA, currentA, n);
    //     int paste = 1 + solve(currentA + clipA, clipA, n);
    //     return memo[currentA][clipA] = min(copyAllAndPaste, paste);
    // }
    // int solveByRecursionMemoization(int n){
    //     if(n == 1){
    //         return 0;
    //     }
    //     memset(memo, -1, sizeof(memo));
    //     // Initially we need to copy
    //     return 1 + solve(1, 1, n);
    // }
    int solveByBottomUp(int n){
        if(n == 1){
            return 0;
        }
        vector<int>dp(n+1);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            int largestFactor = i / 2;
            while(largestFactor >= 1){
                if(i % largestFactor == 0){
                    int stepsToLargestFactor = dp[largestFactor];
                    int copy = 1;
                    int paste = (i / largestFactor - 1);
                    dp[i] = stepsToLargestFactor + copy + paste;
                    break;
                }else{
                    largestFactor--;
                }
            }
        }
        return dp[n];
    }
    int minSteps(int n) {
        // return solveByRecursionMemoization(n);
        return solveByBottomUp(n);
    }
};

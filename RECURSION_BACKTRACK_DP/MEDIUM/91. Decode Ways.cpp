/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
/*
    Time Complexity
        1. solveByTabulation -> O(n)
    Space Complexity
        1. solveByTabulation -> O(n) dp array
*/
class Solution {
public:
    int solve(string s, int n, vector<int>&memo, int i){
        if(memo[i] != -1){
            return memo[i];
        }
        // If i reaches the last index that means it has found its way
        if(i == n){
            return memo[i] = 1;
        }
        if(s[i] == '0'){
            return memo[i] = 0;
        }
        int iThCharacter = solve(s, n, memo, i + 1);
        if(i+1 < n){
            if(s[i] == '1' || s[i] == '2' && s[i + 1] <= '6'){
                iThCharacter += solve(s, n, memo, i + 2);
            }
        }
        return memo[i] = iThCharacter;
    }
    int solveByRecursion(string s){
        int n = s.length();
        vector<int>memo(101, -1);
        return solve(s, n, memo, 0);
    }
    int solveByTabulation(string s){
        int n = s.length();
        vector<int>dp(n+1);
        dp[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }else{
                dp[i] = dp[i + 1];
                if(i + 1 < n){
                    if(s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')){
                        dp[i] = dp[i] + dp[i + 2];
                    }
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // return solveByRecursion(s);
        return solveByTabulation(s);
    }
};

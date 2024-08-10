/*
T.C -> O(n^2) which is achieved by recursion and memoization
S.C -> O(1001^2) since we have used space for memoization.

For bottom up approach:
T.C -> O(n^2)
s.C -> O(length of s ^ 2)
*/
class Solution {
public:
    // int memo[1001][1001];

    // bool checkPalindrome(string s, int i, int j){
    //     if(i >= j){
    //         return 1;
    //     }

    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
    //     if(s[i] == s[j]){
    //         return memo[i][j] = checkPalindrome(s, i + 1, j - 1);
    //     }
    //     return memo[i][j] = 0;
    // }
    int countSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // memset(memo, -1, sizeof(memo));
        int count = 0;
        int n = s.length();
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         if(checkPalindrome(s, i, j)){
        //             count++;
        //         }
        //     }
        // }
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        for(int length = 1; length <= n; length++){
            for(int i = 0; i + length - 1 < n; i++){
                int j = i + length - 1;
                if(i == j){
                    dp[i][j] = true;
                }
                else if(i + 1 == j){
                    if(s[i] == s[j]){
                        dp[i][j] = true;
                    }
                }else{
                    if(s[i] == s[j] && dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                }
                if(dp[i][j] == true){
                    count++;
                }
            }
        }
        return count;
    }
};

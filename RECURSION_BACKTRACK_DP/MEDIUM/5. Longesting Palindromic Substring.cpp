class Solution {
public:
    // int memo[1001][1001];
    // int checkPalindrome(string& s, int i, int j){
    //     if(i >= j){
    //         return 1;
    //     }
    //     if(memo[i][j] != -1){
    //         return memo[i][j];
    //     }
    //     if(s[i] == s[j]){
    //         return memo[i][j] = checkPalindrome(s, i+1, j-1);
    //     }
    //     return memo[i][j] = 0;
    // }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // memset(memo, -1, sizeof(memo));
        int n = s.length();
        int maxLength = INT_MIN;
        int startingIndex = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));
        // All strings of length one are palindrome
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            maxLength = 1;
        }
        for(int length = 2; length <= n; length++){
            for(int i = 0; i + length - 1 < n; i++){
                int j = i + length - 1;
                if(s[i] == s[j] && length == 2){
                    dp[i][j] = true;
                    maxLength = 2;
                    startingIndex = i;
                }else if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    if(j - i + 1 > maxLength){
                        maxLength = j - i + 1;
                        startingIndex = i;
                    }
                }else{
                    dp[i][j] = false;
                }
            }
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = i; j < n; j++){
        //         if(checkPalindrome(s,i,j)){
        //             if(j - i + 1 > maxLen){
        //                 maxLen = j - i + 1;
        //                 startingIndex = i;
        //             }
        //         }
        //     }
        // }
        return s.substr(startingIndex, maxLength);
    }
};

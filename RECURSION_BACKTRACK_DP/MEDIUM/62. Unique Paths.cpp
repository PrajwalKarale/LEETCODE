/*
    Logic:
        1. Recursion and Memoization
            a. From each step we have two options either we go down or go right.
        2. Bottom Up
            a. Our state definition should be dp[i][j] = is the total number of paths to reach (i,j) from (0,0)
            b. dp[0][0] = 0 since total number of unique paths required will be 0 to reach (0,0)
            c. dp[i][j] = dp[i-1][j] + dp[i][j-1]
    Time Complexity:
        1. Recursion and Memoization
            a. recursion -> T.C -> O(2^d) where d is the depth of the recursive tree d = m+n
            b. memoization -> T.C -> O(m*n) since we are visiting every state of the array.
        2. Bottom Up
            a. T.C -> O(m*n)
    Space Complexity:
        1. Recursion and Memoization
            a. In recursion we are using system stack space which would be the height of the recursive tree.
        2. Bottom Up
            a. S.C -> O(m*n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int solveMemo(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        } 
        int down = solveMemo(i+1, j, m, n, dp);
        int right = solveMemo(i, j+1, m, n, dp);
        return dp[i][j] = (down + right);       
    }
    int solve(int i, int j, int m, int n){
        if(i == m - 1 && j == n - 1){
            return 1;
        }
        if(i < 0 || i >= m || j < 0 || j >= n){
            return 0;
        }
        int down = solve(i+1, j, m, n);
        int right = solve(i, j+1, m, n);
        return down + right;
    }
    int tabulation(int m, int n){
        vector<vector<int>>dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i < m; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
    int recursion(int m, int n){
        return solve(0,0,m,n);
    }
    int memoization(int m, int n){
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solveMemo(0,0,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        // return recursion(m, n);
        // return memoization(m,n);
        return tabulation(m,n);
    }
};

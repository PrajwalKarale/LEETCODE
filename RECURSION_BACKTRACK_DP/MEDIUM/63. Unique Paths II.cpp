/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */
/*
    Logic:
        1. Tabulation
            a. State Definition: dp[i][j] = number of ways to reach (i,j) from (0,0)
            b. grid[i][j] == 1 which means obstacle is present so dp[i][j] = 0
    Time Complexity:
        1. T.C -> O(rows * columns);
    Space Complexity:
        2. S.C -> O(rows * columns);
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int rows, int columns, int i, int j){
        if(i == rows - 1 && j == columns - 1){
            return 1;
        }
        if(i < 0 || i >= rows || j < 0 || j >= columns || obstacleGrid[i][j] == 1){
            return 0;
        }
        int right = solve(obstacleGrid, rows, columns, i, j + 1);
        int down = solve(obstacleGrid, rows, columns, i + 1, j);
        return (right + down);
    }
    int recursion(vector<vector<int>>& obstacleGrid){
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        return solve(obstacleGrid, rows, columns, 0, 0);
    }
    int memoize(vector<vector<int>>& obstacleGrid, int rows, int columns, int i, int j, vector<vector<int>>&dp){
        if(i == rows - 1 && j == columns - 1 && obstacleGrid[i][j] != 1){
            return 1;
        }
        if(i < 0 || i >= rows || j < 0 || j >= columns || obstacleGrid[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int right = memoize(obstacleGrid, rows, columns, i, j + 1, dp);
        int down = memoize(obstacleGrid, rows, columns, i + 1, j, dp);
        return dp[i][j] = (right + down);
    }
    int memoization(vector<vector<int>>& obstacleGrid){
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        vector<vector<int>>dp(rows, vector<int>(columns, -1));
        return memoize(obstacleGrid, rows, columns, 0, 0, dp);
    }
    int tabulation(vector<vector<int>>&obstacleGrid){
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        vector<vector<int>>dp(rows, vector<int>(columns, 0));
        for(int col = 0; col < columns; col++){
            if(obstacleGrid[0][col] == 1){
                dp[0][col] = 0;
            }else if(col >= 1 && obstacleGrid[0][col - 1] == 1){
                dp[0][col] = 0;
                obstacleGrid[0][col] = 1;
            }else{
                dp[0][col] = 1;
            }
        }
        for(int row = 0; row < rows; row++){
            if(obstacleGrid[row][0] == 1){
                dp[row][0] = 0;
            }else if(row > 0 && obstacleGrid[row - 1][0] == 1){
                dp[row][0] = 0;
                obstacleGrid[row][0] = 1;
            }else{
                dp[row][0] = 1;
            }
        }
        for(int row = 1; row < rows; row++){
            for(int col = 1; col < columns; col++){
                if(obstacleGrid[row][col] == 1){
                    dp[row][col] = 0;
                }else{
                    dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
                }
            }
        }
        return dp[rows - 1][columns - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // return recursion(obstacleGrid);
        // return memoization(obstacleGrid);
        return tabulation(obstacleGrid);
    }
};

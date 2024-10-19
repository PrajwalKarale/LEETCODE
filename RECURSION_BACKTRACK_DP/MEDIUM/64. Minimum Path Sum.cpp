/*
  Time complexity:
    1. We are travelling each and every cell in the grid
    2. T.C -> O(m *n)
  Space Complexity:
    1. We have created a dp array of m*n cells
    2. S.C -> O(m*n)
*/
class Solution {
public:
    int solveByRecursionMemoization(vector<vector<int>>& grid, int rowI, int columnI, int rows, int columns, vector<vector<int>>& memo) {
        // Base case: if indices are out of bounds
        if (rowI >= rows || columnI >= columns) {
            return INT_MAX;
        }
        // Base case: reached the bottom-right cell
        if (rowI == rows - 1 && columnI == columns - 1) {
            return grid[rowI][columnI];
        }
        // Check memoization table
        if (memo[rowI][columnI] != -1) {
            return memo[rowI][columnI];
        }
        // Recursively compute the minimum path sum for right and down moves
        int right = solveByRecursionMemoization(grid, rowI, columnI + 1, rows, columns, memo);
        int down = solveByRecursionMemoization(grid, rowI + 1, columnI, rows, columns, memo);
        // Calculate current cell's minimum path sum
        int minSum = grid[rowI][columnI] + min(right, down);
        // Store in memoization table
        memo[rowI][columnI] = minSum;
        return minSum;
    }
    int solveByTabulation(vector<vector<int>>&grid){
        int rows = grid.size();
        int columns = grid[0].size();
        vector<vector<int>>dp(rows, vector<int>(columns, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < rows; i++){
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }
        for(int i = 1; i < columns; i++){
            dp[0][i] = grid[0][i] + dp[0][i - 1]; 
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                dp[i][j] = grid[i][j] + min(dp[i][j - 1], dp[i-1][j]);
            }
        }
        return dp[rows - 1][columns - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        // Initialize memoization table with -1
        vector<vector<int>> memo(rows, vector<int>(columns, -1));
        // return solveByRecursionMemoization(grid, 0, 0, rows, columns, memo);
        return solveByTabulation(grid);
    }
};

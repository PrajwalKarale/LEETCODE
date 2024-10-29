/*
    Time Complexity:
        1. Since we are visiting each and every cell of the grid
        2. T.C -> O(rows * columns)
    Space Complexity:
        1. We have created a dp array
        2. S.C -> O(rows * columns)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int>directions = {-1, 0, 1};
    int solve(vector<vector<int>>&grid, int i, int j, int rows, int columns, vector<vector<int>>&dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int moves = 0;
        for(int &direction: directions){
            int newI = i + direction;
            int newJ = j + 1;
            if(newI >= 0 && newI < rows && newJ >= 0 && newJ < columns && grid[newI][newJ] > grid[i][j]){
                moves = max(moves, 1 + solve(grid, newI, newJ, rows, columns, dp));
            }
        }
        return dp[i][j] = moves;
    }
    int solveUsingRecursionMemoization(vector<vector<int>>&grid){
        int rows = grid.size();
        int columns = grid[0].size();
        int result = INT_MIN;
        vector<vector<int>>dp(rows, vector<int>(columns, -1));
        for(int i = 0; i < rows; i++){
            int temp = solve(grid, i, 0, rows, columns, dp);
            result = max(result, temp);
        }
        return result;
    }
    int maxMoves(vector<vector<int>>& grid) {
        return solveUsingRecursionMemoization(grid);
    }
};

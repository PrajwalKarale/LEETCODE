static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();

class Solution {
public:
    int n;
    int helper(int row, int column, vector<vector<int>>grid){
        //Whenever last row is encountered at that time the recursion should be stopped
        if(row == n - 1){
            return grid[row][column];
        }
        int ans = INT_MAX;
        for(int nextColumn = 0; nextColumn < n; nextColumn++){
            if(nextColumn != column){
                ans = min(ans, helper(row + 1, nextColumn, grid));
            }
        }
        return ans + grid[row][column];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int result = INT_MAX;
        for(int column = 0; column < n; column++){
            result = min(result, helper(0, column, grid));
        }
        return result;
    }
};

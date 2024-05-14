// T.C:
//     For loop -> O(row * column)
//     DFS -> Since from each cell we can go in 4 possible directions so 4^(m*n) if all the cell has gold
//     O(m*n * 4^(m*n))
// S.C: Depth of Recursion Tree

class Solution {
public:
    vector<vector<int>>directions = {{-1,0}, {1,0}, {0, 1}, {0,-1}};
    int dfs(vector<vector<int>> &grid, int i, int j, int row, int column){
        if(i >= row || i < 0 || j >= column || j < 0 || grid[i][j] == 0){
            return 0;
        }
        // Since it will be useful during backtracking;
        int ogValue = grid[i][j];
        grid[i][j] = 0;
        int maxGold = 0;
        for(vector<int> &dir: directions){
            int newX = i + dir[0];
            int newY = j + dir[1];

            maxGold = max(maxGold, dfs(grid, newX, newY, row, column));
        }

        grid[i][j] = ogValue;
        return ogValue + maxGold;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();
        int maximumGold = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(grid[i][j] != 0){
                    maximumGold = max(maximumGold, dfs(grid, i, j, row, column));
                }
            }
        }
        return maximumGold;
    }
};

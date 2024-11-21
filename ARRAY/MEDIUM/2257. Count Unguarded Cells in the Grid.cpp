/*
    Time Complexity:
        1. We are visiting each and every cells of grid at least once
        2. T.C -> O(m * n)
    Space Complexity:
        1. Since we are creating a grid of m rows and n columns
        2. S.C -> O(m * n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

class Solution {
public:
    void markGuarded(int row, int column, vector<vector<int>>&grid){
        for(int i = row - 1; i >= 0; i--){
            if(grid[i][column] == 2 || grid[i][column] == 3){
                break;
            }
            grid[i][column] = 1;
        }
        for(int i = row + 1; i < grid.size(); i++){
            if(grid[i][column] == 2 || grid[i][column] == 3){
                break;
            }
            grid[i][column] = 1;
        }
        for(int j = column - 1; j >= 0; j--){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1;
        }
        for(int j = column + 1; j < grid[0].size(); j++){
            if(grid[row][j] == 2 || grid[row][j] == 3){
                break;
            }
            grid[row][j] = 1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n, 0));
        int unguarded = 0;
        for(vector<int>& guard: guards){
            int i = guard[0];
            int j = guard[1];
            // Mark Guard as 2
            grid[i][j] = 2;
        }
        for(vector<int> &wall: walls){
            int i = wall[0];
            int j = wall[1];
            // Mark 3 for wall
            grid[i][j] = 3;
        }
        for(vector<int>&guard: guards){
            int i = guard[0];
            int j = guard[1];
            markGuarded(i, j, grid);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    unguarded += 1;
                }
            }
        }
        return unguarded;
    }
};

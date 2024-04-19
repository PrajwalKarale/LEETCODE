auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return 'c';
}();

class Solution {
public:
    int row;
    int column;
    void dfs(vector<vector<char>>& grid, int i, int j){
        if((i < 0 || i >= row) || (j < 0 || j >= column) || grid[i][j] != '1'){
            return ;
        }
        grid[i][j] = '$';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j - 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        column = grid[0].size();
        int numberOfIslands = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
};

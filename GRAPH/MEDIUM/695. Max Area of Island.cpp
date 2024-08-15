/*
1. DFS APPROACH
*/
class Solution {
public:
    int dfs(vector<vector<int>>&grid, int rows, int columns, int i, int j, int &a){
        if(i >= 0 && i < rows && j >= 0 && j < columns && grid[i][j] == 1){
            a++;
            grid[i][j] = '$';
            dfs(grid, rows, columns, i - 1, j, a);
            dfs(grid, rows, columns, i + 1, j, a);
            dfs(grid, rows, columns, i, j - 1, a);
            dfs(grid, rows, columns, i, j + 1, a);
        }
        return a;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int rows = grid.size();
        int columns = grid[0].size();
        int maxArea = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    int a = dfs(grid, rows, columns, i, j, area);
                    cout << i << " " << j << " " << area << endl;
                    maxArea = max(a, maxArea);
                }
            }
        }
        return maxArea;
    }
};

/*
2. BFS APPROACH
*/

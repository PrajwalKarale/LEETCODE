/*
    Logic: Instead of finding treasure chest from land. Let us find land from treasure chest
*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
        int rows = grid.size();
        int columns = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < columns; ++j){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            int currRow = q.front().first;
            int currColumn = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int r = currRow + dirs[i][0];
                int c = currColumn + dirs[i][1];

                if (r < 0 || r >= rows || c < 0 ||
                    c >= columns || grid[r][c] != INT_MAX) {
                    continue;
                }

                grid[r][c] = grid[currRow][currColumn] + 1;
                q.push({r, c});
            }
        }
    }
};

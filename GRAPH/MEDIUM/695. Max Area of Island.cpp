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
typedef pair<int,int>p;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int maxArea = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 1){
                    queue<p>q;
                    q.push({i, j});
                    int area = 1;
                    // In order to mark visited
                    grid[i][j] = 0;
                    while(!q.empty()){
                        p point = q.front();
                        q.pop();
                        for(int i = 0; i < 4; i++){
                            int newI = point.first + dx[i];
                            int newJ = point.second + dy[i];
                            if(newI >= 0 && newI < rows && newJ >= 0 && newJ < columns && grid[newI][newJ] == 1){
                                area++;
                                grid[newI][newJ] = 0;
                                q.push({newI, newJ});
                            }
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};

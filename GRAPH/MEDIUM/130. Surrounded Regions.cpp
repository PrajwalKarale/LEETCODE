/*
    Time Complexity:
        1. The worst case is at all the cells in board will be visited by the BFS
        2. T.C -> O(rows * columns)
    Space Complexity:
        1. dx and dy are constant spaces
        2. queue in worst case shall contain all the points
        3. S.C -> O(rows * columns)
*/
typedef pair<int,int>p;
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>>visited(rows, vector<int>(columns, 0));
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};
        queue<p>q;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                // Checking for boundary condition
                if(i == 0 || i == rows - 1 || j == 0 || j == columns - 1){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
        }
        while(!q.empty()){
            p point = q.front();
            int i = point.first;
            int j = point.second;
            visited[i][j] = 1;
            q.pop();
            for(int it = 0; it < 4; it++){
                int newI = i + dx[it];
                int newJ = j + dy[it];
                if(newI >= 0 && newI < rows && newJ >= 0 && newJ < columns && visited[newI][newJ] == 0 && board[newI][newJ] == 'O'){
                    q.push({newI, newJ});
                    visited[newI][newJ] == 1;
                }
            }
        }
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(visited[i][j] == 0 && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};

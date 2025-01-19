/*
    Logic:
        1. We will use the concept of multisource BFS. This will be parallel BFS implementation
    Time Complexity:
        1. From equation 1 and 2 T.C -> O(rows * columns)
    Space Complexity:
        1. From equation 1 and 2 we get S.C -> O(rows*columns) + O(4)
        2. S.C -> O(rows*columns)
*/
typedef pair<int,int>pii;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOranges = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        //S.C -> O(rows * columns) -> 1
        queue<pii>q;
        int minutes = 0;
        // S.C -> O(4) -> 2
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        // T.C -> O(rows*columns) -> 1
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    freshOranges += 1;
                }
            }
        }
        if(freshOranges == 0){
            return 0;
        }
        //T.C -> O(rows*columns) -> 2
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                pii current = q.front();
                q.pop();
                int i = current.first;
                int j = current.second;
                for(int k = 0; k < 4; k++){
                    int newI = i + dx[k];
                    int newJ = j + dy[k];
                    if(newI >= 0 && newI < rows && newJ >= 0 && newJ < columns && grid[newI][newJ] == 1){
                        // marking it as rotten
                        grid[newI][newJ] = 2;
                        q.push({newI, newJ});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }
        if(freshOranges == 0){
            return minutes - 1;
        }
        return -1;
    }
};


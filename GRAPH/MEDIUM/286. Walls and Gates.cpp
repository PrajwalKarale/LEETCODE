/*
Time Complexity
1. Since we are visiting each and every cell of the matrix it will be O(rows*columns)

Space Complexity:
1. We are using queue data structures so it will be O(rows*columns)
*/
typedef pair<int,int>p;
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<int>dx = {1, -1, 0, 0};
        vector<int>dy = {0, 0, 1, -1};
        int rows = rooms.size();
        queue<p>q;
        int columns = rooms[0].size();
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < columns; j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            p point = q.front();
            int i = point.first;
            int j = point.second;
            q.pop();
            for(int it = 0; it < 4; it++){
                int newI = i + dx[it];
                int newJ = j + dy[it];
                if(newI < 0 || newI >= rows || newJ < 0 || newJ >= columns || rooms[newI][newJ] <= rooms[i][j] + 1){
                    continue;
                }
                rooms[newI][newJ] = rooms[i][j] + 1;
                q.push({newI, newJ});
            }
        }
    }
};

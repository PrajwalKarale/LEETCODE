typedef pair<int,int>p;
class Solution {
public:
    vector<int>dx = {1, -1, 0, 0};
    vector<int>dy = {0, 0, 1, -1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int row = maze.size();
        int col = maze[0].size();
        queue<p>q;
        q.push({entrance[0], entrance[1]});
        int steps = 0;
        while(!q.empty()){
            int qSize = q.size();
            while(qSize--){
                p point = q.front();
                q.pop();
                int i = point.first;
                int j = point.second;
                // Condition for a boundary point
                if(
                    point != make_pair(entrance[0], entrance[1]) &&
                    (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                ){
                    return steps;
                }
                for(int it = 0; it < 4; it++){
                    int newI = i + dx[it];
                    int newJ = j + dy[it];
                    if(newI >= 0 && newI < row && newJ >= 0 && newJ < col && maze[newI][newJ] != '+'){
                        q.push({newI, newJ});
                        maze[newI][newJ] = '+';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};

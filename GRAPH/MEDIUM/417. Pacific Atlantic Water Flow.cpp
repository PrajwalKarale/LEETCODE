/*
Time complexity
    1. The main factor is the BFS performed on the matrix. The worst case is the it has to visit each and every cell in the heights matrix.
    2. T.C -> O(rows * columns)

Space Complexity
    1. 2 Queues, 3 Set. Worst case they have to accumulate all the cells of the matrix
    2. S.C -> O(rows * columns)
*/
typedef pair<int,int> p;
class Solution {
public:
    set<p> getCoordinates(queue<p> &q, set<p> &visited, vector<int> &dx, vector<int> &dy, int rows, int columns, vector<vector<int>> &heights){
        set<p>result;
        while(!q.empty()){
            p point = q.front();
            result.insert(point);
            int i = point.first;
            int j = point.second;
            q.pop();
            for(int it = 0; it < 4; it++){
                int newI = i + dx[it];
                int newJ = j + dy[it];
                p newPoint = make_pair(newI, newJ);
                if(
                    newI >= 0 &&
                    newI < rows &&
                    newJ >= 0 &&
                    newJ < columns &&
                    visited.find(newPoint) == visited.end() &&
                    heights[newI][newJ] >= heights[i][j]
                ){
                    q.push(newPoint);
                    visited.insert(newPoint);
                }
            }
        }
        return result;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        vector<vector<int>>result;
        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        int rows = heights.size();
        int columns = heights[0].size();
        if(rows == 1){
            for(int j = 0; j < columns; j++){
                result.push_back({0, j});
            }
            return result;
        }
        if(heights.size() == 1){
            return {{0,0}};
        }

        queue<p>atlanticQueue;
        queue<p>pacificQueue;
        set<p>visitedAtlantic;
        set<p>visitedPacific;

        for(int i = 0; i < rows; i++){
            p point = make_pair(i,0);
            pacificQueue.push(point);
            visitedPacific.insert(point);
        }
        for(int j = 1; j < columns; j++){
            p point = make_pair(0, j);
            pacificQueue.push(point);
            visitedPacific.insert(point);
        }
        for(int i = 0; i < rows; i++){
            p point = make_pair(i, columns - 1);
            atlanticQueue.push(point);
            visitedAtlantic.insert(point);
        }
        for(int j = 0; j < columns - 1; j++){
            p point = make_pair(rows - 1, j);
            atlanticQueue.push(point);
            visitedAtlantic.insert(point);
        }

        set<p> coordinatesAtlantic = getCoordinates(atlanticQueue, visitedAtlantic, dx, dy, rows, columns, heights);
        set<p> coordinatesPacific = getCoordinates(pacificQueue, visitedPacific, dx, dy, rows, columns, heights);

        set<p> intersectionCoordinates;
        set_intersection(
            coordinatesPacific.begin(), coordinatesPacific.end(),
            coordinatesAtlantic.begin(), coordinatesAtlantic.end(),
            inserter(intersectionCoordinates, intersectionCoordinates.begin())
        );
        for(auto &point: intersectionCoordinates){
            result.push_back({point.first, point.second});
        }
        return result;
    }
};

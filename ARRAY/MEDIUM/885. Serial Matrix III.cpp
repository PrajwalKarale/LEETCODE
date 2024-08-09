/*
S.C -> O(1) since no extra space is used
T.C -> O(max(rows, cols) ^ 2) since we are visiting extra cells out of the border
*/
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<vector<int>>result;
        vector<vector<int>>directions = {
            {0,1}, //E
            {1,0}, //S
            {0,-1},//W
            {-1,0} //N
        };
        int dir = 0; // Initially it will be moving in east
        int steps = 0; // Steps taken in dir direction
        result.push_back({rStart, cStart});
        while(result.size() < rows*cols){
            if(dir == 0 || dir == 2){
                steps++;
            }
            for(int count = 0; count < steps; count++){
                rStart  = rStart + directions[dir][0];
                cStart = cStart + directions[dir][1];
                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};

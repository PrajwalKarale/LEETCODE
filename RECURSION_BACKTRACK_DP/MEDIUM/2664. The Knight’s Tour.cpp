auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

class Solution {
public:
    vector<int>dx = {1, 1, -1, -1, -2, -2, 2, 2};
    vector<int>dy = {-2, 2, -2, 2, -1, 1, -1, 1};
    bool dfs(int m, int n, int r, int c, int moveNumber, vector<vector<int>>&result){
        if(moveNumber >= m * n){
            return true;
        }
        if(r < 0 || r >= m || c < 0 || c >= n || result[r][c] >= 0){
            return false;
        }
        result[r][c] = moveNumber;
        for(int i = 0; i < 8; i++){
            if(dfs(m, n, r + dx[i], c + dy[i], moveNumber + 1, result)){
                return true;
            }
        }
        result[r][c] = -1;
        return false;
    }
    vector<vector<int>> tourOfKnight(int m, int n, int r, int c) {
        vector<vector<int>>result(m, vector<int>(n, -1));
        dfs(m, n, r, c, 0, result);
        return result;
    }
};

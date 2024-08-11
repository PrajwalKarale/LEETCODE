/*
T.C -> O(n^2)
S.C -> O(9n^2)
*/
class Solution {
public:
    void dfs(vector<vector<int>>&sm, int i, int j){
        if(i < 0 || i >= sm.size() || j < 0 || j >= sm[0].size() || sm[i][j] == 1){
            return;
        }
        sm[i][j] = 1;
        dfs(sm, i + 1, j);
        dfs(sm, i - 1, j);
        dfs(sm, i, j + 1);
        dfs(sm, i, j - 1);
    }
    int regionsBySlashes(vector<string>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int rows = grid.size();
        int col = grid[0].size();
        vector<vector<int>>sm(rows*3, vector<int>(col*3, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == '/'){
                    sm[i*3 + 0][j*3 + 2] = 1;
                    sm[i*3 + 1][j*3 + 1] = 1;
                    sm[i*3 + 2][j*3 + 0] = 1;
                }else if(grid[i][j] == '\\'){
                    sm[i*3 + 0][j*3 + 0] = 1;
                    sm[i*3 + 1][j*3 + 1] = 1;
                    sm[i*3 + 2][j*3 + 2] = 1;
                }
            }
        }
        int regions = 0;
        for(int i = 0; i < sm.size(); i++){
            for(int j = 0; j < sm[0].size(); j++){
                if(sm[i][j] == 0){
                    dfs(sm, i, j);
                    regions++;
                }
            }
        }
        return regions;
    }
};

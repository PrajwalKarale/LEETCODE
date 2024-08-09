class Solution {
public:
    bool isMagicalGrid(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> st;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num)) {
                    return false;
                } else {
                    st.insert(num);
                }
            }
        }
        //check Sum - Rows and columns
        int SUM = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i = 0; i < 3; i++) {
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != SUM) {
                return false;
            }

            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != SUM) {
                return false;
            }
        }


        //diaornal and anti-diagonal
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != SUM) {
            return false;
        }

        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != SUM) {
            return false;
        }
        

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i <= row-3; i++){
            for(int j = 0; j <= col - 3; j++){
                if(isMagicalGrid(grid, i, j)){
                    count++;
                }
            }
        }
        return count;
    }
};

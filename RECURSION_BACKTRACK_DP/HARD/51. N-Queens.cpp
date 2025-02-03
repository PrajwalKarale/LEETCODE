/*
    Logic:
        1. Simple Back Tracking Approach
    Time Complexity:
        1. T.C -> O(n!)
    Space Complexity:
        1. No auxiliary space is used
        2. System Space is O(n)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool isValid(vector<string>&board, int row, int col, int n){
        // Look forward
        for(int i = row - 1; i >= 0; i--){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solve(vector<string>&board, int n, int row, vector<vector<string>>&result){
        if(row >= n){
            result.push_back(board);
            return;
        }
        for(int column = 0; column < n; column++){
            if(isValid(board, row, column, n)){
                board[row][column] = 'Q';
                solve(board, n, row + 1, result);
                board[row][column] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n , string(n, '.'));
        solve(board, n, 0, result);
        return result;
    }
};
// @lc code=end


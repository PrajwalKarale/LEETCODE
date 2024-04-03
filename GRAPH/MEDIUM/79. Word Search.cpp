#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

auto initialize = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int row;
    int column;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    bool search(vector<vector<char>>& board, int i, int j, int index, string word){
        if(index == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= row || j >= column || board[i][j] == '$'){
            return false;
        }
        if(board[i][j] != word[index]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';
        for(int it = 0; it < 4; it++){
            int n_i = i + dx[it];
            int n_j = j + dy[it];
            if(search(board, n_i, n_j, index + 1, word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        column = board[0].size();
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                if(board[i][j] == word[0] && search(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
};

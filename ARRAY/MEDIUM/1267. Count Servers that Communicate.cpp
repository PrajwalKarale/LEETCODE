/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */
/*
    Logic:
      1. Store the servers present in each row and each column and then calculate.
    Time Complexity:
        1. From TC1 and TC2 we get T.C -> O(rows * columns)
    Space Complexity:
        1. From SC1 and SC2
        2. SC -> O(rows + columns)
*/
// @lc code=start
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        int result = 0;
        //SC1 -> O(rows)
        vector<int>indexRowCount(rows, 0);
        //SC2 -> O(columns)
        vector<int>indexColCount(columns, 0);

        //TC1 -> O(rows * columns)
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < columns; col++){
                if(grid[row][col] == 1){
                    indexColCount[col]++;
                    indexRowCount[row]++;
                }
            }
        }
        //TC2 -> O(rows * columns)
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < columns; col++){
                if(grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1)){
                    result++;
                }
            }
        }
        return result;
    }
};
// @lc code=end


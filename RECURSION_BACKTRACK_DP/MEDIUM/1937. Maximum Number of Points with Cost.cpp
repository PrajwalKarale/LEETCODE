/*
T.C -> O(rows * columns)
*/
typedef long long ll;
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
class Solution {
public:
    long long solveByTabulation(vector<vector<int>> &points, int rows, int columns){
        vector<ll>prev(columns);
        for(int i = 0; i < columns; i++){
            prev[i] = points[0][i];
        }
        for(int row = 1; row < rows; row ++){
            vector<ll>left(columns,0);
            left[0] = prev[0];
            for(int col = 1; col < columns; col++){
                left[col] = max(prev[col], left[col - 1] - 1);
            }
            vector<ll>right(columns,0);
            right[columns - 1] = prev[columns - 1];
            for(int col = columns - 2; col >= 0; col--){
                right[col] = max(prev[col], right[col + 1] - 1);
            }
            vector<ll>current(columns, 0);
            for(int col = 0; col < columns; col++){
                current[col] = points[row][col] + max(left[col], right[col]);
            }
            prev = current;
        }
        return *max_element(begin(prev), end(prev));
    }
    // long long findSum(vector<vector<int>>points, int rows, int columns, int rowIndex, int columnIndex){
    //     if(rowIndex >= rows){
    //         return 0;
    //     }
    //     ll ans = 0;
    //     for(int col = 0; col < columns; col++){
    //         ll sum = points[rowIndex][col] - abs(col - columnIndex) + findSum(points, rows, columns, rowIndex + 1, col);
    //         ans = max(ans, sum);
    //     }
    //     return ans;
    // }
    // long long solveByRecursion(vector<vector<int>>points, int rows, int columns){
    //     ll result = INT_MIN;
    //     for(int col = 0; col < columns; col++){
    //         ll sum = points[0][col] + findSum(points, rows, columns, 1, col);
    //         result = max(result, sum);
    //     }
    //     return result;
    // }
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size();
        int columns = points[0].size();
        // return solveByRecursion(points, rows, columns);
        return solveByTabulation(points, rows, columns);
    }
};

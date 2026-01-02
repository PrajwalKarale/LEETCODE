class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int rowNumber = 0;
        int columnNumber = column - 1;
        while(rowNumber < row && columnNumber >= 0){
            if(matrix[rowNumber][columnNumber] == target){
                return true;
            }
            if(target > matrix[rowNumber][columnNumber]){
                rowNumber++;
            }else{
                columnNumber--;
            }
        }
        return false;
    }
};

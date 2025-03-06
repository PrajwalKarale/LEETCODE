// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
    Logic:
        1. Same logic as Path Sum 1 just we need to create temporary vector.
    Time Complexity:
        1. We are passing vector by value so every time when a function call is done at that time the copy of the vector is created which leads to O(n) time
        & this is happening for n number of nodes since we will be visiting each and every node.
        T.C -> O(n^2)
    Space Complexity:
        1. S.C -> O(n) we are using auxiliary space in form of vector.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    void solve(TreeNode* root, int targetSum, vector<vector<int>>&result, vector<int>temp, int sum){
        if(root == nullptr){
            return;
        }
        temp.push_back(root -> val);
        sum += root -> val;
        if(root -> left == nullptr && root -> right == nullptr){
            if(sum == targetSum){
                result.push_back(temp);
            }
            return;
        }
        solve(root -> left, targetSum, result, temp, sum);
        solve(root -> right, targetSum, result, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>result;
        vector<int>temp;
        int sum = 0;
        solve(root, targetSum, result, temp, sum);
        return result;
    }
};

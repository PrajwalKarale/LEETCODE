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
        1. It is similar to Path Sum. So basically my approach would be I would apply path sum logic to each and every node.
    Time Complexity:
        1. T.C -> O(n^2) where n is thentotal number of node.
        2. Since we are visiting each and every node and calling the helper function.
    Space Complexity:
        1. S.C
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    int ans = 0;
    void helper(TreeNode *root, long long targetSum){
        if(!root){
            return;
        }
        if(targetSum == root -> val){
            ans++;
        }
        targetSum = targetSum - (root -> val);
        helper(root -> left, targetSum);
        helper(root -> right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }
        helper(root, (long long)targetSum);
        pathSum(root -> left, targetSum);
        pathSum(root -> right, targetSum);
        return ans;
    }
};

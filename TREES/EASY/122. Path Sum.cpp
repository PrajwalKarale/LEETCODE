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
    Time complexity:
        1. We are visiting each and every node of the tree.
        2. T.C -> O(n)
    Space complexity:
        1. S.C -> O(n) in the worst case if it is a skewed binary tree
        2. S.C -> O(log(n)) if it is a balanced binary tree. 
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    bool inOrder(TreeNode* root, int sum, int targetSum){
        if(root == nullptr){
            return false;
        }
        sum += root -> val;
        if(!root -> left && !root -> right){
            if(sum == targetSum){
                return true;
            }
            return false;
        }
        bool leftSubTree = inOrder(root -> left, sum, targetSum);
        bool rightSubTree = inOrder(root -> right, sum, targetSum);
        return leftSubTree || rightSubTree;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        int sum = 0;
        bool result = inOrder(root, sum, targetSum);
        return result;
    }
};

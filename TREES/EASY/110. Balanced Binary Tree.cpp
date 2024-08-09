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

T.C -> O(n) -> since we will be visiting each and every node in worst case
S.C -> Stack Space it will be O(n) if it is a skew tree;
 */
class Solution {
public:
    int solve(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftHeight = solve(root -> left);
        int rightHeight = solve(root -> right);
        if(leftHeight == -1 || rightHeight == -1){
            return -1;
        }
        if(abs(leftHeight - rightHeight) > 1){
            return -1;
        }
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root){
            return true;
        }
        return solve(root) != -1;
    }
};

// T.C -> O(n) since each node is visited only once.
// S.C -> O(height of the tree) -> no extra space is used only the system stack space is used.
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
class Solution {
public:
    int solve(TreeNode* root, int &moves){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root -> left, moves);
        int right = solve(root -> right, moves);
        moves += abs(left) + abs(right);
        return left + right + root -> val - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        solve(root, moves);
        return moves;
    }
};

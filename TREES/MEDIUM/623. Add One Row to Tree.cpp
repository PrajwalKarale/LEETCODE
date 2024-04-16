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
    TreeNode* add(TreeNode *root,int val, int depth, int currentDepth){
        if(!root){
            return NULL;
        }
        if(currentDepth == depth - 1){
            TreeNode *tempLeft = root -> left;
            TreeNode *tempRight = root -> right;

            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);

            root -> left -> left = tempLeft;
            root -> right -> right = tempRight;

            return root;
        }
        root->left = add(root -> left, val, depth, currentDepth + 1);
        root -> right = add(root -> right, val, depth, currentDepth + 1);

        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot -> left = root;
            return newRoot;
        }
        int currentDepth = 1;

        return add(root, val, depth, currentDepth);
    }
};

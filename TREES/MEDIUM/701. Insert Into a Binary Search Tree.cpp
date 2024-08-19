/*
  Time Complexity
  1. T.C -> O(log N) Height Balanced Binary Search Tree
*/
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
#include <chrono>

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode *current = root;
        while(true){
            // Right Subtree
            if(val >= current -> val ){
                if(current -> right != nullptr){
                    current = current -> right;
                }else{
                    current -> right = new TreeNode(val);
                    break;
                }
            }else{
                if(current -> left != nullptr){
                    current = current -> left;
                }else{
                    current -> left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

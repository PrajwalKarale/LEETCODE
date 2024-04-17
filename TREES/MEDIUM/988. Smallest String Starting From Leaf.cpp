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
    string result = "";
    void dfs(TreeNode* root, string current){
        if(!root){
            return;
        }
        // since we have to do leaf to root we have to add at the back of the current string
        current = char(root -> val + 'a') + current;

        //Now when the leaf node is encountered
        if((root -> left == NULL) && (root -> right == NULL)){
            if(result == "" || result > current){
                result = current;
            }
        }
        dfs(root -> left, current);
        dfs(root -> right, current);
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root, "");
        return result;
    }
};

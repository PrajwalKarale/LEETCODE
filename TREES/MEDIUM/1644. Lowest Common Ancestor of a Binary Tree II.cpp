/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isPresent(TreeNode* root, TreeNode *node){
        if(!root){
            return false; 
        }
        if(root -> val == node -> val){
            return true;
        }
        return isPresent(root -> left, node) || isPresent(root -> right, node);
    }
    TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return nullptr;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* leftN = findLCA(root -> left, p, q);
        TreeNode* rightN = findLCA(root -> right, p, q);

        if(leftN != nullptr && rightN != nullptr){
            return root;
        }
        if(leftN != nullptr){
            return leftN;
        }
        return rightN;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        // First let us find the LCA
        auto lca = findLCA(root, p, q);
        // Check for the presence of the nodes
        if(lca == p){
            return isPresent(lca, q) ? lca: nullptr;
        }
        if(lca == q){
            return isPresent(lca, p) ? lca: nullptr;
        }
        return lca;
    }
};

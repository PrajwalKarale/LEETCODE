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
    TreeNode* findLCA(TreeNode* root, unordered_set<TreeNode*> nodeSet){
        if(!root){
            return nullptr;
        }
        if(nodeSet.find(root) != nodeSet.end()){
            return root;
        }
        TreeNode* leftN = findLCA(root -> left, nodeSet);
        TreeNode* rightN = findLCA(root -> right, nodeSet);
        if(leftN != nullptr && rightN != nullptr){
            return root;
        }
        if(leftN){
            return leftN;
        }
        return rightN;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(nodes.size() == 1){
            return nodes[0];
        }
        unordered_set<TreeNode*>nodeSet(nodes.begin(), nodes.end());
        auto result = findLCA(root, nodeSet);
        return result;
    }
};

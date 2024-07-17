
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

 1. T.c -> O(n)
 2. S.C -> O(n)
 */
class Solution {
public:
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int>&nodesDelete, vector<TreeNode*> &result){
        if(root == NULL){
            return NULL;
        }
        root -> left = deleteNodes(root -> left, nodesDelete, result);
        root -> right = deleteNodes(root -> right, nodesDelete, result);

        if(nodesDelete.find(root -> val) != nodesDelete.end()){
            if(root -> left != nullptr){
                result.push_back(root ->left);
            }
            if(root -> right != nullptr){
                result.push_back(root -> right);
            }
            return nullptr;
        }else{
            return root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<TreeNode*>result;
        unordered_set<int>nodesDelete(to_delete.begin(), to_delete.end());
        deleteNodes(root, nodesDelete, result);
        if(nodesDelete.find(root -> val) == nodesDelete.end()){
            result.push_back(root);
        }
        return result;
    }
};

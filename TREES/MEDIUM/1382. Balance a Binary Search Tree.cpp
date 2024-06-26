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
    vector<int>inOrder;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        solve(root -> left);
        inOrder.push_back(root -> val);
        solve(root -> right);
    }
    TreeNode* makeBST(vector<int>&inOrder, int left, int right){
        if(left > right){
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(inOrder[mid]);
        root -> left = makeBST(inOrder, left, mid - 1);
        root -> right = makeBST(inOrder, mid + 1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root){
            return nullptr;
        }
        solve(root);
        root = makeBST(inOrder, 0, inOrder.size() - 1);
        return root;
    }
};

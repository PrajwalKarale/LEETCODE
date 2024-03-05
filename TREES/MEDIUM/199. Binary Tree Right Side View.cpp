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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        if(!root){
            return {};
        }
        vector<vector<int>>levelOrder;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int qSize = q.size();
            vector<int> temp;
            while(qSize--){
                TreeNode *node = q.front();
                q.pop();
                temp.push_back(node -> val);
                if(node -> left != NULL){
                    q.push(node -> left);
                }
                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }
            levelOrder.push_back(temp);
        }
        for(vector<int> &vect: levelOrder){
            result.push_back(vect[vect.size() - 1]);
        }
        return result;
    }
};

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
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        vector<int>levelSum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            while(n--){
                TreeNode *current = q.front();
                q.pop();
                sum += current -> val;
                if(current -> left){
                    q.push(current -> left);
                }
                if(current -> right){
                    q.push(current -> right);
                }
            }
            levelSum.push_back(sum);
        }
        q.push(root);
        root -> val = 0;
        int i = 1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* current = q.front();
                q.pop();
                int siblingSum = 0;
                if(current -> left){
                    siblingSum += current -> left -> val;
                }
                if(current -> right){
                    siblingSum += current -> right -> val;
                }
                if(current -> left){
                    current -> left -> val = levelSum[i] - siblingSum;
                    q.push(current -> left);
                }
                if(current -> right){
                    current -> right -> val = levelSum[i] - siblingSum;
                    q.push(current -> right);
                }
            }
            i+=1;
        }
        return root;
    }
};

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
/*
    Logic:
        1. Level Order Traversal and the. find max element at each level
    Time Complexity:
        1. We are traversing each and every node of the tree once so
        2. T.C -> O(n)
    Space Complexity:
        1. We are using queue to store all the nodes of the tree
        2. S.C -> O(n) since the total number of nodes are n in a tree
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(!root){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int qSize = q.size();
            int maxElementAtLevel = INT_MIN;
            while(qSize--){
                TreeNode* node = q.front();
                maxElementAtLevel = max(maxElementAtLevel, node -> val);
                q.pop();
                if(node -> left){
                    q.push(node -> left);
                }
                if(node -> right){
                    q.push(node -> right);
                }
            }
            result.push_back(maxElementAtLevel);
        }
        return result;
    }
};

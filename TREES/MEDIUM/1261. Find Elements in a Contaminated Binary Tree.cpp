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
    Time Complexity:
        1. We are traversing each and every node in the tree.
        2. T.C -> O(n) where n is the number of nodes.
    Space Complexity:
        1. We are using queue as an auxiliary data structure and also hashmap.
        2. S.C -> O(n) where n is the number of nodes.
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class FindElements {
public:
    unordered_map<int, bool>mp;
    FindElements(TreeNode* root) {
        root -> val = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            int x = node -> val;
            mp[x] = true;
            q.pop();
            if(node -> left != nullptr){
                node -> left -> val = (2*x) + 1;
                q.push(node -> left);
            }
            if(node -> right != nullptr){
                node -> right -> val = (2*x) + 2;
                q.push(node -> right);
            }
        }
    }
    
    bool find(int target) {
        if(mp.find(target) != mp.end()){
            return true;
        }   
        return false;
    }
};

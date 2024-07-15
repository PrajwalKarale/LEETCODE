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
#pragma GCC optimize("03")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, TreeNode*>tree;
        unordered_set<int>children;

        for(vector<int>& description: descriptions){
            int parent = description[0];
            int child = description[1];
            int isLeft = description[2];

            if(tree.find(parent) == tree.end()){
                tree[parent] = new TreeNode(parent);
            }
            if(tree.find(child) == tree.end()){
                tree[child] = new TreeNode(child);
            }
            if(isLeft == 1){
                tree[parent] -> left = tree[child];
            }else{
                tree[parent] -> right = tree[child];
            }
            children.insert(child);
        }
        for(vector<int>&description: descriptions){
            if(children.find(description[0]) == children.end()){
                return tree[description[0]];
            }
        }
        return nullptr;
    }
};

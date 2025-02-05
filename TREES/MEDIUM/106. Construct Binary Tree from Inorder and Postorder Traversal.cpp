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
        1. Inorder -> Left Root Right
        2. Postorder -> Left Right Root
        3. The root node of the tree will be the last element of `postorder`
    Time Complexity:
        1. T.C -> O(n^2)
    Space Complexity:
        1. S.C -> O(n)
*/
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int postStart, int postEnd){
        if(inorderStart > inorderEnd){
            return nullptr;
        }
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        int i = inorderStart;
        while(i <= inorderEnd){
            if(inorder[i] == rootVal){
                break;
            }
            i++;
        }
        int leftSize = i - inorderStart;
        int rightSize = inorderEnd - i;
        root -> left = solve(inorder, postorder, inorderStart, i - 1, postStart, postStart + leftSize - 1);
        root -> right = solve(inorder, postorder, i + 1, inorderEnd, postEnd - rightSize, postEnd - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int inorderStart = 0;
        int inorderEnd = n - 1;

        int postStart = 0;
        int postEnd = n - 1;

        return solve(inorder, postorder, inorderStart, inorderEnd, postStart, postEnd);
    }
};

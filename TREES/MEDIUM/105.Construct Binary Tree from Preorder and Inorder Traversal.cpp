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
        2. Preorder -> Root Left Right
        3. The first node in the preorder list is the root node. So when we locate the root node in the inorder list the left portion from the root node would be the left subtree of the binary tree.
        4. In 'preorder' every element is root and then we will find the left subtree and right subtree in the 'inorder' list.
        5. We will be using recursion to solve this problem.
    Time Complexity:
        1. For each node in the `preorder` vector we are performing linear search in the `inorder` vector.
        2. Linear search takes O(n) time where n is the length of the vector
        3. T.C -> O(n^2)
    Space Complexity:
        1. No Auxiliary space is used.
        2. S.C -> O(n) system stack space is used.
 */
auto fastIO = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};
class Solution {
public:
    TreeNode* solve(vector<int>&preorder, vector<int>&inorder, int start, int end, int &index){
        if(start > end){
            return nullptr;
        }

        // The value of the root node is found from 'preoder'
        int rootVal = preorder[index];
        //Now we need to locate the root node in 'inorder'
        int i = start;
        while(i <= end){
            if(inorder[i] == rootVal){
                break;
            }
            i++;
        }
        index++;
        TreeNode *root = new TreeNode(rootVal);
        root -> left = solve(preorder, inorder, start, i - 1, index);
        root -> right = solve(preorder, inorder, i + 1, end, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return solve(preorder, inorder, 0, n - 1, index);
    }
};

